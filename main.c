/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:42:46 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/08 13:55:44 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		main()
{
	short	shrt = 58, sht2 = 6659;
	int		i = 0, ex = -526, ex2 = 652, ex3 = -2569, ret = 0;
	long	lng = 56987456311999;
	long long	lngl = -99999999996, lngmax = 9223372036854775807, lngmin = -9223372036854775808;

	unsigned short	usht = 5845;
	unsigned int uex = 4000000000;
	unsigned long	ulng = 3500000000000001234;
	unsigned long long	ulngl = 8750000124875457865, umax = 18446744073709551615, utest = 18446744031709551615;

	char	c = 'A';
	char test = ex;
	char	*s1 = "\n___Salut le monde _% 01h1.215h16.25*.*h*.*d_ + _%#15.12hhlX___  LAST : _%-15.5d_+++ NEW LaSt : '%-10.15s'++==++\n", *s2 = "This is a sentence";
	char	*s3 = "TEST %lld %ld", *s4 = "_%-+*d_\n";
	char	*s5 = "_%20s_ petit test si possible\n", *s6 = "\n\n";

//ft_printf("|#		'# + - 0 15 L d'		: _%#0+---hh--hhh-++++++0015d_\n", ex2);

//printf("1_%-15.10t_____________ %12d salut\n", 10);
//ft_printf("2_%-15.10t_ %12d salut\n", 10);
/*printf("1_%-15.10#+y_ %12d salut\n", 10);
ft_printf("2_%-15.10#+y_ %12d salut\n", 10);*/
/*printf(s1, 10, 12, 45, 20, ex2, ex3, ex2, s5);
ft_printf(s1, 10, 12, 45, 20, ex2, ex3, ex2, s5);
*/



	nbr_cmp();
	return (0);
}
