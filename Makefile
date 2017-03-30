# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sescolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/13 09:59:58 by sescolas          #+#    #+#              #
#    Updated: 2017/02/28 18:32:25 by sescolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

OBJS = ft_atoi.o ft_bzero.o ft_isalnum.o ft_countwords.o ft_isalpha.o \
	   ft_isascii.o ft_isdigit.o ft_isprime.o ft_isprint.o ft_itoa.o \
	   ft_lstadd.o ft_exp.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o \
	   ft_lstmap.o ft_lstnew.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
	   ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_numlen.o \
	   ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o \
	   ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_sqrt.o ft_strcat.o \
	   ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o \
	   ft_strdup.o ft_strequ.o ft_strfind.o ft_striter.o ft_striteri.o \
	   ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o \
	   ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o \
	   ft_strnstr.o ft_strrchr.o ft_strrev.o ft_strsplit.o ft_strstr.o \
	   ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o get_next_line.o \
	   ft_padstr.o ft_padnbr.o

SRCS = 	*\.c

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rc $@ *.o
	ranlib $@

$(OBJS): $(SRCS) $(HEADER)

.PHONY: clean fclean re

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
