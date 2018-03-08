/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:21:30 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/08 18:25:16 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		uni_size(wchar_t w)
{
	int		bsize;

	bsize = 0;
	if (w <= 0x7F)
		bsize = 1;
	else if (w <= 0x7FF)
		bsize = 2;
	else if (w <= 0x7FFF)
		bsize = 3;
	else
		bsize = 4;
	return (bsize);
}

char	*uni_trans(wchar_t w, int size)
{
	char *tmp;

	if ((tmp = (char*)malloc(size + 1)) == NULL)
		return (NULL);
	tmp[size]  = '\0';
	if (w <= 0x7F)
	{
		printf("1 BYTE\n");
		tmp[0] = w;
	}
	else if (w <= 0x7FF)
	{
		printf("2 BYTES\n");
		tmp[0] = (w >> 6) + 0xC0;
		tmp[1] = (w & 0x3F) + 0x80;
	}
	else if (w <= 0x7FFF) // 3 bytes
	{
		printf("3 BYTES\n");
		tmp[0] = (w >> 12) + 0xE0;
		tmp[1] = ((w >> 6) & 0x3F) + 0x80;
		tmp[2] = (w & 0x3F) + 0x80;
	}
	else // 4 bytes (since UTF-32 is the biggest?)
	{
		printf("4 BYTES\n");
		tmp[0] = (w >> 18) + 0xF0;
		tmp[1] = ((w >> 12) & 0x3F) + 0x80;
		tmp[2] = ((w >> 6) & 0x3F) + 0x80;
		tmp[3] = (w & 0x3F) + 0x80;
	} // if you putchar 4 hex values in a row, the computer will understand it as one wchar_t character
	ft_putchar('\n');
	return (tmp);
}

char	*uni_conv(wchar_t *w)
{
	int x;
	int y;
	int	fsz;
	char	*s;
	char *tmp;

	x = 0;
	y = 0;
	fsz = 0;
	while (w[x])
	{
		fsz += uni_size(w[x]);
		printf("%d\n", fsz);
		x++;
	}
	if ((s = (char*)malloc(fsz + 1)) == NULL)
		return (NULL);
	ft_bzero(s, fsz);
	s[fsz] = '\0';
	x = 0;
	while (w[x])
	{
		fsz = uni_size(w[x]);
		tmp = uni_trans(w[x], fsz);
		s = ft_strcat(s, tmp);
		x++;
	}
	return (s);
}

void    ft_putwchar(wchar_t c)
{
    if (c <= 0x7F) // 1 byte
    {
        ft_putchar(c);
    }
    else if (c <= 0x7FF) // 2 bytes
    {
        ft_putchar((c >> 6) + 0xC0); // 0xC0 is the code point range, and >> 6 shifts bits 6 places over
        ft_putchar((c & 0x3F) + 0x80); // 0x3F is the code point range, and 0x80 is the masking value
    }
    else if (c <= 0x7FFF) // 3 bytes
    {
    ft_putchar((c >> 12) + 0xE0);
    ft_putchar(((c >> 6) & 0x3F) + 0x80);
    ft_putchar((c & 0x3F) + 0x80);
    }
    else // 4 bytes (since UTF-32 is the biggest?)
    {
    ft_putchar((c >> 18) + 0xF0);
    ft_putchar(((c >> 12) & 0x3F) + 0x80);
    ft_putchar(((c >> 6) & 0x3F) + 0x80);
    ft_putchar((c & 0x3F) + 0x80);
    } // if you putchar 4 hex values in a row, the computer will understand it as one wchar_t character
	ft_putchar('\n');
}

char	*chr_manager(va_list **arg, t_info *data)
{
	char	*save;
	wchar_t	*tmp;
	int x = 0;

	save = NULL;
	if (data->type == 'c' && !(data->conv & MINUS_L))
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
	if (data->type == 'C' || (data->type == 'c' && data->conv & MINUS_L))
	{
		data->s_ct[0] = -15;
		if ((tmp = (wchar_t*)malloc(sizeof(wchar_t) * 2)) == NULL)
			return (NULL);
			tmp[1] = '\0';
		tmp[0] = va_arg(**arg, wchar_t);
		save = uni_conv(tmp);
		return (save);
	}
	if (data->type == 'S')
	{
		data->s_ct[0] = -15;
		tmp = va_arg(**arg, wchar_t*);
		printf("PRINT MY SHIT\n");
		while (tmp[x])
		{
			ft_putwchar(tmp[x]);
			x++;
		}
		printf("\n");
		save = uni_conv(tmp);
		printf("PRINT SAVE\n");
		ft_putendl(save);
		printf("\n");
		return (save);
	}
	else
		return (save);
}
