# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 20:16:12 by vflorez           #+#    #+#              #
#    Updated: 2023/10/30 16:10:49 by vflorez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors

RED 	= \033[0;91m
GREEN	= \033[1;92m
YELLOW	= \033[1;93m
BLUE	= \033[0;96m
ORANGE	= \033[0;33m
GRAY	= \033[0;90m


#Main
NAME_PROJECT = minitalk
NAME_CLIENT = client
NAME_SERVER = server 

#Compiler
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

#Sources
SRC = 	client.c\
		server.c

PRINTF =src/PRINTF
LIBFT = src/LIBFT


#Objects
OBJ = $(SRC:.c=.o)

#Rules
all: $(NAME_CLIENT) $(NAME_SERVER) 

$(NAME_CLIENT) : $(OBJ_CLIENT)
	@ar rcs $(NAME) $(OBJ)

%.o : %.c
	@gcc $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re