/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:04:06 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/01 18:23:23 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	nbr_cmp(void)
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
	char	*s1 = "___Salut le monde _% 011.215h16.25*.*h*.*d_%#15.12X___  LAST : %-15.5d+++\n", *s2 = "This is a sentence";
	char	*s3 = "TEST %lld %ld", *s4 = "_%-+*d_\n";
	char	*s5 = "_%20s_ petit test si possible\n", *s6 = "\n\n";

	setlocale(LC_ALL, "");
		printf("\n----------\nBASICS\n----------\n");
		fflush(stdout);

		ft_printf("%i\n", 0);
		printf("%i\n", 0);
		fflush(stdout);
		ft_printf("%d, %d\n", 245, -952);
		printf("%d, %d\n", 245, -952);
		fflush(stdout);
		ft_printf("%+i %+i % i % i\n", 321, -321, 321, -321);
		printf("%+i %+i % i % i\n", 321, -321, 321, -321);
		fflush(stdout);
		ft_printf("%10i\n", 12);
		printf("%10i\n", 12);
		fflush(stdout);
		printf("_%+ jd_\n", MAX_INT *4);
		fflush(stdout);
		ft_printf("_%+ jd_\n", MAX_INT*4);
		ft_printf("%+ d\n", 0);
		printf("%+ d\n", 0);
		fflush(stdout);
		printf("%+ d\n", -42);
		fflush(stdout);
		ft_printf("%+ d\n", -42);
		printf("%+ 20jd\n", MAX_INT *4);
		fflush(stdout);
		ft_printf("%+ 20jd\n", MAX_INT*4);
		ft_printf("%+ 20d\n", MIN_INT);
		printf("%+ 20d\n", MIN_INT);
		fflush(stdout);
		ft_printf("%+ 20d\n", 0);
		printf("%+ 20d\n", 0);
		fflush(stdout);
		ft_printf("%+ 20d\n", 42);
		printf("%+ 20d\n", 42);
		fflush(stdout);

		printf("\n----------\nPRECISION\n----------\n");
		fflush(stdout);

		ft_printf("%.12d\n", 42);
		printf("%.12d\n", 42);
		fflush(stdout);
		ft_printf("%.4d\n", 42);
		printf("%.4d\n", 42);
		fflush(stdout);
		ft_printf("%.4d\n", 424242);
		printf("%.4d\n", 424242);
		fflush(stdout);
		printf("{%.20d}\n", 42);
		fflush(stdout);
		ft_printf("{%.20d}\n", 42);
		ft_printf("{%-.20d}\n", 42);
		printf("{%-.20d}\n", 42);
		fflush(stdout);
		ft_printf("%.d, %.0d\n", 0, 0);
		printf("%.d, %.0d\n", 0, 0);
		fflush(stdout);
		ft_printf("@moulitest: %.d %.0d\n", 42, 43);
		printf("@moulitest: %.d %.0d\n", 42, 43);
		fflush(stdout);
		ft_printf("%.10d\n", -42);
		printf("%.10d\n", -42);
		fflush(stdout);
		printf("%+ .0jd\n", MAX_INT *4);
		fflush(stdout);
		ft_printf("%+ .0jd\n", MAX_INT*4);
		ft_printf("%+ .0d\n", MIN_INT);
		printf("%+ .0d\n", MIN_INT);
		fflush(stdout);
		ft_printf("%+ .0d\n", 0);
		printf("%+ .0d\n", 0);
		fflush(stdout);
		ft_printf("%+ .0d\n", -42);
		printf("%+ .0d\n", -42);
		fflush(stdout);

		printf("\n----------\nMFIELD\n----------\n");
		fflush(stdout);

		ft_printf("{%-10d}\n", 42);
		printf("{%-10d}\n", 42);
		fflush(stdout);
		ft_printf("{%010d}\n", -42);
		printf("{%010d}\n", -42);
		fflush(stdout);
		ft_printf("{%10d}\n", -42);
		printf("{%10d}\n", -42);
		fflush(stdout);
		ft_printf("{% 03d}\n", 0);
		printf("{% 03d}\n", 0);
		fflush(stdout);
		printf("{%0-3d}\n", 0);
		fflush(stdout);
		ft_printf("{%0-3d}\n", 0);
		printf("{%03d}\n", 0);
		fflush(stdout);
		ft_printf("{%03d}\n", 0);
		printf("{%020d}\n", 42);
		fflush(stdout);
		ft_printf("{%020d}\n", 42);
		ft_printf("{%-020d}\n", 42);
		printf("{%-020d}\n", 42);
		fflush(stdout);

		printf("\n----------\nMFIELD && PRECISION\n----------\n");
		fflush(stdout);

		printf("%15.4d\n", 42);
		fflush(stdout);
		ft_printf("%15.4d\n", 42);
		printf("%15.4d\n", 424242);
		fflush(stdout);
		ft_printf("%15.4d\n", 424242);
		printf("%15.4d\n", 4);
		fflush(stdout);
		ft_printf("%15.4d\n", 4);
		printf("{%10.5d}\n", 9);
		fflush(stdout);
		ft_printf("{%10.5d}\n", 9);
		printf("{%03.2d}\n", 9);
		fflush(stdout);
		ft_printf("{%03.2d}\n", 9);
		printf("{%03.5d}\n", 9);
		fflush(stdout);
		ft_printf("{%03.5d}\n", 9);
		printf("{%03.10d}\n", 9);
		fflush(stdout);
		ft_printf("{%03.10d}\n", 9);
		printf("{%03.2d}\n", 0);
		fflush(stdout);
		ft_printf("{%03.2d}\n", 0);
		printf("{%020.8d}\n", 42);
		fflush(stdout);
		ft_printf("{%020.8d}\n", 42);
		printf("{%020.5d}\n", 42);
		fflush(stdout);
		ft_printf("{%020.5d}\n", 42);
		printf("{%20.5d}\n", 42);
		fflush(stdout);
		ft_printf("{%20.5d}\n", 42);
		printf("{%015.20d}\n", 42);
		fflush(stdout);
		ft_printf("{%015.20d}\n", 42);
		printf("{%-020.8d}\n", 42);
		fflush(stdout);
		ft_printf("{%-020.8d}\n", 42);
		printf("{%-020.5d}\n", 42);
		fflush(stdout);
		printf("{%-020.5d}\n", 42);
		fflush(stdout);
		ft_printf("{%-20.5d}\n", 42);
		printf("{%-20.5d}\n", 42);
		fflush(stdout);
		ft_printf("{%-015.20d}\n", 42);
		printf("{%-015.20d}\n", 42);
		fflush(stdout);
		ft_printf("% 10.5d\n", 4242);
		printf("% 10.5d\n", 4242);
		fflush(stdout);
		ft_printf("%+10.5d\n", 4242);
		printf("%+10.5d\n", 4242);
		fflush(stdout);
		ft_printf("%10.5d\n", -4242);
		printf("%10.5d\n", -4242);
		fflush(stdout);
		ft_printf("%03.2d\n", -1);
		printf("%03.2d\n", -1);
		fflush(stdout);
		ft_printf("@moulitest: %5.d %5.0d\n", 0, 0);
		printf("@moulitest: %5.d %5.0d\n", 0, 0);
		fflush(stdout);

		printf("\n----------\nTHE 0 EXCEPTION\n----------\n");
		fflush(stdout);

		ft_printf("%.d\n", 0);
		printf("%.d\n", 0);
		fflush(stdout);
		ft_printf("%.0d\n", 0);
		printf("%.0d\n", 0);
		fflush(stdout);
		ft_printf("%.1d\n", 0);
		printf("%.1d\n", 0);
		fflush(stdout);
		ft_printf("%05d\n", 0);
		printf("%05d\n", 0);
		fflush(stdout);
		ft_printf("%25d\n", 0);
		printf("%25d\n", 0);
		fflush(stdout);
		ft_printf("% .d\n", 0);
		printf("% .d\n", 0);
		fflush(stdout);
		ft_printf("%03.d\n", 0);
		printf("%03.d\n", 0);
		fflush(stdout);
		ft_printf("%+3.d\n", 0);
		printf("%+3.d\n", 0);
		fflush(stdout);
		ft_printf("%+-8.d\n", 0);
		printf("%+-8.d\n", 0);
		fflush(stdout);
		ft_printf("%*.*d\n", 1, 0, 0);
		printf("%*.*d\n", 1, 0, 0);
		fflush(stdout);
		ft_printf("%+.1d\n", 0);
		printf("%+.1d\n", 0);
		fflush(stdout);
		ft_printf("5_%+-0 5.0jd_\n",0, 5,0,0);
		printf("5_%+-0 5.0jd_\n",0, 5,0,0);
		fflush(stdout);

		printf("\n----------\nFUNKY SHIT\n----------\n");
		fflush(stdout);

		ft_printf(s1, 10, 12, 45, 20, ex2, ex3, ex2);
		printf(s1, 10, 12, 45, 20, ex2, ex3, ex2);
		fflush(stdout);
		ft_printf(s5, s2);
		printf(s5, s2);
		fflush(stdout);
		ft_printf(s4, 5, 0);
		printf(s4, 5, 0);
		fflush(stdout);
		ft_printf("|#		'# + - 0 15 L d'		: _%#0+---hh--hhh-++++++0015d_\n", ex2);
		printf("|#		'# + - 0 15 L d'		: _%#0+---hh--hhh-++++++0015d_\n", ex2);
		fflush(stdout);
		ft_printf("|#		'pres 0'			: _%+++++10.15h-20.15hd__________\n", 123457);
		printf("|#		'pres 0'			: _%+++++10.15h-20.15hd__________\n", 123457);
		fflush(stdout);

		printf("\n----------\nSTRING STUFF\n----------\n");
		fflush(stdout);

		ft_printf("_%s_\n", "Salut les gens");
		printf("_%s_\n", "Salut les gens");
		fflush(stdout);
		ft_printf("_%.5s_\n", "Salut les gens");
		printf("_%.5s_\n", "Salut les gens");
		fflush(stdout);
		ft_printf("_%010s_\n", "Salut les gens");
		printf("_%010s_\n", "Salut les gens");
		fflush(stdout);
		ft_printf("_%0100.25s_\n", "Salut les gens");
		printf("_%0100.25s_\n", "Salut les gens");
		fflush(stdout);
		ft_printf("_%0100-.25s_\n", "Salut les gens");
		printf("_%0100-.25s_\n", "Salut les gens");
		fflush(stdout);
		ft_printf("_%0100hh-.25s_\n", "Salut les gens");
		printf("_%0100hh-.25s_\n", "Salut les gens");
		fflush(stdout);
		ft_printf("_%.25s_\n", "Salut les gens");
		printf("_%.25s_\n", "Salut les gens");
		fflush(stdout);
		ft_printf("_%-.25s_\n", "Salut les gens");
		printf("_%-.25s_\n", "Salut les gens");
		fflush(stdout);
		ft_printf("_%+.25s_\n", "Salut les gens");
		printf("_%+.25s_\n", "Salut les gens");
		fflush(stdout);
		ft_printf("_%25s_\n", "Salut les gens");
		printf("_%25s_\n", "Salut les gens");
		fflush(stdout);
		ft_printf("_%.0s_\n", "Salut les gens");
		printf("_%.0s_\n", "Salut les gens");
		fflush(stdout);
		ft_printf("_%0.35s_\n", "Salut les gens");
		printf("_%0.35s_\n", "Salut les gens");
		fflush(stdout);
		ft_printf("_%.s_\n", "Salut les gens");
		printf("_%.s_\n", "Salut les gens");
		fflush(stdout);
		ft_printf("_%035s_\n", "Salut les gens");
		printf("_%035s_\n", "Salut les gens");
		fflush(stdout);
		ft_printf("_%035.5s_\n", "Salut les gens");
		printf("_%035.5s_\n", "Salut les gens");
		fflush(stdout);
}
