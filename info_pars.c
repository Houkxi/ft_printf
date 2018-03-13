/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:14:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/13 19:31:16 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				star_spe(char *s, t_info ****data, int x)
{
	(***data)->s_ct[0]++;
	if (s[x - 1] == '.')
	{
		(***data)->s_ct[2] = (***data)->s_ct[0];
		(***data)->prec = -1;
	}
	else
	{
		(***data)->s_ct[1] = (***data)->s_ct[0];
		(***data)->mfield = -1;
	}
}

static	unsigned int	basc(char *s, unsigned int sv, t_info ***data, int *xb)
{
	s[*xb] && s[*xb] == 'l' ? (**data)->nbr_l += 1 : (**data)->nbr_l;
	s[*xb] && s[*xb] == 'h' ? (**data)->nbr_h += 1 : (**data)->nbr_h;
	s[*xb] && s[*xb] == 'j' ? sv |= J : sv;
	s[*xb] && s[*xb] == 'z' ? sv |= Z : sv;
	s[*xb] && s[*xb] == '-' ? sv |= MINUS : sv;
	s[*xb] && s[*xb] == '+' ? sv |= PLUS : sv;
	s[*xb] && s[*xb] == '#' ? sv |= HASH : sv;
	s[*xb] && s[*xb] == ' ' ? sv |= SPACE : sv;
	return (sv);
}

static unsigned int	fcn(char *s, unsigned int sv, t_info ***data, int *xb)
{
	int				x;

	x = *xb;
	s[x] && s[x] == '0' && (s[x - 1] <= '0' || s[x - 1] > '9')
	? sv |= ZERO : sv;
	if (s[x] && s[x + 1] && s[x] == '.')
	{
		(**data)->prec = ft_atoi(&s[x + 1]);
		x++;
		if (ft_isdigit(s[x]) == 1)
			x += rec_nbr_count((**data)->prec, 0, 10);
		sv |= DOT;
	}
	if (s[x] && s[x] == '*')
		star_spe(s, &data, x);
	if (s[x] && s[x] > '0' && s[x] <= '9' && (s[x - 1] != '.' &&
	(s[x - 1] <= '0' || s[x - 1] > '9')))
	{
		(**data)->mfield = ft_atoi(&s[x]);
		x += rec_nbr_count((**data)->mfield, 0, 10);
		sv |= MFIELD;
	}
	*xb = x;
	return (sv);
}

static char				type_check(char *s, t_info **data)
{
	int					x;
	int					ret;
	char				*type;

	x = 0;
	type = "dDioOxXuUpcCsS %#*0+-.hjzlL$123456789q_";
	while ((ret = ft_occ_pos(type, s[x])) > 13 && ++x)
	{
		(*data)->flgs = basc(s, (*data)->flgs, &data, &x);
		(*data)->flgs = fcn(s, (*data)->flgs, &data, &x);
		if (s[x] && x != 0 && s[x] == '%')
		{
			ret = 15;
			break ;
		}
	}
	if (ret >= 0 && ret <= 9)
		(*data)->flgs |= DEC;
	if (ret == -1 || ret == 15)
		(*data)->flgs |= STOP;
	(*data)->type = s[x];
	return (x);
}

void					wildcard_calc(va_list ***arg, t_info **data, int ct)
{
	int					save;
	unsigned int 		sv;

	sv = (*data)->flgs;
	while (ct <= (*data)->s_ct[0])
	{
		save = va_arg(***arg, int);
		if (ct == (*data)->s_ct[1] && (*data)->mfield == -1)
		{
			(*data)->mfield = save;
			sv |= MFIELD;
			save < 0 && sv & MFIELD ? sv |= MINUS : sv;
			save < 0 ? (*data)->mfield *= -1 : (*data)->mfield;
		}
		if (ct == (*data)->s_ct[2] && (*data)->prec == -1)
		{
			(*data)->prec = save;
			(*data)->flgs |= DOT;
			save < 0 && sv & DOT ? sv &= sv - DOT : sv;
			save < 0 ? (*data)->prec = 0 : (*data)->prec;
		}
		ct++;
	}
	(*data)->flgs = sv;
}

int						data_init(va_list **arg, t_info *data, char *s)
{
	int					ct;

	ct = 1;
	new_data(&data);
	data->cmd_size = type_check(s, &data);
	wildcard_calc(&arg, &data, 1);
	/*while (ct <= data->s_ct[0])
	{
		save = va_arg(**arg, int);
		save < 0 ? save = 0 : save;
		if (ct == data->s_ct[1] && data->mfield == -1)
		{
			data->mfield = save;
			data->flgs |= MFIELD;
		}
		if (ct == data->s_ct[2] && data->prec == -1)
		{
			data->prec = save;
			data->flgs |= DOT;
		}
		ct++;
	}*/
	if (data->flgs & STOP)
		return (-1);
	data->flgs = pars_check(&data, data->type, data->flgs);
	/*printf("%c\n", data->type);
	printf("BYTES --> %d\n", data->flgs);
	ft_print_bits_int(data->flgs, 32);
	printf("\n");*/
	return (0);
}
