/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:05:51 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/12 20:18:45 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*flag_prec_chr(int prec, char *s, int size)
{
	char	*new;

	if (prec > size)
		prec = size;
	if ((new = (char*)malloc((prec + 1))) == NULL)
		return (NULL);
	new[prec] = '\0';
	ft_strncpy(new, s, prec);
	free(s);
	return (new);
}

static void	mfielding(int len, char c)
{
	char	*new;
	int		size;

	size = len;
	if (len <= 0)
		return ;
	if ((new = (char*)malloc((len + 1))) == NULL)
		return ;
	new[len] = '\0';
	while (len--)
		new[len] = c;
	buff_rend(new, size, 0);
	free(new);
}

void		flag_mfield_chr(int size, t_info *data, char *s, unsigned int sv)
{
	int		mfield;

	mfield = data->mfield;
	if (sv & MINUS)
	{
		mfield -= flag_sign(data, data->flgs, 0);
		buff_rend(s, size, 0);
		mfielding(mfield - size, ' ');
	}
	else if (sv & ZERO)
	{
		size += flag_sign(data, data->flgs, 0);
		mfielding(mfield - size, '0');
		buff_rend(s, size, 0);
	}
	else
	{
		if (sv & PLUS || sv & SPACE)
			size++;
		mfielding(mfield - size, ' ');
		flag_sign(data, data->flgs, 0);
		buff_rend(s, size, 0);
	}
	free(s);
}
