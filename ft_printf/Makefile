# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 17:20:52 by kyoda             #+#    #+#              #
#    Updated: 2022/09/03 10:26:20 by kyoda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFTDIR = ./libft

INCLUDEDIR = include/ft_printf.h

SRC = ft_printf.c ft_putstr.c ft_puthex.c ft_putnbr.c   ft_putptr.c   ft_putchr.c  ft_putnbr_u.c   

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
