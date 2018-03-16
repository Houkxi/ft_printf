# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 16:56:10 by mmanley           #+#    #+#              #
#    Updated: 2018/03/16 12:55:18 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJ_PATH = objs/

INC = ~/libft/includes

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

OBJS_NAME = $(SRCS:%.c=%.o)

OBJS = $(addprefix $(OBJ_PATH), $(OBJS_NAME))

all : $(NAME)

$(OBJ_PATH) :
	@if [ ! -d "objs" ]; then \
	mkdir objs;\
	fi

$(OBJS): |$(OBJ_PATH)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< -I $(INC)

run :
	@gcc -o ft_printf main.c checks/nbr_check.c libftprintf.a ~/libft/libft.a -I $(INC) && ./ft_printf

clean :
	@rm -rf objs

fclean : clean
	@rm -rf $(NAME)
	@rm ft_printf
	@echo "Wanted files deleted : .a & .o"

re : fclean all
