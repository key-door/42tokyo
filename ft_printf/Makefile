# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 17:20:52 by kyoda             #+#    #+#              #
#    Updated: 2022/08/31 17:23:58 by kyoda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRC			= 
OBJS		= $(SRC:.c=.o)
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror -I libft.h

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $^

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
