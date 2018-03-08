/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:51:30 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/08 14:06:24 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned char	conv_check(unsigned char sv)
{
	if (sv & STOP_D)
	{
		if (sv & HASH_J)
			return (sv = 132);
		else if (((sv & PLUS_LL) || (sv & ZERO_Z)))
			return (sv = 130);
		else if (sv & MINUS_L)
			return (sv = 129);
		else if (sv & DOT_H)
			return (sv = 144);
		else if (sv & MFIELD_HH)
			return (sv = 160);
		else
			return (sv = 128);
	}
	else if (!(sv & STOP_D) && sv & MINUS_L)
		return (sv = MINUS_L);
	return (0);
}

static unsigned char	conv_search(unsigned char sv, t_info **data)
{
	if ((*data)->nbr_l % 2 != 0)
		sv |= MINUS_L;
	else if ((*data)->nbr_l % 2 == 0 && (*data)->nbr_l != 0)
		sv |= PLUS_LL;
	else if (!(sv & MINUS_L) && !(sv & PLUS_LL) && !(sv & ZERO_Z) &&
	(*data)->nbr_h % 2 != 0 && !(sv & HASH_J))
		sv |= DOT_H;
	else if (!(sv & MINUS_L) && !(sv & PLUS_LL) && !(sv & ZERO_Z) &&
	(*data)->nbr_h % 2 == 0 && (*data)->nbr_h != 0 && !(sv & HASH_J))
		sv |= MFIELD_HH;
	return (sv);
}

void					fl_ps(t_info **data, int size, int ch, unsigned char sv)
{
	if (ch == 0)
	{
		(*data)->s_ct[0] == -2 ? sv |= PLUS_LL : sv;
		if (sv & MFIELD_HH && ((*data)->mfield <= size ||
			(*data)->mfield <= (*data)->prec))
			sv &= sv - MFIELD_HH;
		if (sv & DOT_H && (*data)->prec <= size &&
			(*data)->s_ct[1] != -5)
			sv &= sv - DOT_H;
		sv & HASH_J && (*data)->s_ct[1] == -5 ? sv &= sv - HASH_J : sv;
		if ((sv & PLUS_LL || sv & HASH_J) && sv & SPACE)
			sv &= sv - SPACE;
	}
	else if (ch == 1)
	{
		if (sv & MFIELD_HH && (*data)->mfield <= (*data)->prec)
			sv &= sv - MFIELD_HH;
		if (sv & DOT_H && (*data)->prec >= size)
			sv &= sv - DOT_H;
	}
	(*data)->flags = sv;
}

unsigned char			pars_check(t_info **data, char t, unsigned char sv)
{
	(*data)->conv = conv_search((*data)->conv, data);
	if (ft_occ_pos("dDioOxXuUp", t) > -1)
	{
		if ((sv & MINUS_L || sv & DOT_H || !(sv & MFIELD_HH)) && sv & ZERO_Z)
			sv &= sv - ZERO_Z;
		(sv & PLUS_LL || sv & HASH_J) && sv & SPACE ? sv &= sv - SPACE : sv;
		sv & HASH_J && ft_occ_pos("xXoOp", t) == -1 ? sv &= sv - HASH_J : sv;
		(*data)->type == 'p' ? sv |= HASH_J : sv;
		(*data)->type == 'p' ? (*data)->conv = STOP_D + MINUS_L : (*data)->conv;
		if (ft_occ_pos("oOxXuU", t) > -1)
		{
			sv & PLUS_LL ? sv &= sv - PLUS_LL : sv;
			sv & SPACE ? sv &= sv - SPACE : sv;
		}
		(*data)->conv = conv_check((*data)->conv);
	}
	if (ft_occ_pos("cCsS", t) > -1)
	{
		if ((sv & MINUS_L || !(sv & MFIELD_HH)) && sv & ZERO_Z)
			sv &= sv - ZERO_Z;
		sv & HASH_J ? sv &= sv - HASH_J : sv;
		sv & PLUS_LL ? sv &= sv - PLUS_LL : sv;
		(*data)->conv = conv_check((*data)->conv);
	}
	return (sv);
}
