/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:43:57 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/19 17:08:01 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef T_U36
#  define T_U36		long long;
# endif

# include <stdio.h>
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>

enum {MINUS_L = 1, PLUS_LL = 2, HASH_J = 4, ZERO_Z = 8, DOT_H = 16,
	MFIELD_HH = 32, SPACE = 64, STOP_D = 128};

typedef	struct		s_info
{
	char			type;
	int			cmd_size;
	unsigned char	flags;
	unsigned char	conv;
	int				mfield;
	int				prec;
	int				nbr_l;
	int				nbr_h;
}					t_info;

int					data_init(t_info *data, char *s);
void				new_data(t_info **data);
char				*chr_manager(va_list **arg, t_info *data);
char				*nbr_manager(va_list **arg, t_info *data);
char				*flag_manager(t_info *data, char *s);
char				*ft_itoall(long long int n, int base, int size, int sign);
char				*ft_utoall(unsigned long long int n, int base, int size,
	int sign);

#endif
