/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:21:30 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/06 11:45:32 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*chr_manager(va_list **arg, t_info *data)
{
	char	*save;

	save = NULL;
	if (data->type == 'c')
	{
		if ((save = (char*)malloc(2)) == NULL)
			return (NULL);
		save[1] = '\0';
		save[0] = (char)va_arg(**arg, intmax_t);
	}
	if (data->type == 's')
	{
		save = va_arg(**arg, char*);
		if (save == NULL)
			save = "(null)";
	}
	if (data->type == 'C')
		return (NULL);
	if (data->type == 'S')
		return (NULL);
	else
		return (save);
}
