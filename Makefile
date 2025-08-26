# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 11:16:43 by chpasqui          #+#    #+#              #
#    Updated: 2025/08/26 13:55:02 by chpasqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
SRC = main.c errors.c free.c init.c parsing/parse_arg.c parsing/parse_file.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INC_DIR = includes/

#Minilibx
MLX_DIR = minilibx-linux/
MLX = $(MLX_DIR)libmlx.a 
MLX_FLAGS = -lmlx -lXext -lX11 -lm

#Libft
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_FLAGS = -lft

all : $(NAME)

# Compilation of minilibx
$(MLX) :
	@echo "Making MiniLibX..."
	@$(MAKE) -C $(MLX_DIR) all
	@echo "MiniLibx made!"

# Compilation of Libft
$(LIBFT) :
	@echo "Making Libft..."
	@$(MAKE) -C $(LIBFT_DIR) all
	@echo "Libft made!"

#Compilation of cub3d
$(NAME) : $(OBJ) $(MLX) $(LIBFT)
	$(CC) $(OBJ) -L$(INC_DIR) -L$(MLX_DIR) $(MLX_FLAGS) -L$(LIBFT_DIR) $(LIBFT_FLAGS) -o $(NAME)

#Compilation objects files avec header MLX et LIBFT
$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean :
	@echo "Object files removed"
	@rm -rf $(OBJ_DIR)
	@echo "Cleaning Libft..."
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Cleaning MiniLibX..."
	@$(MAKE) -C $(MLX_DIR) clean

fclean : clean
	@echo "Program removed"
	@rm -f $(NAME)
	@echo "Full clean for Libft..."
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Full clean for MiniLibX..."
	@rm -f $(MLX_DIR)libmlx.a 

re : fclean all

.PHONY : all clean fclean re