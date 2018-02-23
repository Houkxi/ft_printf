/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:33:37 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/23 16:26:44 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/*
		Not workimg with a long long overflow, look towards maxint_t.
		Might be the answer.
		Define if I want to work with a malloc or a static
*/

static int		signed_count(long long int nb, int i, int base)
{
	if (nb < 0)
	{
		if (base == 10)
			i++;
		nb *= -1;
	}
	if (nb >= base)
		return (rec_nbr_count(nb / base, i + 1, base));
	return (i);
}

static int		unsigned_signed_count(unsigned long long int nb, int i, int base)
{
	if (nb >= base)
		return (rec_nbr_count(nb / base, i + 1, base));
	return (i);
}

char			*ft_utoall(unsigned long long int n, int base, int size, int sign)
{
	char		*str;
	static char	us[49];
	char		*tmp;
	int			value;

	if (base < 2 || base > 16)
		return (NULL);
	str = "0123456789ABCDEF";
	size = unsigned_signed_count(n, 0, base) + 1;
	ft_bzero(us, size + 1);
	us[size] = '\0';
	while (size-- > sign)
	{
		value = n % base;
		us[size] = str[value];
		n /= base;
	}
	tmp = &us[0];
	return (tmp);
}

char			*ft_itoall(long long int n, int base, int size, int *sign)
{
	char		*str;
	static char	s[49];
	char		*tmp;
	int			value;

	if (base < 2 || base > 16)
		return (NULL);
	str = "0123456789ABCDEF";
	if (n < 0)
	{
		*sign = -2;
		n *= -1;
	}
	size = signed_count(n, 0, base) + 1;
	ft_bzero(s, size + 1);
	s[size] = '\0';
	while (size-- > 0)
	{
		value = n % base;
		s[size] = str[value];
		n /= base;
	}
	tmp = &s[0];
	return (tmp);
}
