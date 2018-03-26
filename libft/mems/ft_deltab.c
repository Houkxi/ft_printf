/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:35:32 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/20 14:54:39 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	ft_deltab(char **tab)
{
	int y;

	y = 0;
	if (tab)
	{
		while (tab[y])
		{
			free(tab[y]);
			tab[y] = NULL;
			y++;
		}
		free(tab);
		tab = NULL;
	}
}
