/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_gestion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:52:59 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/08 14:21:13 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strfill(char *s, char c, int len)
{
	char	*new;
	int		x;

	new = s;
	x = 0;
	while (len--)
	{
		s[x] = c;
		x += 1;
	}
	return (new);
}

char		*ft_strdecal(char *d, char *s, int decl, int len)
{
	int		x;

	x = 0;
	if (s[0] == '\0')
		return (d);
	while (s[x] && len--)
	{
		d[decl] = s[x];
		x++;
		decl++;
	}
	return (d);
}

char		*ft_strcpy_dir(char *d, char *s, int dir, int start)
{
	int		x;
	int		end;
	int		ssz;

	end = start;
	ssz = ft_strlen(s);
	x = ssz - 1;
	if ((dir != 1 && dir != -1))
		return (NULL);
	if (dir == 1)
	{
		end = 0;
		x = 0;
	}
	while ((s[x] && x >= 0) || (x > 0 && x < ssz))
	{
		d[end] = s[x];
		end += dir;
		x += dir;
	}
	return (d);
}
