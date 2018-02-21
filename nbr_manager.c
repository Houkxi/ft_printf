/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:43:16 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/21 17:43:31 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*signed_nbrs(va_list ***arg, t_info *data, int base)
{
	char *save;

	save = NULL;
	if (data->conv & MINUS_L)
		save = ft_itoall((long int)(va_arg(***arg, intmax_t)), base, 0, 0);
	else if (data->conv & PLUS_LL)
		save = ft_itoall((long long int)(va_arg(***arg, intmax_t)), base, 0, 0);
	else if (data->conv & HASH_J)
		save = ft_itoall((intmax_t)(va_arg(***arg, intmax_t)), base, 0, 0);
	else if (data->conv & ZERO_Z)
		save = ft_itoall((size_t)(va_arg(***arg, intmax_t)), base, 0, 0);
	else if (data->conv & DOT_H)
		save = ft_itoall((short int)(va_arg(***arg, intmax_t)), base, 0, 0);
	else if (data->conv & MFIELD_HH)
		save = ft_itoall((char)(va_arg(***arg, intmax_t)), base, 0, 0);
	else if (data->conv == 128)
		save = ft_itoall((int)(va_arg(***arg, intmax_t)), base, 0, 0);
	return (save);
}

char		*unsigned_nbrs(va_list ***arg, t_info *data, int base)
{
	char *save;

	save = NULL;
	if (data->conv & MINUS_L)
		save = ft_utoall((unsigned long int)(va_arg(***arg, uintmax_t)), base, 0, 0);
	else if (data->conv & PLUS_LL)
		save = ft_utoall((unsigned long long int)(va_arg(***arg, uintmax_t)), base, 0, 0);
	else if (data->conv & HASH_J)
		save = ft_utoall((uintmax_t)(va_arg(***arg, uintmax_t)), base, 0, 0);
	else if (data->conv & ZERO_Z)
		save = ft_utoall((size_t)(va_arg(***arg, uintmax_t)), base, 0, 0);
	else if (data->conv & DOT_H)
		save = ft_utoall((unsigned short int)(va_arg(***arg, uintmax_t)), base, 0, 0);
	else if (data->conv & MFIELD_HH)
		save = ft_utoall((unsigned char)(va_arg(***arg, uintmax_t)), base, 0, 0);
	else if (data->conv == 128)
		save = ft_utoall((unsigned int)(va_arg(***arg, uintmax_t)), base, 0, 0);
	return (save);
}

char		*nbr_manager(va_list **arg, t_info *data)
{
	char *rendu;

	rendu = NULL;
	if (data->type == 'd' || data->type == 'D' || data->type == 'i')
	{
		if (data->type == 'D' && !(data->conv & MINUS_L))
			data->conv |= PLUS_LL;
//		printf("JE VAIS TE CONVERTIR\n");
		rendu = signed_nbrs(&arg, data, 10);
		if (rendu[0] == '-')
			data->flags |= PLUS_LL;
	//	printf("%s\n", rendu);
	}
	else if (data->type == 'u' || data->type == 'U' || data->type == 'x' ||
		data->type == 'X' || data->type == 'o' || data->type == 'O')
	{
		if (data->flags & PLUS_LL)
			data->flags &= data->flags - PLUS_LL;
		if (data->type == 'X' || data->type == 'x')
			rendu = unsigned_nbrs(&arg, data, 16);
		else if (data->type == 'o')
			rendu = unsigned_nbrs(&arg, data, 8);
		else
			rendu = unsigned_nbrs(&arg, data, 10);
		if (data->type == 'x')
			ft_put_to_lower(rendu);
	}
	return (rendu);
}
