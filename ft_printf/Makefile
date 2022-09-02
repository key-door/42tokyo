# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 17:20:52 by kyoda             #+#    #+#              #
#    Updated: 2022/09/03 05:31:46 by kyoda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFTDIR = ./libft

INCLUDEDIR = include/ft_printf.h

SRC = ft_printf.c ft_pri_str.c

OBJS		= $(SRC:.c=.o)

CC 			= cc

CFLAGS		= -Wall -Wextra -Werror -I $(INCLUDEDIR)

all : $(NAME)

$(NAME) : $(OBJS)
	make bonus -C $(LIBFTDIR)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $^

clean :
	make clean -C $(LIBFTDIR)
	rm -f $(OBJS)

fclean : clean
	make fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
