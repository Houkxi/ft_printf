/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:02:10 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/19 19:16:21 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_bits(unsigned int octet, int size, char **s)
{
	int				oct;

	oct = octet;
	if (size > -1)
	{
		ft_bits(octet >> 1, size - 1, s);
		s[0][size] = '0' + (oct & 1);
	}
}

char				*wrt_bin_proper(char *tmp, int x, int size)
{
	int				i;
	char			*tmp2;
	int				test;

	if (!(tmp2 = ft_strnew(size)))
		return (NULL);
	i = 0;
	test = size;
	while (tmp[i])
	{
		if (test % 8 == 0 && test != size)
		{
			tmp2[x] = ' ';
			x++;
		}
		tmp2[x] = tmp[i];
		i++;
		x++;
		test--;
	}
	tmp2[x] = '\0';
	return (tmp2);
}

char				*binairy_spec(va_list ****arg, t_info ***data)
{
	char			*tmp;
	char			*tmp2;
	unsigned int	bn;

	if ((**data)->flgs & DOT)
	{
		if (!(tmp = ft_strnew(32)))
			return (NULL);
		ft_bits((unsigned int)(va_arg(****arg, uintmax_t)), 31, &tmp);
	}
	else
		tmp = ft_utoall((unsigned int)(va_arg(****arg, uintmax_t)), 2, 0, 0);
	bn = ft_strlen(tmp);
	tmp2 = wrt_bin_proper(tmp, 0, bn);
	ft_strdel(&tmp);
	return (tmp2);
}
