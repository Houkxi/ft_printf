/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:14:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/21 16:16:52 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	flag_search(char *s, unsigned char sv, t_info ***data, int *xb)
{
	int			x;

	x = *xb;
	s[x] && s[x] == '-' ? sv |= MINUS_L : sv;
	s[x] && s[x] == '+' ? sv |= PLUS_LL : sv;
	s[x] && s[x] == '#' ? sv |= HASH_J : sv;
	(s[x] && s[x] == '0' && (s[x - 1] < '0' || s[x - 1] > '9') &&
	!(sv & MINUS_L)) ? sv |= ZERO_Z : sv;
	(s[x] && (sv & MINUS_L) && sv & ZERO_Z) ? sv &= sv - ZERO_Z : sv;
	if (s[x] && s[x + 1] && s[x] == '.')
	{
		(**data)->prec = ft_atoi(&s[x + 1]);
		x += rec_nbr_count((**data)->prec, 0, 10) + 1;
		sv |= DOT_H;
	}
	if (s[x] && s[x] > '0' && s[x] <= '9' && s[x - 1] != '.')
	{
		(**data)->mfield = ft_atoi(&s[x]);
		x += rec_nbr_count((**data)->mfield, 0, 10);
		sv |= MFIELD_HH;
	}
	s[x] && s[x] == ' ' ? sv |= SPACE : sv;
	*xb = x;
	return (sv);
}

unsigned char	conv_search(char *s, unsigned char sv, t_info **data, int ch)
{
	int			x;
	char		pt;

	x = 0;
	if (ch < 0)
	{
		if (s[x] && (*data)->nbr_l % 2 != 0)
			sv |= MINUS_L;
		if (s[x] && (*data)->nbr_l % 2 == 0 && (*data)->nbr_l != 0)
			sv |= PLUS_LL;
		if (s[x] && !(sv & MINUS_L) && !(sv & PLUS_LL) && !(sv & ZERO_Z) &&
		(*data)->nbr_h % 2 != 0 && !(sv & HASH_J))
			sv |= DOT_H;
		if (s[x] && !(sv & MINUS_L) && !(sv & PLUS_LL) && !(sv & ZERO_Z) &&
		(*data)->nbr_h % 2 == 0 && (*data)->nbr_h != 0 && !(sv & HASH_J))
			sv |= MFIELD_HH;
	}
	if (s[x] && s[x] == 'j' && !(sv & PLUS_LL))
		sv |= HASH_J;
	if (s[x] && s[x] == 'z' && !(sv & PLUS_LL) && !(sv & HASH_J))
		sv |= ZERO_Z;
	return (sv);
}

/*
CONDITION in case type is special, some flags are not wanted
(*data)->flags &= 41
*/

unsigned char	conv_check(unsigned char sv, t_info **data)
{
	if ((*data)->type && ((*data)->type == 's' || (*data)->type == 'S' ||
		(*data)->type == 'c' || (*data)->type == 'C'))
		(*data)->flags &= 41;
	if ((sv & STOP_D) && ((sv & PLUS_LL) || (sv & ZERO_Z) || (sv & HASH_J)))
		return (sv = 130);
	else if ((sv & STOP_D) && sv & MINUS_L)
		return (sv = 129);
	if ((sv & PLUS_LL) || (sv & ZERO_Z) || (sv & HASH_J))
		return (sv = PLUS_LL);
	else if (sv & MINUS_L)
		return (sv = MINUS_L);
	else
		return (sv);
}

char			type_check(char *s, t_info **data)
{
	int			x;
	int			ret;
	int			ret2;
	char		*type;

	x = 1;
	type = "dDioOxXuUpcCsS #*0+-.hjzlL$123456789";
	while ((ret = ft_occ_pos(type, s[x])) > 13)
	{
		s[x] && s[x] == 'l' ? (*data)->nbr_l += 1 : (*data)->nbr_l;
		s[x] && s[x] == 'h' ? (*data)->nbr_h += 1 : (*data)->nbr_h;
		(*data)->flags = flag_search(s, (*data)->flags, &data, &x);
		(*data)->conv = conv_search(&s[x], (*data)->conv, data, 1);
		x++;
	}
	(*data)->conv = conv_search(&s[x], (*data)->conv, data, -1);
	if (ret >= 0 && ret <= 8)
		(*data)->conv |= STOP_D;
	if (ret == -1)
		(*data)->flags |= STOP_D;
	return (x);
}

int				data_init(t_info *data, char *s)
{
	new_data(&data);
	data->cmd_size = type_check(s, &data);
	data->type = s[data->cmd_size];
//	ft_print_bits(data->conv, 8);
	//printf("\n");
	if (data->flags & STOP_D)
		return (-1);
	data->conv = conv_check(data->conv, &data);
	return (0);
}
