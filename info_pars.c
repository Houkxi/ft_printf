/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:14:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/23 17:37:55 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
LISTE PRIORITIES :
					- PREC first, prioritie on mfield, if smaller than base no
					effect, except prec 0 on zero
					- MFIELD if <= to Base || PREC --> desactivate, Zero flag in
					accordance
					- ZERO flag, desactivate with, prec, minus, !mfield
					_ PLUS if !mfield (du to <= or just not activated) -->
					take minimum size/ prec || base add +1
					else don't add 1
					- SPACE add +1 with prec || base max size, unless MFIELD
					sufficiant size, overwrites the ZERO flag ONLY FOR POSITIVE
					SIGNED NUMBERS without the + flag
					DESACTIVATE if unsigned type
					- HASH only with types x,X & o,O, desactivate for other types
					- APOS " ' " Separates every thousands
					- MINUS active only with sufficent MFIELD, watchout for
					PLUS or SPACE flag will take priorities for the 1 space in front
					- STAR will exchange first arg as int int the command line
					multiple stars will take multiple args in order
					- POURCENT mfield ok, prec no, minus ok, space no, plus no,
*/
/*
	PUT STOP AT 255 BECAUSE IMPOSSIBLE FOR OTHER FLAGS TO ALL BE active
	USE 128 to activate other stuff
	RECHECKER PARSING, ET le revoir, refaire le buffer pour itoall voir si possible
	Buffer commun pour chaque %
*/

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
		x++;
		if (ft_isdigit(s[x]) == 1)
			x += rec_nbr_count((**data)->prec, 0, 10);
		sv |= DOT_H;
	}
	printf("_%c_\n", s[x]);
	if (s[x] && s[x] == '*')
	{
		(**data)->s_ct[0]++;
		printf("STAR ***%d***\n", (**data)->s_ct[0]);
		if (s[x - 1] == '.')
		{
			printf("PREC STAR %d\n", (**data)->s_ct[0]);
			(**data)->s_ct[2] = (**data)->s_ct[0];
			(**data)->prec = -1;
		}
		else
		{
			(**data)->s_ct[1] = (**data)->s_ct[0];
			(**data)->mfield = -1;
		}
	}
	if (s[x] && s[x] > '0' && s[x] <= '9' && (s[x - 1] != '.' &&
	(s[x - 1] <= '0' || s[x - 1] > '9')))
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
	(*data)->flags & ZERO_Z && ((*data)->flags & DOT_H ||
	(*data)->flags & MINUS_L || !((*data)->flags & MFIELD_HH)) ?
	(*data)->flags &= (*data)->flags - ZERO_Z : (*data)->flags;
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
	char		*type;

	x = 0;
	type = "dDioOxXuUpcCsS %#*0+-.hjzlL$123456789";
	while ((ret = ft_occ_pos(type, s[x])) > 13 && ++x)
	{
		s[x] && s[x] == 'l' ? (*data)->nbr_l += 1 : (*data)->nbr_l;
		s[x] && s[x] == 'h' ? (*data)->nbr_h += 1 : (*data)->nbr_h;
		(*data)->flags = flag_search(s, (*data)->flags, &data, &x);
		(*data)->conv = conv_search(&s[x], (*data)->conv, data, 1);
	}
	(*data)->conv = conv_search(&s[x], (*data)->conv, data, -1);
	if (ret >= 0 && ret <= 8)
		(*data)->conv |= STOP_D;
	if (ret == -1)
		(*data)->flags |= STOP_D;
	return (x);
}

int				data_init(va_list **arg, t_info *data, char *s)
{
	int			ct;
	int			save;

	ct = 1;
	new_data(&data);
	data->cmd_size = type_check(s, &data);
	data->type = s[data->cmd_size];
	ft_print_bits(data->flags, 8);
	printf("\n");
	printf("TEST FOR STARS : %d, %d\nCOUNT STARTS 0 : %d, 1 : %d, 2 : %d\n", data->mfield, data->prec, data->s_ct[0], data->s_ct[1], data->s_ct[2]);
	while (ct <= data->s_ct[0])
	{
		save = va_arg(**arg, int);
		printf("SAVE : %d\n%d\n", save, ct);
		if (ct == data->s_ct[1] && data->mfield == -1)
		{
			data->mfield = save;
			data->flags |= DOT_H;
		}
		if (ct == data->s_ct[2] && data->prec == -1)
		{
			data->prec = save;
			data->flags |= MFIELD_HH;
		}
		ct++;
	}
	printf("TEST FOR STARS END : %d, %d\n", data->mfield, data->prec);
	if (data->flags & STOP_D)
	{
		printf("STOP THIS SHIT !!!\n");
		ft_print_bits(data->flags, 8);
		printf("\n");
		return (-1);
	}
	data->conv = conv_check(data->conv, &data);
	return (0);
}
