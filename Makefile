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

NAME = libft.a
SRC =  main.c ft_strlen.c ft_memset.c ft_bzero.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT_DIR = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)
# delete + main.c + $(CC) -o 
%.o: %.c
	$(CC) -c $< -o $@
##
clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
