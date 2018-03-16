/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:29:33 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/16 16:48:44 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		error_case(char *s, int *size)
{
	if (s)
	{
		//free(s);
		ft_bzero(s, *size);
		s = NULL;
		*size = 0;
	}
	return (-1);
}

int				buff_rend(char *s, int len, int fd)
{
	static int	size = 0;
	static char	*rend = NULL;
	char		*tmp;
	int			mlen[2];

	mlen[0] = size;
	mlen[1] = len;
	if (fd == -1)
		return (error_case(rend, &size));
	else if (fd >= 1)
	{
		write(fd, rend, size);
		free(rend);
		ft_bzero(rend, size);
		rend = NULL;
		return (size);
	}
	else
	{
		if (!rend)
			size = 0;
		tmp = ft_memdup(s, len);
		rend = ft_memjoin_free(rend, tmp, mlen, 3);
		size += len;
	}
	return (len);
}
