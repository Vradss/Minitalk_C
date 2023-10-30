# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 20:16:12 by vflorez           #+#    #+#              #
#    Updated: 2023/10/30 22:22:46 by vflorez          ###   ########.fr        #
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

#Sources
SRC_DIR = src
SRC_CLIENT = src/client.c
SRC_SERVER = src/server.c

PRINTF = $(SRC_DIR)/Printf
LIBFT = $(SRC_DIR)/libft


#Compiler
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
LINKFLAGS = -L./$(LIBFT) -lft -L./$(PRINTF) -lftprintf

#Objects
OBJ_DIR = obj/
OBJ_CLIENT = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_CLIENT))
OBJ_SERVER = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_SERVER))


#Rules
all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : $(OBJ_CLIENT)
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(PRINTF)
	@$(CC) $(CFLAGS) $(LINKFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT)
	@echo "$(BLUE) $(NAME_CLIENT)--> Created & compiled 👀$(END)"

$(NAME_SERVER) : $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(LINKFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER)
	@echo "$(BLUE) $(NAME_SERVER)--> Created & compiled 👀$(END)"


$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I./includes -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN) All .o files deleted💀💀$(END)"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)
	@$(MAKE) fclean -C $(PRINTF)
	@rm -f $(NAME_CLIENT)
	@rm -f $(NAME_SERVER)
	@echo "$(BLUE) All clean $(END)"

re: fclean all

.PHONY: all clean fclean re