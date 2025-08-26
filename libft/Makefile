# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 14:40:23 by chpasqui          #+#    #+#              #
#    Updated: 2025/08/26 14:25:08 by chpasqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra
CC = cc

#Source files for the library
SRC_CHECK = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
SRC_STR = ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c \
		  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c ft_strdup.c \
		  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		  ft_striteri.c		  
SRC_MEM = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
		  ft_memcmp.c ft_calloc.c 
SRC_WRITE = ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
SRC_PRINTF = ft_printf.c print_hex.c print_pointer.c print_put.c
SRC_GNL = GNL_cub3d.c

SRCS = $(SRC_CHECK) $(SRC_STR) $(SRC_MEM) $(SRC_WRITE) $(SRC_BONUS) $(SRC_PRINTF) $(SRC_GNL)

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean :
	@echo "Objects files removed"
	@rm -f $(OBJ)
	
fclean : clean
	@echo "Library removed"
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus