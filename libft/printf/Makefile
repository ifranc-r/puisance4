# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/16 13:57:26 by qmerlot           #+#    #+#              #
#    Updated: 2016/02/22 15:38:45 by qmerlot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = printf.c put.c itoa.c flags.c fpm.c convs.c convd.c convb.c convw.c \
	  misc.c putw.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I ../includes -c $(SRC)
	
clean:
	/bin/rm -f $(OBJ)

re: clean all
