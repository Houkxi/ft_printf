/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:29:33 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/19 14:34:49 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				buff_rend(char *s, int len, int fd)
{
	static int	size = 0;
	static char	*rend = NULL;
	char		*tmp;
	int			mlen[2];

	mlen[0] = size;
	mlen[1] = len;
	if (fd >= 1)
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
