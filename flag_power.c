/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_power.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:31:00 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/23 18:45:27 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		new_data(t_info **data)
{
	(*data)->nbr_h = 0;
	(*data)->nbr_l = 0;
	(*data)->prec = 0;
	(*data)->mfield = 0;
	(*data)->flags = 0;
	(*data)->cmd_size = 0;
	(*data)->type = 0;
	(*data)->conv= 0;
	(*data)->s_ct[0] = 0;
	(*data)->s_ct[1] = 0;
	(*data)->s_ct[2] = 0;
}

/*
			GERER LE CAS OU IL Y A UN ZERO AVEC FLAG PLUS ET PREC 0
			PROBLEM WITH THE + SIGN

			THE PLUS SIGN : + 1 TO SIZE IF TOTAL WIDTH PREC SIZE IF NOT NO +1
			IF MFIELD NON EXISTANT MINUS FLAG SHUT DOWN
*/

char		*size_testout(t_info *data, char *s, int size)
{
	int		size2;
	int		sign;
	char	*new;
	char	*tmp;

	size2 = 0;
	sign = 0;
	tmp = s;
	if (data->s_ct[0] == -2)
		sign = 1;
	if (data->prec == 0 && s[0] == '0')
		new = ft_strdup("\0");
	else
		new = ft_strdup(s);
	printf("\n1-\n");
	if (data->flags & DOT_H)
	{
		printf("\n1- DOT\n");
		tmp = new;
		new = flag_prec(data->prec, new, size);
		free(tmp);
		printf("DOT : _%s_\n", new);
	}
	printf("\n2-\n");
	if (data->flags & MFIELD_HH)
	{
		printf("\n2- MFIELD\n");
		tmp = new;
		new = flag_mfield(data->mfield, data, new);
		printf("MFIELD : _%s_\n", new);
		free(tmp);
	}
	printf("\n3-\n");
	if (data->flags & PLUS_LL)
	{
		printf("\n3- PLUS\n");
		tmp = new;
		//printf("%zu\n", ft_strlen(new));
		new = flag_signs(new, ft_strlen(new), sign, data);
		printf("NEW SIGNS : _%s_\n", new);
		free(tmp);
	}
	printf("\n4-\n");
	if (!(data->flags & PLUS_LL) && data->flags & SPACE)
	{
		printf("\n4- SPACE\n");
		tmp = new;
		//printf("%zu\n", ft_strlen(new));
		new = flag_space(new, ft_strlen(new), data);
		printf("NEW SPACE : _%s_\n", new);
		free(tmp);
	}
	if (data->flags & HASH_J)
		new = flag_hash(new, ft_strlen(new), ft_strlen (s), data);
	printf("\n6- END\n%s\n", new);
	return (new);
}

char		*flag_manager(t_info *data, char *s)
{
	char	*new;
	int		size;

	new = NULL;
	if (data->flags == 0 || data->flags == 128)
		return (s);
	size = ft_strlen(s);
	printf("VERIF MFIELD ---> %d, %d, %d -> %d\n", MFIELD_HH, data->mfield, data->prec, size);
	ft_print_bits(data->flags, 8);
	printf("\n");
	if (data->flags &  MFIELD_HH && (data->mfield <= size ||
		data->mfield <= data->prec))
		data->flags &= data->flags - MFIELD_HH;
	if (data->flags & DOT_H && data->prec <= size)
		data->flags &= data->flags - DOT_H;
		printf("VERIF MFIELD ---> %d\n", MFIELD_HH);
		ft_print_bits(data->flags, 8);
		printf("\n");
	new = size_testout(data, s, size);
	printf("INFORMATION : _%s_	%zu, %zu\n", new, ft_strlen(new), ft_strlen("-000000000007616"));
	return (new);
}
