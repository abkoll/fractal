# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoller <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 16:27:58 by akoller           #+#    #+#              #
#    Updated: 2018/09/03 22:25:15 by akoller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

FLAGS	= -Wall -Wextra -Werror

SRCS	= fractol_main.c\
		  fractol_rgbconversion.c\
		  fractol_move.c

OBJF	= $(SRCS:%.c=%.o)

INC		= ./fractol.h

LIBS	= includes/libft/libft.a\
		  includes/libmlx/libmlx.a

FRAMEWORKS	= -framework OpenGL -framework AppKit

all:	$(NAME)
	@gcc $(FLAGS) -o $(NAME) $(SRCS) -I$(INC) $(LIBS) $(FRAMEWORKS) -g

$(NAME):
	@make -C src/libft
	@make -C src/libmlx

clean:
	@/bin/rm -f rm $(OFILES)
	@make -C src/libft/ clean
	@make -C src/libmlx/ clean

fclean: clean
	@rm -f rm $(NAME)
	@make -C src/libft/ fclean
	@make -C src/libmlx/ fclean

re:	fclean all

.PHONY: fclean clean re
