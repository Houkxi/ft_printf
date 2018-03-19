/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:58:59 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/19 19:17:32 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					tab_size(char **tab, int ct)
{
	int				y;
	int				x;

	y = 0;
	x = 0;
	while (tab[y])
	{
		while (tab[y][x])
		{
			ct++;
			x++;
		}
		x = 0;
		y++;
	}
	return (ct);
}

char				*tab_to_char(char *new, char **tab, int z)
{
	int				y;
	int				x;

	y = 0;
	x = 0;
	while (tab[y])
	{
		new[z] = '\n';
		z++;
		while (tab[y][x])
		{
			new[z] = tab[y][x];
			x++;
			z++;
		}
		x = 0;
		y++;
	}
	new[z] = '\n';
	new[z + 1] = '\0';
	return (new);
}

char				*tab_spec(va_list ****arg, t_info ***data)
{
	char			**tab;
	char			*new;
	int				ct;

	(**data)->flgs &= 0xFFFF0000;
	if (!(tab = va_arg(****arg, char**)))
		return (ft_strdup("(null)"));
	ct = tab_size(tab, 0);
	if (!(new = ft_strnew(ct)))
		return (NULL);
	new = tab_to_char(new, tab, 0);
	return (new);
}

char				*bonus_part(va_list ***arg, t_info **data)
{
	char			*rendu;

	rendu = NULL;
	if ((*data)->type && (*data)->type == 'b')
	{
		(*data)->flgs &= 0xFFFF00B1;
		rendu = binairy_spec(&arg, &data);
	}
	if ((*data)->type && (*data)->type == 't')
		rendu = tab_spec(&arg, &data);
	return (rendu);
}
