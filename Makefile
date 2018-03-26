# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 16:56:10 by mmanley           #+#    #+#              #
#    Updated: 2018/03/26 18:12:52 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJ_PATH = objs/

INC = libft/includes

SRCS =	chr_manager.c\
		flag_power.c\
		flags_pmss.c\
		ft_itoall.c\
		ft_printf.c\
		info_pars.c\
		nbr_manager.c\
		pars_check.c\
		buff_renderer.c\
		flags_chr.c\
		wchar_conv.c\
		bonus_part.c\
		bonus_binairy.c\

OBJS_NAME = $(SRCS:%.c=%.o)

OBJS = $(addprefix $(OBJ_PATH), $(OBJS_NAME))

all : $(NAME)

$(OBJ_PATH) :
	@if [ ! -d "objs" ]; then \
		mkdir objs;\
		fi

$(OBJS): |$(OBJ_PATH)

$(NAME) : $(OBJS)
	@make -C libft
	@cp libft/libft.a ./libftprintf.a
	@ar rc libftprintf.a $(OBJS)
	@ranlib libftprintf.a

$(OBJ_PATH)%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< -I $(INC)

run :
	@gcc -o ft_printf main.c libftprintf.a libft/libft.a -I $(INC) && ./ft_printf

clean :
	@cd libft/ && $(MAKE) clean && cd ..
	@rm -rf objs

fclean : clean
	@cd libft/ && $(MAKE) fclean && cd ..
	@rm -rf $(NAME)

re : fclean all
