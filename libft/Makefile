# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/29 19:39:57 by qmerlot           #+#    #+#              #
#    Updated: 2016/02/24 19:05:12 by qmerlot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	  ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	  ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	  ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	  ft_isprint.c ft_toupper.c ft_tolower.c ft_isspace.c ft_strnew.c \
	  ft_memalloc.c ft_memdel.c ft_strdel.c ft_strclr.c ft_striter.c \
	  ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
	  ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
	  ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	  ft_strndup.c get_next_line.c ft_atoi_long.c

OBJ = $(SRC:.c=.o)

PRINTF = printf
PRINTFSRC = printf.c put.c itoa.c flags.c fpm.c convs.c convd.c convb.c convw.c \
			misc.c putw.c

PRINTFOBJ = $(PRINTFSRC:.c=.o)
PRINTFOBJS = $(addprefix $(PRINTF)/, $(PRINTFOBJ))

all: $(NAME)

$(NAME) :
	make -C $(PRINTF)/ re
	$(CC) $(CFLAGS) -I ./includes -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ar rc $(NAME) $(PRINTFOBJS)
	make -C $(PRINTF)/ clean
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

doclean : re
	/bin/rm -f $(OBJ)
