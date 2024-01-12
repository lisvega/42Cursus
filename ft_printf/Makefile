# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lisriver <lisriver@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 11:40:10 by lisriver          #+#    #+#              #
#    Updated: 2023/12/26 16:28:39 by lisriver         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRCS =      ft_printf.c\
			ft_basics.c\
			ft_hexadecimals.c\
			ft_pointers.c	

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -rf
 
CFLAGS = -Wall -Werror -Wextra

AR = ar crs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)		

re:	fclean all

.PHONY:	all clean fclean re
