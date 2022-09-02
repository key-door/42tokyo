# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 17:20:52 by kyoda             #+#    #+#              #
#    Updated: 2022/09/03 02:54:55 by kyoda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFTDIR = ./libft

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ../include/libft.h

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)


clean:
	make clean -C $(LIBFTDIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

# NAME		= printf.a
# SRC			= ft_printf.c
# OBJS		= $(SRC:.c=.o)
# CC 			= gcc
# CFLAGS		= -Wall -Wextra -Werror -I ../include/ft_printf.h

# all : $(NAME)

# $(NAME) : $(OBJS)
# 	ar rcs $(NAME) $^

# clean :
# 	$(RM) $(OBJS)

# fclean : clean
# 	$(RM) $(NAME)

# re : fclean all

# .PHONY : all clean fclean re
