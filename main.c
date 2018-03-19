/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:42:46 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/19 19:16:48 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		main()
{
	/*short	shrt = 58, sht2 = 6659;
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
	char	*s5 = "_%20s_ petit test si possible\n", *s6 = "\n\n";*/

//ft_printf("|#		'# + - 0 15 L d'		: _%#0+---hh--hhh-++++++0015d_\n", ex2);

//printf("1_%-15.10t_____________ %12d salut\n", 10);
//ft_printf("2_%-15.10t_ %12d salut\n", 10);
/*printf("1_%-15.10#+y_ %12d salut\n", 10);
ft_printf("2_%-15.10#+y_ %12d salut\n", 10);*/
/*printf(s1, 10, 12, 45, 20, ex2, ex3, ex2, s5);
ft_printf(s1, 10, 12, 45, 20, ex2, ex3, ex2, s5);
*/
//setlocale(LC_ALL, "");

/*ft_printf("LET's SEe whEre You StoP oR stARt _%+10Z_\n");
printf("LET's SEe whEre You StoP oR stARt _%+10Z_\n");
fflush(stdout);*/
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
	/*ft_printf("%zd\n", 4294967296);
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
	fflush(stdout);*/
	/*ft_printf("_%2.000007c_\n", 55);
	printf("_%2.000007c_\n", 55);
	fflush(stdout);
	ft_printf("_%.0p_, _%.p_\n", 0, 0);
	printf("_%.0p_, _%.p_\n", 0, 0);
	ft_printf("");
	printf("%d\n", ft_printf(""));
	printf("");
	printf("%d\n", printf(""));
	//ft_printf("%");
	printf("%");
	printf("%d", printf("%"));
	ft_printf("%d", ft_printf("%"));
	printf("%d", printf("%"));
	ft_printf("%#.3o\n", 55896);
	printf("%#.3o\n", 55896);
	ft_printf("% p|%+p\n", 42, 421256);
	printf("% p|%+p\n", 42, 421256);
	ft_printf("%s\n", "salut test");
	printf("%s\n", "salut test");
	ft_printf("_%#-25.20u_\n", lngl);
	printf("_%#-25.20u_\n", lngl);
	fflush(stdout);
	ft_printf("_%25.20p_\n", s1);
	printf("_%25.20p_\n", s1);
	fflush(stdout);
	ft_printf("P TEST _%#-25.20p_\n", s1);
	printf("P TEST _%#-25.20p_\n", s1);
	fflush(stdout);
	ft_printf("_%-.20p_\n", s1);
	printf("_%-.20p_\n", s1);
	fflush(stdout);
	ft_printf("LET's SEe whEre You StoP oR stARt _%012 po 154\n", 154);
	printf("LET's SEe whEre You StoP oR stARt _%012 po 154\n", 154);
	fflush(stdout);
	ft_printf("PB _%#10p_\n", s1);
	printf("PB _%#10p_\n", s1);
	fflush(stdout);
	ft_printf("PB0 _%#015.1p_\n", s1);
	printf("PB0 _%#015.1p_\n", s1);
	fflush(stdout);
	ft_printf("PB _%#015p_\n", s1);
	printf("PB _%#015p_\n", s1);
	fflush(stdout);
	ft_printf("PB2 _%#015.12p_\n", s1);
	printf("PB2 _%#015.12p_\n", s1);
	fflush(stdout);
	ft_printf("_%#-25.20x_\n", 1256);
	printf("_%#-25.20x_\n", 1256);
	fflush(stdout);
	ft_printf("_%#-25.20X_\n", 256398);
	printf("_%#-25.20X_\n", 256398);
	fflush(stdout);
	ft_printf("_%#-25.20hlx_\n", 4294967296);
	printf("_%#-25.20hlx_\n", 4294967296);
	fflush(stdout);
	ft_printf("_%#-25.20lx_\n", 0);
	printf("_%#-25.20lx_\n", 0);
	fflush(stdout);
	ft_printf("_%#25.20lx_\n", -4294967296);
	printf("_%#25.20lx_\n", -4294967296);
	fflush(stdout);
	ft_printf("_% 5#o_\n", 2569);
	printf("_% 5#o_\n", 2569);
	fflush(stdout);
	ft_printf("_%#015X_\n", 1258);
	printf("_%#015X_\n", 1258);
	fflush(stdout);
	ft_printf("_%#015o_\n", 1258);
	printf("_%#015o_\n", 1258);
	fflush(stdout);
	ft_printf("_%12.6o_\n", 1258);
	printf("_%#12.6o_\n", 1258);
	fflush(stdout);
	ft_printf("_%#3.2x_\n", 0);
	printf("_%#3.2x_\n", 0);
	fflush(stdout);
	ft_printf("_%#4o_\n", 0);
	printf("_%#4o_\n", 0);
	fflush(stdout);
	ft_printf("_%#.0o_\n", 0);
	printf("_%#.0o_\n", 0);
	fflush(stdout);
	//ft_printf("%s, %s\n", "test", "test");
	ft_printf("_%5.0Z_\n");
	printf("_%5.0Z_\n");
	fflush(stdout);
	ft_printf("%");
	printf("%");
	fflush(stdout);
	ft_printf("%lld\n", -92233720368547758);
	printf("%lld\n", -92233720368547758);
	fflush(stdout);
	ft_printf(NULL);
	ft_printf("_%10c_\n", NULL);
	printf("_%10c_\n", NULL);
	fflush(stdout);
	//printf("%d\n", printf(NULL));

	ft_printf("_%10c_testing\n", NULL);
	printf("_%10c_testing\n", NULL);
	fflush(stdout);
	ft_printf("_%ld_\n", 123456);
	printf("_%ld_\n", 123456);
	fflush(stdout);*/
	wchar_t	s[4];
	s[0] = 0x053;
s[1] = 0x11ffff;
s[2] = 'b';
s[3] = '\0';

/*	0000— 001F		4E00— 9FFF		A000— A48F*/

//printf("%d\n", printf("MTEST------%C-\n", L'z'));


//	printf("%d\n", ft_printf("M- %C-\n", L'a'));
	/*printf("%d\n", printf("O- %C-\n", L'a'));
	fflush(stdout);*/

	//printf("%d\n", ft_printf("M----%C-\n", 0xbffe));
	/*printf("%d\n", printf("O----%C-\n", 0xbffe));
	fflush(stdout);*/

//	printf("%d\n", ft_printf("M-----%C-\n", 254));
	/*printf("%d\n", printf("O-----%C-\n", 254));
	fflush(stdout);*/

/*	printf("%d\n", ft_printf("-%-10.2ls-\n", L"〻 "));
	printf("%d\n", printf("-%-10.2ls-\n", L"〻 "));*/
	/*printf("%d\n", printf("O-------%C-\n", 0x0002));
	fflush(stdout);*/

	/*printf("%d\n", ft_printf("_%8C_ et coco +%C_ titi =%lc_\n", 3250, 0x11ffff, 'a'));
	printf("%d\n", printf("_%8C_ et coco +%C+ titi =%lc_\n", 3250, 0x11ffff, 'a'));
	fflush(stdout);
	printf("\n");*/

	/*printf("%d\n", ft_printf("NOX%ls-\n", s));
	printf("%d\n", printf("NOX%ls-\n", s));
	fflush(stdout);*/

	/*printf("%d\n", printf("MTEST------%C-\n", 0x4DFF));
	printf("%d\n", printf("O-------%C-\n", 0x9FFF));
	fflush(stdout);

	printf("%d\n", printf("M------%C-\n", 0xA097));
	printf("%d\n", printf("O-------%C-\n", 0xA097));
	fflush(stdout);

	int ret = printf("%C\n", 0x4215);
	printf("%d\n", ret);
	fflush(stdout);

	printf("%d\n", printf("M-------%C-\n", 0xA097));
	printf("%d\n", printf("O-------%C-\n", 0xA097));
	fflush(stdout);*/
	//printf("%C\n", (wint_t)-2);
	/*ft_printf("UNiCode Try Out _%d_ %06d\n", 50, 52);
	printf("UNiCode Try Out _%d_ %06d\n", 50, 52);
	fflush(stdout);
	ft_printf("UNiCode Try Out _%C_ %06C\n", 3209, 32080);
	printf("UNiCode Try Out _%C_ %06C\n", 3209, 32080);
	fflush(stdout);
	ft_printf("UNiCode Try Out _%C_ %06C\n", 221, 200);
	printf("UNiCode Try Out _%C_ %06C\n", 221, 200);
	fflush(stdout);
	ft_printf("TWO ENORMOUS UNICODE _%.6C_ %-015C\n", 41622, 38886);
	printf("TWO ENORMOUS UNICODE _%.6C_ %-015C\n", 41622, 38886);
	fflush(stdout);
	ft_printf("BIG UNICODE _%+-*.*C_ %7C\n", 10, 5, 254, 41959);
	printf("BIG UNICODE _%+-*.*C_ %7C\n", 10, 5, 254, 41959);
	fflush(stdout);
	ft_printf("TWO ENORMOUS UNICODE _%.6C_ %-015C\n", 41622, 0x01012F);
	printf("TWO ENORMOUS UNICODE _%.6C_ %-015C\n", 41622, 0x01012F);
	fflush(stdout);
	ft_printf("TWO ENORMOUS UNICODE _%.6C_ %-015C\n", 0x011A9, 0x01012F);
	printf("TWO ENORMOUS UNICODE _%.6C_ %-015C\n", 0x011A9, 0x01012F);
	fflush(stdout);
	ft_printf("TWO ENORMOUS UNICODE Small prec_%.6C_ %-015C\n", 0x100259, 0x0110AF);
	printf("TWO ENORMOUS UNICODE Small prec_%.6C_ %-015C\n", 0x100259, 0x0110AF);
	fflush(stdout);
	ft_printf("TWO ENORMOUS UNICODE _%018#C_ %-015C\n", 0x031A9, 0x07A12F);
	printf("TWO ENORMOUS UNICODE _%018#C_ %-015C\n", 0x031A9, 0x07A12F);
	fflush(stdout);
	ft_printf("TWO ENORMOUS UNICODE Small prec_%3.0C_ _%-015C_\n", 0x0110AF, 0x0112AF);
	printf("TWO ENORMOUS UNICODE Small prec_%3.0C_ _%-015C_\n", 0x0110AF, 0x0112AF);
	fflush(stdout);
	ft_printf("_%S_\n", L"ĝØĔᄉ䆶");
	printf("_%S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%10S_\n", L"ĝØĔᄉ䆶");
	printf("_%10S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%-10S_\n", L"ĝØĔᄉ䆶");
	printf("_%-10S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("T_% 10S_\n", L"ĝØĔᄉ䆶");
	printf("T_% 10S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%010S_\n", L"ĝØĔᄉ䆶");
	printf("_%010S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%+10S_\n", L"ĝØĔᄉ䆶");
	printf("_%+10S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%25S_\n", L"ĝØĔᄉ䆶");
	printf("_%25S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%-25S_\n", L"ĝØĔᄉ䆶");
	printf("_%-25S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_% 25S_\n", L"ĝØĔᄉ䆶");
	printf("_% 25S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%025S_\n", L"ĝØĔᄉ䆶");
	printf("_%025S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%+25S_\n", L"ĝØĔᄉ䆶");
	printf("_%+25S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%10.5S_\n", L"ĝØĔᄉ䆶");
	printf("_%10.5S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%-10.6S_\n", L"ĝØĔᄉ䆶");
	printf("_%-10.6S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_% 10.3S_\n", L"ĝØĔᄉ䆶");
	printf("_% 10.3S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%010.7S_\n", L"ĝØĔᄉ䆶");
	printf("_%010.7S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%+10.8S_\n", L"ĝØĔᄉ䆶");
	printf("_%+10.8S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%10.15S_\n", L"ĝØĔᄉ䆶");
	printf("_%10.15S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%S_\n", L"ĝØĔᄉ䆶");
	printf("_%S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%10S_\n", L"긙ᄉᄉĔᄉ䆶");
	printf("_%10S_\n", L"긙ᄉᄉĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%-10S_\n", L"ĝØĔᄉ䆶");
	printf("_%-10S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%10.5S_\n", L"엹ᄉ䆶");
	printf("_%10.5S_\n", L"엹ᄉ䆶");
	fflush(stdout);
	ft_printf("_%S_\n", L"ĝØĔᄉ䆶");
	printf("_%S_\n", L"ĝØĔᄉ䆶");
	fflush(stdout);
	ft_printf("_%10S_\n", L"긙aᄉbᄉcĔᄉd䆶e");
	printf("_%10S_\n", L"긙aᄉbᄉcĔᄉd䆶e");
	fflush(stdout);
	ft_printf("_%-10S_\n", L"ĝØĔᄉtestons䆶@");
	printf("_%-10S_\n", L"ĝØĔᄉtestons䆶@");
	fflush(stdout);*/
	/*ft_printf("\n");
ft_printf("%%\n");
ft_printf("%d\n", 42);
ft_printf("%d%d\n", 42, 41);
ft_printf("%d%d%d\n", 42, 43, 44);
ft_printf("%ld\n", 2147483647);
ft_printf("%lld\n", 9223372036854775807);
ft_printf("%x\n", 505);
ft_printf("%X\n", 505);
ft_printf("%p\n", &ft_printf);
ft_printf("%20.15d\n", 54321);
ft_printf("%-10d\n", 3);
ft_printf("% d\n", 3);
ft_printf("%+d\n", 3);
ft_printf("%010d\n", 1);
ft_printf("%hhd\n", 0);
ft_printf("%jd\n", 9223372036854775807);
ft_printf("%zd\n", 4294967295);
ft_printf("%\n");
ft_printf("%U\n", 4294967295);
ft_printf("%u\n", 4294967295);
ft_printf("%o\n", 40);
ft_printf("%%#08x\n", 42);
ft_printf("%x\n", 1000);
ft_printf("%#X\n", 1000);
ft_printf("%s\n", NULL);
ft_printf("%S\n", L"ݗݜशব");
ft_printf("%s%s\n", "test", "test");
ft_printf("%s%s%s\n", "test", "test", "test");
ft_printf("%C\n", 15000);
	ft_printf("_%10.5S_\n", L"salut 엹ᄉ䆶 ca va 엡");
	printf("_%10.5S_\n", L"salut 엹ᄉ䆶 ca va 엡");
	fflush(stdout);
	ft_printf("_%C_ _%C_ _%C_\n", 0x53, 0x3abcD, 0x81000);
	printf("_%C_ _%C_ _%C_\n", 0x53, 0x3abcD, 0x81000);
	fflush(stdout);
	ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi\n", 125, 124, 256);
	printf("%-+-12.7Dt%0 4i %04.2% et %lc titi\n", 125, 124, 256);*/

			/*ft_printf("_%05d_\n", 0);
			printf("_%05d_\n", 0);
			fflush(stdout);*/

			/*ft_printf("_%5.0d_\n", 0);
			printf("_%5.0d_\n", 0);
			fflush(stdout);

			ft_printf("_%+1.0d_\n", 0);
			printf("_%+1.0d_\n", 0);
			fflush(stdout);*/

			//ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi\n", 125, 124, 256);
			//printf("%-+-12.7Dt%0 4i %04.2% et %lc titi\n", 125, 124, 256);
			char **tab;
			tab = ft_newtab(8, 12, 'c');

			ft_printf("YoBin : _%589 - 0.36t_\n", tab);
			ft_printf("YoBin : _%055hb_\n", 245698);
	//nbr_cmp();
	//basics();
	return (0);
}
