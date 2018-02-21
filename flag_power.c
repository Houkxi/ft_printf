/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_power.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:31:00 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/21 20:15:44 by mmanley          ###   ########.fr       */
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
}

char		*ft_strfill(char *s, char c, int len)
{
	char	*new;
	int x;

	new = s;
	x = 0;
	while(len--)
	{
		s[x] = c;
		x += 1;
	}
	return (new);
}

char		*ft_strcpy_dir(char *d, char *s, int dir, int start)
{
	int		x;
	int		end;
	int		ssz;

	end = ft_strlen(d) - 1;
	ssz = ft_strlen(s);
	x = ssz - 1;
	if (end < x || (dir != 1 && dir != -1))
		return (NULL);
	if (dir == 1)
	{
		end = 0;
		x = 0;
	}
	while ((s[x] && x >= 0) || (x > 0 && x < ssz))
	{
		d[end] = s[x];
		end += dir;
		x += dir;
	}
	return(d);
}

char		*flag_prec(int prec, char *s, int size, t_info *data)
{
	char	*new;
	int		sign;

	sign = 0;
	prec++;
	if (data->flags & PLUS_LL)
	{
		if (s[0] == '-')
			size--;
		sign = 1;
	}
	if ((new =(char*)malloc((prec + 1))) == NULL)
		return (NULL);
	new[prec] = '\0';
	prec--;
	if (s[0] == '-')
		new[0] = '-';
	else if (data->flags & PLUS_LL)
		new[0] = '+';
	while (size >= sign && s[0] != '0')
	{
		printf("%d, %d\n", sign, size);
		new[prec] = s[size];
		prec--;
		size--;
	}
	while (prec >= sign)
		new[prec--] = '0';
	printf("\nNEW ***** : _%s_ :*******\n", new);
	return (new);
}

char		*flag_mfield(int mfield, t_info *data)
{
	char	*new;

	if ((new =(char*)malloc(mfield + 1)) == NULL)
		return (NULL);
	new[mfield] = '\0';
	if (data->flags & ZERO_Z && !(data->flags & DOT_H))
		new = ft_strfill(new, '0', mfield);
	else
		new = ft_strfill(new, ' ', mfield);
	printf("NEW MFIELD : _%s_\n", new);
	return (new);
}

/*
			GERER LE CAS OU IL Y A UN ZERO AVEC FLAG PLUS ET PREC 0
			PROBLEM WITH THE + SIGN
*/

char		*size_testout(t_info *data, char *s, int size)
{
	int size2;
	char *new;

	size2 = 0;
	new = NULL;
	printf("%d < | > %d , %d\n", size, data->mfield, data->prec);
	if (data->mfield > data->prec)
		new = flag_mfield(data->mfield, data);
	printf("%d < | > %d , %d\n", size, data->mfield, data->prec);
	/*if (s[0] == '0' && data->prec == 0&& data->flags & DOT_H && data->flags & PLUS_LL)
	{
		s[0] = '+';
		data->flags |= MINUS_L;
	}
	else if (s[0] == '0' &&  data->prec == 0 && !(data->flags & PLUS_LL))
		s[0] = '\0';*/
	if (/*data->flags & DOT_H ||*/ (s[0] == '-' && data->prec >= size - 1) || (s[0] != '-' && data->prec >= size))
		s = flag_prec(data->prec, s, size, data);
	printf("\n\n*****%s, %d*****\n\n", s, data->prec);

	/*if ((s[0] == '-' && data->prec >= size - 1) || (s[0] != '-' && data->prec >= size))
		s = flag_prec(data->prec, s, size, data);*/
	printf("CMP : ***\nS : _%s_\nN : _%s_\n*****\n", s, new);
	if (data->prec >= data->mfield)
		return (s);
	else if (data->flags & MINUS_L)
		ft_strcpy_dir(new, s, 1, 0);
	else
		ft_strcpy_dir(new, s, -1, data->mfield);
	printf("NEW _%s_\n", new);
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
	new = size_testout(data, s, size);
	printf("INFORMATION : _%s_	%zu, %zu\n", new, ft_strlen(new), ft_strlen("-000000000007616"));
	return (new);
}
