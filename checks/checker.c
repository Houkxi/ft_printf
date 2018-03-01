/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:14:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/01 18:14:18 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <limits.h>

int		options(char *s, int *oct);

int		main(int argv, char **argc)
{
	char	*line1 = NULL, *line2 = NULL;
	int		ret = 0, ret1 = 0, ret2 = 0, fd1, stret = 0, sv = 0, i = 0;

	if (argv == 1)
	{
		printf("options: abcdefghijklmnopqrstuvwxyz + Target_File\nFlag : a -> valid green\n       b -> Cyan = you\n");
		return (0);
	}
	if (argv > 1)
	{
		while (i < argv)
		{
			if ((ret = options(argc[i], &sv)) == -1)
			{
				write(1, "Invalid Option\n", 15);
				return (0);
			}
			else if (ret & 128)
			{
				printf("options: abcdefghijklmnopqrstuvwxyz + Target_File\nFlag : a -> valid green\n       b -> Cyan = you\n");
				return (0);
			}
			i++;
		}
		if (argv == 2 && sv == 0)
			fd1 = open(argc[1], O_RDONLY);
		else
			fd1 = open(argc[2], O_RDONLY);
		while ((ret1 = get_next_line(fd1, &line1)) > 0 &&
			(ret2 = get_next_line(fd1, &line2)) > 0)
			{
				//printf("%s\n",line1);
				//printf("%s\n",line2);
				stret = ft_strcmp(line1, line2);
			if (stret != 0)
			{
				printf("\033[0;31m");
				printf("\n%s\n%s\n", line1, line2);
				printf("\033[0;0m");
			}
			else if (sv & 1 && stret == 0)
			{
				printf("\033[0;32m");
				printf("->%s\n<+%s\n", line1, line2);
				printf("\033[0;0m");
			}
			else if (sv & 2 && stret == 0)
			{
				printf("\033[0;36m");
				printf("->%s\n", line1);
				printf("\033[0;35m");
				printf("<+%s\n", line2);
				printf("\033[0;0m");
			}
			else
			{
				printf("\033[0;32m");
				printf(".");
			}
			}
	}
	else
		printf("usage : [flags] Target_File\n");
	return (0);
}
