/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:51:30 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/13 19:44:43 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	conv_check(unsigned int sv)
{
	if (sv & DEC)
	{
		if (sv & J)
			return (sv &= 0xFFFF00FF + J);
		else if ((sv & Z))
			return (sv &= 0xFFFF00FF + Z);
		else if ((sv & LL))
			return (sv &= 0xFFFF00FF + LL);
		else if (sv & L)
			return (sv &= 0xFFFF00FF + L);
		else if (sv & H)
			return (sv &= 0xFFFF00FF + H);
		else if (sv & HH)
			return (sv &= 0xFFFF00FF + HH);
		else
			return (sv &= 0xFFFF00FF);
	}
	else if (!(sv & DEC) && sv & L)
		return (sv = (sv & 0xFFFF00FF) + L);
	return (sv &= 0xFFFF00FF);
}

static unsigned int	conv_search(unsigned int sv, t_info **data)
{
	if ((*data)->nbr_l % 2 != 0)
		sv |= L;
	else if ((*data)->nbr_l % 2 == 0 && (*data)->nbr_l != 0)
		sv |= LL;
	else if (!(sv & L) && !(sv & LL) && !(sv & Z) &&
	(*data)->nbr_h % 2 != 0 && !(sv & J))
		sv |= H;
	else if (!(sv & L) && !(sv & LL) && !(sv & Z) &&
	(*data)->nbr_h % 2 == 0 && (*data)->nbr_h != 0 && !(sv & J))
		sv |= HH;
	return (sv);
}

void					fl_ps(t_info **data, int size, int ch, unsigned int sv)
{
	if (ch == 0)
	{
		(*data)->s_ct[0] == -2 ? sv |= PLUS : sv;
		if (sv & MFIELD && ((*data)->mfield <= size ||
			(*data)->mfield <= (*data)->prec))
			sv &= sv - MFIELD;
		if (sv & DOT && (*data)->prec <= size &&
			(*data)->s_ct[1] != -5)
			sv &= sv - DOT;
		sv & HASH && ((*data)->s_ct[1] == -5 || (*data)->s_ct[2] == -9)  && ft_occ_pos("oO", (*data)->type) == -1 ? sv &= sv - HASH : sv;
		if ((sv & PLUS || sv & HASH) && sv & SPACE)
			sv &= sv - SPACE;
	}
	else if (ch == 1)
	{
		(*data)->s_ct[0] == -15 && sv & SPACE ? sv &= sv - SPACE : sv;
		if (sv & MFIELD && (*data)->s_ct[0] == -15 &&
		((*data)->mfield <= (*data)->prec || (*data)->mfield <= size))
			sv &= sv - MFIELD;
		if ((sv & DOT && (*data)->prec >= size) || (sv & DOT && (*data)->type == 'c'))
			sv &= sv - DOT;
		if (sv & MFIELD && sv & DOT && (*data)->mfield <= (*data)->prec)
			sv &= sv - MFIELD;
	}
	(*data)->flgs = sv;
}

unsigned int			pars_check(t_info **data, char t, unsigned int sv)
{
	/*printf("BYTES\n");
	ft_print_bits_int(sv, 32);
	printf("\n");*/
	sv = conv_search(sv, data);
	/*printf("NEW\n");
	ft_print_bits_int(sv, 32);
	printf("\n");*/
	if (ft_occ_pos("dDioOxXuUp", t) > -1)
	{
		if ((sv & MINUS || sv & DOT || !(sv & MFIELD)) && sv & ZERO)
			sv &= sv - ZERO;
		(sv & PLUS || sv & HASH) && sv & SPACE ? sv &= sv - SPACE : sv;
		sv & HASH && ft_occ_pos("xXoOp", t) == -1 ? sv &= sv - HASH : sv;
		(*data)->type == 'p' ? sv |= HASH : sv;
		(*data)->type == 'p' ? sv = (sv & 0xFFFF00FF) + L : sv;
		if (ft_occ_pos("oOxXuU", t) > -1)
		{
			sv & PLUS ? sv &= sv - PLUS : sv;
			sv & SPACE ? sv &= sv - SPACE : sv;
		}
		sv = conv_check(sv);
	}
	if (ft_occ_pos("cCsS", t) > -1)
	{
		if ((sv & MINUS || !(sv & MFIELD)) && sv & ZERO)
			sv &= sv - ZERO;
		sv & HASH ? sv &= sv - HASH : sv;
		sv & PLUS ? sv &= sv - PLUS : sv;
		sv & SPACE ? sv &= sv - SPACE : sv;
		sv = conv_check(sv);
	}
	/*printf("AGAIN\n");
	ft_print_bits_int(sv, 32);
	printf("\n");*/
	return (sv);
}
