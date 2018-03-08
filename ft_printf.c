/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:02:50 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/08 14:12:21 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

void	affichage(t_info data)
{
	printf("\n*************************-1-,\n---DATA---\nTYPE : %c\n", data.type);
	ft_putstr("FLAGS : ");
	ft_print_bits(data.flags, 8);
	printf("\n");
	ft_putstr("CONV : ");
	ft_print_bits(data.conv, 8);
	printf("\nMFIELD : %d\n", data.mfield);
	printf("PREC : %d\n\n", data.prec);
	printf("L : %d ---- H : %d\n*************************-2-'\n\n", data.nbr_l, data.nbr_h);
}

int		ft_printf_2(va_list *arg, int *size, char *s)
{
	t_info	data;
	int		x;
	int		ret;
	char	*tmp;

	x = 0;
	ret = 0;
	tmp = NULL;
	//printf("%zu\n", ft_strlen(s));
	while (s[ret + x])
	{
		while (s[ret + x] && s[ret + x] != '%')
			x++;
		buff_rend(&s[ret], x, 0);
		if (s[ret + x] && data_init(&arg, &data, &s[ret + x]) >= -1)
		{
		//	affichage(data);
			if (!(data.flags & STOP_D))
			{
				if (data.conv & STOP_D)
					tmp = nbr_manager(&arg, &data);
				else
					tmp = chr_manager(&arg, &data);
			}
			else
			{
				//printf("TYPE : %c\n", data.type);
				tmp = ft_memalloc(1);
				tmp[0] = data.type;
				tmp[1] = '\0';
				//printf("STRING : _%s_\n", tmp);
				//data.flags = pars_check(data), data.type, data.conv);
			}
			tmp = flag_manager(&data, tmp, ft_strlen(tmp));
			x += data.cmd_size + 1;
		}
		else if (s[ret + x])
			return (-1);
		ret += x;
		x = 0;
	}
	//printf("\nJAI FINI MES BETISES !!!!!!!\n");
	return (*size);
}

int		ft_printf(char *s, ...)
{
	va_list	arg;
	int		size;

	size = 0;
	if (!s && !*s)
		return (-1);
	va_start(arg, s);
	if (ft_printf_2(&arg, &size, s) == -1)
		return (-1);
	buff_rend(NULL, 0, 1);
	//while(1);
	//show_it_all(NULL, size, 1, 0);
	va_end(arg);
	return (size);
}
