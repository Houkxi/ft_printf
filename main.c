/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:42:46 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/13 19:48:24 by mmanley          ###   ########.fr       */
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
setlocale(LC_ALL, "");

ft_printf("LET's SEe whEre You StoP oR stARt _%+10Z_\n");
printf("LET's SEe whEre You StoP oR stARt _%+10Z_\n");
fflush(stdout);
/*ft_printf("LET's SEe whEre You StoP oR stARt _%-10Z_\n");
printf("LET's SEe whEre You StoP oR stARt _%-10Z_\n");
fflush(stdout);
printf("\nTEST\n");
fflush(stdout);
ft_printf("2_%10.5S_\n", L"엹ᄉ䆶");
printf("2_%10.5S_\n", L"엹ᄉ䆶");
fflush(stdout);*/
/*ft_printf("%lld\n", -9223372036854775808);
printf("TRUE : %d\n", printf("%lld\n", -9223372036854775808));
fflush(stdout);
ft_printf("%010y\n", 5482);
printf("TRUE : %d\n", printf("%010y\n", 5482));
fflush(stdout);*/

/*ft_printf("_%C_\n", L'米');
printf("TRUE : %d\n", printf("_%C_\n", L'米'));
fflush(stdout);
ft_printf("_%C_\n", NULL);
printf("TRUE : %d\n", printf("_%C_\n", NULL));
fflush(stdout);
ft_printf("%010S\n", L"ĝØĔᄉtestons䆶@");
printf("TRUE : %d\n", printf("%010S\n", L"ĝØĔᄉtestons䆶@"));
fflush(stdout);
ft_printf("%010S\n", NULL);
printf("TRUE : %d\n", printf("%010S\n", NULL));
fflush(stdout);
ft_printf("_%010C_\n", NULL);
printf("TRUE : %d\n", printf("_%010C_\n", NULL));
fflush(stdout);*/
	/*ft_printf("2_%#3.2x_\n", 0);
	printf(" _%#3.2x_\n", 0);
	fflush(stdout);
	ft_printf("3_%#4o_\n", 0);
	printf(" _%#4o_\n", 0);
	fflush(stdout);
	ft_printf("4_%#.0o_\n", 0);
	printf(" _%#.0o_\n", 0);
	fflush(stdout);
	ft_printf("4_%#.O_\n", 0);
	printf(" _%#.O_\n", 0);
	fflush(stdout);
	ft_printf("4_%#x_\n", 0);
	printf(" _%#x_\n", 0);
	fflush(stdout);
	ft_printf("5_%+3o_\n", 0);
	printf(" _%+3o_\n", 0);
	fflush(stdout);
	printf("\n");
	ft_printf("C_%#c_\n", 0);
	printf("C_%#c_\n", 0);
	fflush(stdout);
	ft_printf("_% s_\n", "salut \0 comment");
	printf("_%+s_\n", "salut \0 comment");
	fflush(stdout);
	printf("------- U ---------\n" );
	fflush(stdout);
	ft_printf("_%hU_\n", 4294967296);
	printf("_%hU_\n", 4294967296);
	fflush(stdout);*/
	/*printf("%hhC, %hhC\n", 0, L'米');
	fflush(stdout);*/
	/*ft_printf("UNiCode Try Out _%C_ %06C\n", 221, 200);
	printf("UNiCode Try Out _%C_ %06C\n", 221, 200);
	fflush(stdout);
	ft_printf("%zd\n", 4294967295);
	printf("%zd\n", 4294967295);
	fflush(stdout);*/
	ft_printf("%zd\n", 4294967296);
	printf("%zd\n", 4294967296);
	fflush(stdout);
	ft_printf("_%-5c_\n", 0);
	printf("_%-5c_\n", 0);
	fflush(stdout);
	ft_printf("_%0*d_\n", -15, 456);
	printf("_%0*d_\n", -15, 456);
	fflush(stdout);
	ft_printf("_%4.15s_\n", "42");
	printf("_%4.15s_\n", "42");
	fflush(stdout);
	ft_printf("_%.c_\n", 0);
	printf("_%.c_\n", 0);
	fflush(stdout);
	ft_printf("_%3*p_\n", 10, 0);
	printf("_%3*p_\n", 10, 0);
	fflush(stdout);
	//nbr_cmp();
	return (0);
}
