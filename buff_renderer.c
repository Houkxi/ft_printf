/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:29:33 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/08 14:55:26 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			buff_rend(char *s, int len, int wrt)
{
	static int	size = 0;
	static char	*rend = NULL;
	char		*tmp;

	if (wrt == 1)
	{
		size = ft_strlen(rend);
		write(1, rend, size);
		free(rend);
		ft_bzero(rend, size);
		rend = NULL;
		size = 0;
		return (size);
	}
	else
	{
		if (!rend)
			rend = ft_memalloc(1);
		if ((tmp = (char*)malloc(len + 1)) == NULL)
			return (0);
		tmp = ft_strncpy(tmp, s, len);
 		rend = ft_strjoin_free(rend, tmp, 1);
		free(tmp);
	}
	return (len);
}
