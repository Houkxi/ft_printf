/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:14:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/08 13:17:02 by mmanley          ###   ########.fr       */
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
	int		ret = 0, ret1 = 0, ret2 = 0, fd1, stret = 50, sv = 0, i = 0, szret = 0;
	char	*titles[15] = {"BASICS", "PRECISION", "MFIELD", "MFIELD && PRECISION",
						"THE 0 EXCEPTION", "UNSIGNED", "FUNKY SHIT", "STRING STUFF",
						"SPES", "BONUS", "UNDEFINED", "END"};

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
		i = 0;
		while ((ret1 = get_next_line(fd1, &line1)) > 0 &&
			(ret2 = get_next_line(fd1, &line2)) > 0)
			{
				szret = 0;
				if ((stret = ft_strcmp("TITLE TO PARS THE RENDER", line1)) == 0)
				{
					printf("\033[0;33m");
					printf("\n-----------------\n%s\n-----------------\n", titles[i]);
					if ((ret1 = get_next_line(fd1, &line1)) <= 0)
						ret1 = ret1;
					i++;
				}
				else if ((stret = ft_strcmp("TITLE TO PARS THE RENDER", line2)) == 0)
				{
					printf("\033[0;33m");
					printf("\n-----------------\n%s\n-----------------\n", titles[i]);
					if ((ret2 = get_next_line(fd1, &line2)) <= 0)
						ret2 = ret2;
					i++;
				}
				else
				{
					stret = ft_strcmp(line1, line2);
					if (ft_strlen(line1) != ft_strlen(line2))
						szret = -5;
					if (stret != 0 || szret == -5)
					{
						printf("\033[0;31m");
						printf("\n_->%s_\n_<+%s_\n", line1, line2);
						printf("\033[0;0m");
					}
					else if ((sv & 1 || sv & 4) && stret == 0)
					{
						printf("\033[0;32m");
						printf("->%s\n", line1);
						if (!(sv & 4))
							printf("<+%s\n", line2);
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
						//printf("\n_%s_\n_%s_\n", line1, line2);
						printf(".");
					}
				}
			}
	}
	else
		printf("usage : [flags] Target_File\n");
	return (0);
}
