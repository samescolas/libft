# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sescolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/13 09:59:58 by sescolas          #+#    #+#              #
#    Updated: 2017/05/23 17:03:52 by sescolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRCS = 	$(wildcard *.c)

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -I ../includes

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rc $@ *.o
	ranlib $@

$(OBJS): $(SRCS) $(HEADER)

.PHONY: clean fclean re

print: $(SRCS)
	lpr -p $?
	touch print

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
