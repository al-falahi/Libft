# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aal-fala <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/13 13:49:39 by aal-fala          #+#    #+#              #
#    Updated: 2025/04/13 13:49:39 by aal-fala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
#NAME = libft.a
#SRC =  main.c ft_strlen.c ft_memset.c ft_bzero.c
#OBJ = $(SRC:.c=.o)
#CC = cc
#CFLAGS = -Wall -Wextra -Werror
#RM = rm -f
#LIBFT_DIR = ./libft
#
#all: $(NAME)
#
#$(NAME): $(OBJ)
#	$(CC) -o $(NAME) $(OBJ)
## delete + main.c + $(CC) -o 
#%.o: %.c
#	$(CC) -c $< -o $@
###
#clean:
#	@$(RM) $(OBJ)
#
#fclean: clean
#	@$(RM) $(NAME)
#
#re: fclean all
#
#.PHONY: all clean fclean re

NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME) main.o
	$(CC) $(CFLAGS) -o main main.o libft.a

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	$(RM) $(OBJ) main.o

fclean: clean
	$(RM) $(NAME) main

re: fclean all

.PHONY: all clean fclean re test
