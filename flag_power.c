/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_power.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:31:00 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/13 19:50:55 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		new_data(t_info **data)
{
	(*data)->nbr_h = 0;
	(*data)->nbr_l = 0;
	(*data)->prec = 0;
	(*data)->mfield = 0;
	(*data)->flgs = 0;
	(*data)->cmd_size = 0;
	(*data)->type = 0;
	(*data)->s_ct[0] = 0;
	(*data)->s_ct[1] = 0;
	(*data)->s_ct[2] = 0;
}

char		*flag_4_chrs(t_info *data, char *s, int size)
{
	int		size2;
	int		sign;
	char	*new;

	size2 = size;
	sign = 0;
	new = ft_strdup(s);
	if (data->flgs & DOT)
	{
		new = flag_prec_chr(data->prec, new, size);
		size = ft_strlen(new);
	}
	if (data->flgs & MFIELD)
	{
		flag_mfield_nbr(size, data, new, data->flgs);
	}
	else
	{
		flag_sign(data, data->flgs, 0);
		buff_rend(new, size, 0);
		free(new);
	}
	return (new);
}

char		*flag_4_nbrs(t_info *data, char *s, int size, unsigned int sv)
{
	int		spz;
	int		sign;
	char	*new;

	spz = 0;
	sign = 0;
	new = ft_strdup(s);
	if (sv & DOT)
	{
		new = flag_prec(data->prec, new, size);
		size = ft_strlen(new);
	}
	if (sv & MFIELD)
		flag_mfield_nbr(size, data, new, data->flgs);
	else
	{
		flag_sign(data, data->flgs, 0);
		buff_rend(new, size, 0);
		free(new);
	}
	return (new);
}

static char	*spec_pars(t_info **data, unsigned int sv, int size, char *s)
{
	sv & PLUS ? sv &= sv - PLUS : sv;
	sv & SPACE ? sv &= sv - SPACE : sv;
	sv & HASH ? sv &= sv - HASH : sv;
	sv & DOT ? sv &= sv - DOT : sv;
	(*data)->flgs = sv;
	return (flag_4_chrs(*data, s, size));
}

char		*flag_manager(t_info *data, char *s, int size)
{
	char	*new;

	new = NULL;
	if ((ft_occ_pos("dDixXoOuUp", data->type)) > -1)
	{
		//printf("_%s_ --> %d, %d\n", s, data->prec, size);
		if (s[0] == '0' && data->flgs & HASH && size == 1 && data->type != 'p')
		{
			//printf("TEST\n");
			if (ft_occ_pos("oO", data->type) > -1)
			{
				s[0] = '\0';
				size = 0;
			}
			data->s_ct[2] = -9;
		}
		if (s[0] == '0' && data->flgs & DOT && data->prec == 0 && size == 1)
		{
			data->s_ct[1] = -5;
			s[0] = '\0';
			size = 0;
		}
		//printf("%d\n", data->s_ct[2]);
		fl_ps(&data, size, 0, data->flgs);

		new = flag_4_nbrs(data, s, size, data->flgs);
	}
	else if ((ft_occ_pos("cCsS", data->type)) > -1)
	{
		if (data->flgs & DOT && data->s_ct[0] == -15 && data->prec < size)
			data->prec = size + 1;
		//	data->flgs &= data->flgs - DOT;
		fl_ps(&data, size, 1, data->flgs);
		new = flag_4_chrs(data, s, size);
	}
	else
		new = spec_pars(&data, data->flgs, size, s);
	return (new);
}
