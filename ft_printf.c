/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:02:50 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/13 19:40:53 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

void	affichage(t_info data)
{
	printf("\n*************************-1-,\n---DATA---\nTYPE : %c\n", data.type);
	ft_putstr("FLGS : ");
	ft_print_bits_int(data.flgs, 32);
	printf("\n");
	printf("\nMFIELD : %d\n", data.mfield);
	printf("PREC : %d\n\n", data.prec);
	printf("L : %d ---- H : %d\n*************************-2-'\n\n", data.nbr_l, data.nbr_h);
}

t_info		*ft_printf_2(va_list *arg, char **tmp, char *s, int *x)
{
	t_info	data;
	t_info	*tp;

	data.cmd_size = -1;
	tp = NULL;
	if (s && data_init(&arg, &data, s) >= -1)
	{
		//affichage(data);
		if (!(data.flgs & STOP))
		{
			if (data.flgs & DEC)
				*tmp = nbr_manager(&arg, &data);
			else
				*tmp = chr_manager(&arg, &data);
			*tmp && *tmp[0] == '\0' && ft_occ_pos("cC", data.type) > -1 ? data.nbr_l = 1 : data.nbr_l;
			*tmp && *tmp[0] != '\0' ? data.nbr_l = ft_strlen(*tmp) : data.nbr_l;
		}
		else
		{
			*tmp = ft_strnew(1);
			*tmp[0] = data.type;
			data.nbr_l = 1;
		}
		*x += data.cmd_size + 1;
		tp = &data;
		*tmp = flag_manager(&data, *tmp, data.nbr_l);
	}
	return (tp);
}

int		ft_printf(char *s, ...)
{
	va_list	arg;
	int		x;
	int		size;
	int		ret;
	char	*tmp;

	tmp = NULL;
	x = 0;
	ret = 0;
	if (!s && !*s)
		return (-1);
	va_start(arg, s);
	while (s[ret + x])
	{
		while (s[ret + x] && s[ret + x] != '%')
			x++;
		buff_rend(&s[ret], x, 0);
		if (s[ret + x] && !(ft_printf_2(&arg, &tmp, &s[ret + x], &x)))
			return (-1);
		ret += x;
		x = 0;
	}
	size = buff_rend(NULL, 0, 1);
	//printf("MINE : %d\n", size);
	//while(1);
	//show_it_all(NULL, size, 1, 0);
	va_end(arg);
	return (size);
}
