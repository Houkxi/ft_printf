/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_pmss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:47:28 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/23 18:47:40 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*flag_signs(char *d, int size, int sign, t_info *data)
{
	char	*new;
	int		x;

	x = 0;
	printf("SIGNS TEST\n");
	if (data->flags & MFIELD_HH)
		new = d;
	else
	{
		new = ft_memalloc(size + 1);
		new = ft_strdecal(new, d, 1);
		new[size + 1] = '\0';
	}
	while (new[x] == ' ')
		x++;
	if (x > 0)
		x -= 1;
	if (sign == 1)
		new[x] = '-';
	else
		new[x] = '+';
	return (new);
}

char		*flag_space(char *d, int size, t_info *data)
{
	char	*new;
	int		x;

	x = 0;
	if (data->flags & MFIELD_HH)
		new = d;
	else
	{
		new = ft_memalloc(size + 1);
		new = ft_strdecal(new, d, 1);
		new[size + 1] = '\0';
	}
	new[0] = ' ';
	return (new);
}

char		*flag_hash(char *d, int size, int oldsize, t_info *data)
{
	char	*new;
	int		x;

	x = 0;
	if (data->flags & MFIELD_HH && data->mfield >= oldsize + 2)
		new = d;
	else
	{
		new = ft_memalloc(size + 2);
		new = ft_strdecal(new, d, 2);
		new[size + 2] = '\0';
	}
	while (new[x] == ' ')
		x++;
	if (x > 0)
		x -= 2;
	new[x] = 'O';
	if (data->type == 'x')
		new[x + 1] = 'x';
	else if (data->type == 'X')
		new[x + 1] = 'X';
	return (new);
}

char		*flag_prec(int prec, char *s, int size)
{
	char	*new;
	int		sign;

	sign = 0;
	if (prec <= size)
		return (s);
	if ((new =(char*)malloc((prec + 1))) == NULL)
		return (NULL);
	new[prec] = '\0';
	if (s[0] == '-')
		sign = 1;
	while (size >= sign && s[0] != '0')
	{
		new[prec] = s[size];
		prec--;
		size--;
	}
	while (prec >= 0 && s[0] != '0')
		new[prec--] = '0';
	return (new);
}

char		*flag_mfield(int mfield, t_info *data, char *s)
{
	char	*new;

	if ((size_t)mfield <= ft_strlen(s))
		return (s);
	if ((new =(char*)malloc(mfield + 1)) == NULL)
		return (NULL);
	new[mfield] = '\0';
	if (data->flags & ZERO_Z && !(data->flags & DOT_H))
		new = ft_strfill(new, '0', mfield);
	else
		new = ft_strfill(new, ' ', mfield);
	if (data->flags & MINUS_L)
	{
		if (data->flags & PLUS_LL || data->flags & SPACE)
			new = ft_strdecal(new, s, 1);
	}
	else
		new = ft_strcpy_dir(new, s, -1, mfield - 1);
	return (new);
}
