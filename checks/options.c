/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <exam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:32:46 by exam              #+#    #+#             */
/*   Updated: 2018/03/01 17:09:25 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		power(int power)
{
	int i;

	i = 1;
	if (power == 0)
		return (1);
	while (power--)
		i *= 2;
	return (i);
}

int		ft_occ(char *s, char c)
{

	int x;

	x = 0;
	while (s[x])
	{
		if (s[x] == c)
			return (x);
		x++;
	}
	if (s[x] == c)
		return (x);
	return (-1);
}

int		options(char *s, int *oct)
{
	int x;
	int ret;

	x = 1;
	ret = 0;
	if (s[0] != '-')
		return (0);
	while (s[x])
	{
		ret = ft_occ("abcdefghijklmnopqrstuvwxyz", s[x]);
		if (ret == -1)
			return (-1);
		ret = power(ret);
		*oct |= ret;
		x++;
	}
	return (*oct);
}
