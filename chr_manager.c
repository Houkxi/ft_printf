/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:21:30 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/13 19:41:00 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*chr_manager(va_list **arg, t_info *data)
{
	char	*save;
	char	c;
	wchar_t	*tmp;
	wchar_t	t;

	save = NULL;
	if (data->type == 'c' && !(data->flgs & L))
	{
		if ((save = (char*)malloc(2)) == NULL)
			return (NULL);
		save[1] = '\0';
		c = (char)va_arg(**arg, intmax_t);
		if (!c || c == 0)
			save = "\0";
		else
			save[0] = c;
	}
	else if (data->type == 'C' || (data->type == 'c' && data->flgs & L))
	{
		data->s_ct[0] = -15;
		t = va_arg(**arg, wchar_t);
		if (!t || t == 0)
			save = "\0";
		else
			save = uni_conv(&t, data, 1);
		return (save);
	}
	else if (data->type == 's')
	{
		save = va_arg(**arg, char*);
		if (save == NULL)
			save = "(null)";
	}
	if (data->type == 'S'|| (data->type == 's' && data->flgs & L))
	{
		data->s_ct[0] = -15;
		tmp = va_arg(**arg, wchar_t*);
		if (!tmp)
			save = "(null)";
		else
			save = uni_conv(tmp, data, 0);
		return (save);
	}
	else
		return (save);
}
