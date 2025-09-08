# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 11:16:43 by chpasqui          #+#    #+#              #
#    Updated: 2025/09/08 19:02:35 by Charlye          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Noms, compilateur et flags
NAME = cub3d
CC = cc
#FLAGS = -Wall -Wextra -Werror
FLAGS = -Wall -Wextra

#Dossiers
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/

#Module
SRC_MAIN	= 		main.c errors.c free.c
SRC_INIT	=		init/init_game.c init/init_mlx.c\
					init/init_texture.c init/init_player.c
SRC_PARSING =		parsing/parse_arg.c parsing/parse_file.c\
					parsing/parse_identifier.c\
					parsing/parse_grid.c parsing/valid_identifier.c\
					parsing/parse_grid_tool.c
SRC_RAYCASTING	=	raycasting/ray_init.c raycasting/ray_dda.c
SRC_RENDER	=		rendering/render_minimap.c\
					rendering/render.c rendering/render_logo.c\
					rendering/render_wall.c rendering/render_ceiling_floor.c
SRC_EVENTS	=		events/hook.c events/key.c events/move_map.c
SRC_UTILS	=		utils/trim.c utils/other.c utils/debug.c

SRC = $(SRC_MAIN) $(SRC_PARSING) $(SRC_UTILS) $(SRC_INIT) $(SRC_RAYCASTING) $(SRC_RENDER) $(SRC_EVENTS)
SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

#Minilibx
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX_DIR = minilibx-linux/
	MLX_FLAGS = -lmlx -lXext -lX11 -lm

else
	MLX_DIR = minilibx_opengl/
	MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lz
endif

MLX = $(MLX_DIR)libmlx.a

#Libft
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_FLAGS = -lft

#Couleurs
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m
RESET = \033[0m


# ************************************************************************************
#										RULES
# ************************************************************************************

all : $(NAME)

# Compilation of minilibx
$(MLX) :
	@echo "$(BLUE) Making MiniLibX...$(RESET)"
	@$(MAKE) --no-print-directory -C $(MLX_DIR) > /dev/null 2>&1
	@echo "$(GREEN) MiniLibx made! $(RESET)"

# Compilation of Libft
$(LIBFT) :
	@echo "$(BLUE) Making Libft... $(RESET)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@echo "$(GREEN) Libft made! $(RESET)"

#Compilation of cub3d
$(NAME) : $(OBJ) $(MLX) $(LIBFT)
	@echo "$(BLUE)→ Linking $(NAME)...$(RESET)"
	@$(CC) $(OBJ) -L$(INC_DIR) -L$(MLX_DIR) $(MLX_FLAGS) -L$(LIBFT_DIR) $(LIBFT_FLAGS) -o $(NAME)
	@echo "$(GREEN)✔ Build finished: $(NAME)$(RESET)"

#Compilation objects files avec header MLX et LIBFT
$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean :
	@echo "Object files removed"
	@rm -rf $(OBJ_DIR)
	@echo "Cleaning Libft..."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean > /dev/null
	@echo "Cleaning MiniLibX..."
	@$(MAKE) --no-print-directory -C $(MLX_DIR) clean > /dev/null

fclean : clean
	@echo "Program removed"
	@rm -f $(NAME)
	@echo "Full clean for Libft..."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean > /dev/null
	@echo "Full clean for MiniLibX..."
	@rm -f $(MLX_DIR)libmlx.a

re : fclean all

.PHONY : all clean fclean re
