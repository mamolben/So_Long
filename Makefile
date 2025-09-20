# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/22 16:08:20 by marimoli          #+#    #+#              #
#    Updated: 2025/05/21 18:38:52 by marimoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
#Flags de compilación
CFLAGS = -Wall -Wextra -Werror -I./includes -I./minilibx -g 
#Flags enlace
LDFLAGS = -L./minilibx -lmlx -lX11 -lXext -lbsd -lm
#Directorio de código fuente y objeto
SRC_DIR = src
OBJ_DIR = obj
#Directorio fuente y objeto
SRC = $(wildcard $(SRC_DIR)/*.c)
#OBJ = $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ) 
	@echo "Enlazando ejecutable: $@"
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compilando: $<"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
