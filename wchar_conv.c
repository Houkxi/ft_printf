/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:13:33 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/13 18:21:08 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		uni_size(wchar_t w)
{
	int		bsize;

	bsize = 0;
	if (w <= 0x7F)
		bsize = 1;
	else if (w <= 0x7FF)
		bsize = 2;
	else if (w <= 0xFFFF)
		bsize = 3;
	else if (w <= 0x10FFFF)
		bsize = 4;
	return (bsize);
}

char	*uni_trans(wchar_t w, int size)
{
	char *tmp;

	if (!(tmp = ft_strnew(size + 1)))
		return (NULL);
	if (w <= 0x7F)
		tmp[0] = w;
	else if (w <= 0x7FF)
	{
		tmp[0] = (w >> 6) + 0xC0;
		tmp[1] = (w & 0x3F) + 0x80;
	}
	else if (w <= 0xFFFF)
	{
		tmp[0] = (w >> 12) + 0xE0;
		tmp[1] = ((w >> 6) & 0x3F) + 0x80;
		tmp[2] = (w & 0x3F) + 0x80;
	}
	else if (w <= 0x10FFFF)
	{
		tmp[0] = (w >> 18) + 0xF0;
		tmp[1] = ((w >> 12) & 0x3F) + 0x80;
		tmp[2] = ((w >> 6) & 0x3F) + 0x80;
		tmp[3] = (w & 0x3F) + 0x80;
	}
	return (tmp);
}

int			wchar_prec(wchar_t *w, t_info *data)
{
	int		x;
	int		fsz;
	int		y;

	x = 0;
	fsz = 0;
	y = 0;
	while (w[x])
	{
		y = uni_size(w[x]);
		fsz += y;
		if (data->type == 'S' && data->flgs & DOT && data->prec < fsz)
		{
			fsz -= y;
			break ;
		}
		x++;
	}
	return (fsz);
}

char		*uni_conv(wchar_t *w, t_info *data, int spe)
{
	int		x;
	int		y;
	int		test;
	int		fsz;
	char	*s;
	char	*tmp;

	x = 0;
	y = 0;
	test = 0;
	if (spe == 0)
		fsz = wchar_prec(w, data);
	else
		fsz = uni_size(w[0]);
	if (!(s = ft_strnew(fsz + 1)))
		return (NULL);
	s[fsz] = '\0';
	while (w[x])
	{
		y = uni_size(w[x]);
		test += y;
		if (fsz < test)
			break ;
		tmp = uni_trans(w[x], y);
		s = ft_strncat(s, tmp, y);
		free(tmp);
		ft_bzero(tmp, y);
		tmp = NULL;
		x++;
	}
	s[fsz] = '\0';
	return (s);
}
