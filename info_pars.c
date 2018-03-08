/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:14:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/08 13:44:36 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PUT STOP AT 255 BECAUSE IMPOSSIBLE FOR OTHER FLAGS TO ALL BE active
	USE 128 to activate other stuff
	RECHECKER PARSING, ET le revoir, refaire le buffer pour itoall voir si
	possible
	Buffer commun pour chaque %

************!!!!!!!!----- BONUS IDEAS ------!!!!!!!!*************
				-Flag to print a matrix/tab					-
				-Flag to print the bytes of char/ int etc	-
*/

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

static	unsigned char	basc(char *s, unsigned char sv, t_info ***data, int *xb)
{
	s[*xb] && s[*xb] == 'l' ? (**data)->nbr_l += 1 : (**data)->nbr_l;
	s[*xb] && s[*xb] == 'h' ? (**data)->nbr_h += 1 : (**data)->nbr_h;
	s[*xb] && s[*xb] == 'j' ? (**data)->conv |= HASH_J : (**data)->conv;
	s[*xb] && s[*xb] == 'z' ? (**data)->conv |= ZERO_Z : (**data)->conv;
	s[*xb] && s[*xb] == '-' ? sv |= MINUS_L : sv;
	s[*xb] && s[*xb] == '+' ? sv |= PLUS_LL : sv;
	s[*xb] && s[*xb] == '#' ? sv |= HASH_J : sv;
	s[*xb] && s[*xb] == ' ' ? sv |= SPACE : sv;
	return (sv);
}

static unsigned char	fcn(char *s, unsigned char sv, t_info ***data, int *xb)
{
	int			x;

	x = *xb;
	s[x] && s[x] == '0' && (s[x - 1] <= '0' || s[x - 1] > '9')
	? sv |= ZERO_Z : sv;
	if (s[x] && s[x + 1] && s[x] == '.')
	{
		(**data)->prec = ft_atoi(&s[x + 1]);
		x++;
		if (ft_isdigit(s[x]) == 1)
			x += rec_nbr_count((**data)->prec, 0, 10);
		sv |= DOT_H;
	}
	if (s[x] && s[x] == '*')
		star_spe(s, &data, x);
	if (s[x] && s[x] > '0' && s[x] <= '9' && (s[x - 1] != '.' &&
	(s[x - 1] <= '0' || s[x - 1] > '9')))
	{
		(**data)->mfield = ft_atoi(&s[x]);
		x += rec_nbr_count((**data)->mfield, 0, 10);
		sv |= MFIELD_HH;
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
		/*s[x] && s[x] == 'l' ? (*data)->nbr_l += 1 : (*data)->nbr_l;
		s[x] && s[x] == 'h' ? (*data)->nbr_h += 1 : (*data)->nbr_h;
		s[x] && s[x] == 'j' ? (*data)->conv |= HASH_J : (*data)->conv;
		s[x] && s[x] == 'z' ? (*data)->conv |= ZERO_Z : (*data)->conv;
		s[x] && s[x] == '-' ? (*data)->flags |= MINUS_L : (*data)->flags;
		s[x] && s[x] == '+' ? (*data)->flags |= PLUS_LL : (*data)->flags;
		s[x] && s[x] == '#' ? (*data)->flags |= HASH_J : (*data)->flags;
		s[x] && s[x] == ' ' ? (*data)->flags |= SPACE : (*data)->flags;*/
		(*data)->flags = basc(s, (*data)->flags, &data, &x);
		(*data)->flags = fcn(s, (*data)->flags, &data, &x);
		if (s[x] && x != 0 && s[x] == '%')
		{
			ret = 15;
			break;
		}
	}
	//printf("RET : %d, X : %d, S : %c\n", ret, x, s[x]);
	if (ret >= 0 && ret <= 9)
		(*data)->conv |= STOP_D;
	if (ret == -1 || ret == 15)
		(*data)->flags |= STOP_D;
	(*data)->type = s[x];
	return (x);
}

/*
	IF NOT GOOD TYPE, KEEP THE BAD CHAR AND DO THE FLAGS ON IT AS A %s || %c

printf("VERIF CONV & FLAGS\n");
ft_print_bits(data->flags, 8);
printf("\n");
ft_print_bits(data->conv, 8);
printf("\n");*/

int						data_init(va_list **arg, t_info *data, char *s)
{
	int					ct;
	int					save;

	ct = 1;
	//printf("TEST FOR %% _%c_\n", s[0]);
	new_data(&data);
	data->cmd_size = type_check(s, &data);
	while (ct <= data->s_ct[0])
	{
		save = va_arg(**arg, int);
		if (ct == data->s_ct[1] && data->mfield == -1)
		{
			data->mfield = save;
			data->flags |= MFIELD_HH;
		}
		if (ct == data->s_ct[2] && data->prec == -1)
		{
			data->prec = save;
			data->flags |= DOT_H;
		}
		ct++;
	}
	if (data->flags & STOP_D)
	{
		//printf("NOT GOOD\n");
		return (-1);
	}
	data->flags = pars_check(&data, data->type, data->flags);
	return (0);
}
