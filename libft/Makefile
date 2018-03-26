# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:58:31 by mmanley           #+#    #+#              #
#    Updated: 2018/03/22 15:20:53 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = includes/

OBJ_INC = ../includes

OBJ_PATH = objs/

SRC_PATH = srcs/

SRC_L = lst_ch/

SRC_P = put/

SRC_S = strs/

SRC_M = mems/

SRC_N = nbrs/

RED = \x1b[31m

GREEN = \x1b[32m

include nbrs/make.dep
include mems/make.dep
include lst_ch/make.dep
include srcs/make.dep
include strs/make.dep
include put/make.dep

OBJS_NAME =	$(SRCS:%.c=%.o)

OBJS = $(addprefix $(OBJ_PATH), $(OBJS_NAME))

all : $(NAME)

$(NAME) : objs $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INC)

objs:
	@mkdir -p objs
	@mkdir -p objs/mems
	@mkdir -p objs/nbrs
	@mkdir -p objs/lst_ch
	@mkdir -p objs/strs
	@mkdir -p objs/srcs
	@mkdir -p objs/put

clean :
	@rm -rf objs
	@rm -rf $(OBJS_PATH)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
