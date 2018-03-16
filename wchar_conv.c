/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:13:33 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/16 19:01:30 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				uni_size(wchar_t w)
{
	int			bsize;

	bsize = 0;
	if (w <= 0x7F)
		bsize = 1;
	else if (w > 0x7F && w <= 0x7FF)
		bsize = 2;
	else if (w > 0x7FF && w <= 0xFFFF)
		bsize = 3;
	else if (w > 0xFFFF && w <= 0x10FFFF)
		bsize = 4;
	return (bsize);
}

static char		*uni_trans(wchar_t w, int size)
{
	char		*tmp;

	tmp = ft_strnew(size + 1);
	if (w >= 0 && w <= 0x7F && tmp)
		tmp[0] = w;
	else if (w > 0x7F && w <= 0x7FF && tmp)
	{
		tmp[0] = (w >> 6) + 0xC0;
		tmp[1] = (w & 0x3F) + 0x80;
	}
	else if (w > 0x7FF && w <= 0xFFFF && tmp)
	{
		if (w >= 0xD800 && w <= 0xDFFF)
			return (NULL);
		tmp[0] = (w >> 12) + 0xE0;
		tmp[1] = ((w >> 6) & 0x3F) + 0x80;
		tmp[2] = (w & 0x3F) + 0x80;
	}
	else if (w > 0xFFFF && w <= 0x10FFFF && tmp)
	{
		tmp[0] = (w >> 18) + 0xF0;
		tmp[1] = ((w >> 12) & 0x3F) + 0x80;
		tmp[2] = ((w >> 6) & 0x3F) + 0x80;
		tmp[3] = (w & 0x3F) + 0x80;
	}
	else
		return (NULL);
	return (tmp);
}

static int		wchar_prec(wchar_t *w, t_info *data)
{
	int			x;
	int			fsz;
	int			y;

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

static char		*uni_copy(char *s, int y, int x, wchar_t *w)
{
	char		*tmp;

	tmp = NULL;
	if (!(tmp = uni_trans(w[x], y)))
		return (NULL);
	s = ft_strncat(s, tmp, y);
	free(tmp);
	ft_bzero(tmp, y);
	return (s);
}

char			*uni_conv(wchar_t *w, t_info *data, int spe, int y)
{
	int			x;
	int			test;
	int			fsz;
	char		*s;

	x = 0;
	test = 0;
	if (spe == 0)
		fsz = wchar_prec(w, data);
	else
		fsz = uni_size(w[0]);
	if (!(s = ft_strnew(fsz)))
		return (NULL);
	while (w[x])
	{
		y = uni_size(w[x]);
		test += y;
		if (fsz < test)
			break ;
		if (!(s = uni_copy(s, y, x, w)))
			return (NULL);
		x++;
	}
	return (s);
}
