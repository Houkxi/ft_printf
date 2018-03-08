/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_power.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:31:00 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/08 14:17:12 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		new_data(t_info **data)
{
	(*data)->nbr_h = 0;
	(*data)->nbr_l = 0;
	(*data)->prec = 0;
	(*data)->mfield = 0;
	(*data)->flags = 0;
	(*data)->cmd_size = 0;
	(*data)->type = 0;
	(*data)->conv = 0;
	(*data)->s_ct[0] = 0;
	(*data)->s_ct[1] = 0;
	(*data)->s_ct[2] = 0;
}

void		spec_pars(t_info **data, unsigned char sv)
{
	sv & PLUS_LL ? sv &= sv - PLUS_LL : sv;
	sv & SPACE ? sv &= sv - SPACE : sv;
	sv & HASH_J ? sv &= sv - HASH_J : sv;
	sv & DOT_H ? sv &= sv - DOT_H : sv;
	(*data)->flags = sv;
}

/*
			GERER LE CAS OU IL Y A UN ZERO AVEC FLAG PLUS ET PREC 0
			PROBLEM WITH THE + SIGN

			THE PLUS SIGN : + 1 TO SIZE IF TOTAL WIDTH PREC SIZE IF NOT NO +1
			IF MFIELD NON EXISTANT MINUS FLAG SHUT DOWN
*/

char		*flag_4_chrs(t_info *data, char *s, int size)
{
	int		size2;
	int		sign;
	char	*new;

	size2 = size;
	sign = 0;
	new = ft_strdup(s);
	if (data->flags & DOT_H)
	{
		new = flag_prec_chr(data->prec, new, size);
		size = ft_strlen(new);
	}
	if (data->flags & MFIELD_HH)
		flag_mfield_nbr(size, data, new, data->flags);
	else
	{
		buff_rend(new, size, 0);
		free(new);
	}
	return (new);
}

char		*flag_4_nbrs(t_info *data, char *s, int size, unsigned char sv)
{
	int		spz;
	int		sign;
	char	*new;

	spz = 0;
	sign = 0;
	new = ft_strdup(s);
	if (sv & DOT_H)
	{
		new = flag_prec(data->prec, new, size);
		size = ft_strlen(new);
	}
	if (sv & MFIELD_HH)
		flag_mfield_nbr(size, data, new, data->flags);
	else
	{
		flag_sign(data, data->flags, 0);
		buff_rend(new, size, 0);
		free(new);
	}
	return (new);
}

/*
		if mfield < prec || mfield < size
			printf("CHRS : %s\n", s);
			ft_print_bits(data->flags, 8);
			printf("\n");
*/

char		*flag_manager(t_info *data, char *s, int size)
{
	char	*new;

	new = NULL;
	if ((ft_occ_pos("dDixXoOuUp", data->type)) > -1)
	{
		if (s[0] == '0' && data->flags & DOT_H && data->prec == 0 && size == 1)
		{
			data->s_ct[1] = -5;
			s[0] = '\0';
			size = 0;
		}
		fl_ps(&data, size, 0, data->flags);
		new = flag_4_nbrs(data, s, size, data->flags);
	}
	else if ((ft_occ_pos("cCsS", data->type)) > -1)
	{
		fl_ps(&data, size, 1, data->flags);
		new = flag_4_chrs(data, s, size);
	}
	else
	{
		spec_pars(&data, data->flags);
		new = flag_4_chrs(data, s, size);
	}
	return (new);
}
