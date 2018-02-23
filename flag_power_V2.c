/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_power.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:31:00 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/22 19:51:39 by mmanley          ###   ########.fr       */
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

	end = start;
	ssz = ft_strlen(s);
	x = ssz - 1;
	if ((dir != 1 && dir != -1))
		return (NULL);
	if (dir == 1)
	{
		end = 0;
		x = 0;
	}
	printf("TEST_");
	while ((s[x] && x >= 0) || (x > 0 && x < ssz))
	{
		printf("%c", d[end]);
		d[end] = s[x];
		end += dir;
		x += dir;
	}
	printf("_\n2:  _%s_\n", d);
	return(d);
}

char		*flag_signs(char *d, int size, int sign, t_info *data)
{
	char	*new;
	char	*tmp;
	int		x;

	if ((new =(char*)malloc((size + 2))) == NULL)
		return (NULL);
	new[size + 1] = '\0';
	x = 0;
	while (d[x] == ' ')
			x++;
	if (x > 0)
		x -= 1;
	new = ft_strcpy_dir(new, d, -1, size + 1);
	if (sign == 1)
		new[x] = '-';
	else
		new[x] = '+';
	return (new);
}

char		*flag_space(char *d, int size, int sign, t_info *data)
{
	char	*new;
	char	*tmp;

	if (d[0] == ' ')
		return (d);
	if ((new =(char*)malloc((size + 2))) == NULL)
		return (NULL);
	new[size + 1] = '\0';
	new = ft_strcpy_dir(new, d, -1, size + 1);
	if (data->flags & SPACE)
		new[0] = ' ';
	return (new);
}

char		*flag_prec(int prec, char *s, int size, t_info *data)
{
	char	*new;
	int		sign;

	sign = 0;
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

	if ((new =(char*)malloc(mfield + 1)) == NULL)
		return (NULL);
	new[mfield] = '\0';
	if (data->flags & ZERO_Z && !(data->flags & DOT_H))
		new = ft_strfill(new, '0', mfield);
	else
		new = ft_strfill(new, ' ', mfield);
	return (new);
}

/*
			GERER LE CAS OU IL Y A UN ZERO AVEC FLAG PLUS ET PREC 0
			PROBLEM WITH THE + SIGN

			THE PLUS SIGN : + 1 TO SIZE IF TOTAL WIDTH PREC SIZE IF NOT NO +1
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
	if (s[0] == '-')
		sign = 1;
		printf("\n1- DOT\n", new);
	if (data->flags & DOT_H)
	{
		if (data->prec < size && s[0] != '0' && s[0] != '-')
			data->prec = size;
		if (data->prec < size && s[0] == '-')
			data->prec = size - 1;
		s = flag_prec(data->prec, s, size, data);
	}
	if ((new =(char*)malloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	new[ft_strlen(s)] = '\0';
//	free(tmp);
	printf("\n2- MFIELD\n", new);
	if (data->flags & MFIELD_HH)
	{
		if (data->mfield > ft_strlen(s))
			new = flag_mfield(data->mfield, data, s);
	}
	else
		data->mfield = ft_strlen(s);
		printf("\n3- MINUS\n", new);
	tmp = new;
	/*if (data->flags & MINUS_L)
		new = ft_strcpy_dir(new, s, 1, 0);*/
	if (data->mfield > ft_strlen(s) && !(data->flags & MINUS_L))
		new = ft_strcpy_dir(new, s, -1, data->mfield - 1);
	else
	{
		printf("\nBAD COPY IF MINUS\n", new);
		new = ft_strcpy_dir(new, s, 1, 0);
	}
	free(tmp);
	printf("\n4- PLUS\n", new);
	if (data->flags & PLUS_LL)
	{
		tmp = new;
		//printf("%zu\n", ft_strlen(new));
		new = flag_signs(new, ft_strlen(new), sign, data);
		free(tmp);
	}
	printf("\n5- SPACE\n", new);
	if (!(data->flags & PLUS_LL) && data->flags & SPACE)
	{
		tmp = new;
		//printf("%zu\n", ft_strlen(new));
		new = flag_space(new, ft_strlen(new), sign, data);
		//free(tmp);
	}
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
	new = size_testout(data, s, size);
	printf("INFORMATION : _%s_	%zu, %zu\n", new, ft_strlen(new), ft_strlen("-000000000007616"));
	return (new);
}
