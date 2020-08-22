# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalona <yalona@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/21 17:40:07 by yalona            #+#    #+#              #
#    Updated: 2020/08/22 17:05:37 by yalona           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g
GFLAGS = -lmlx -framework OpenGL -framework AppKit

HEA_PATH = ./Includes
HEA_NAME = fractol.h
HEA = $(addprefix $(HEA_PATH)/,$(HEA_NAME))

SRC_PATH = ./src
SRC_NAME = 	main.c utilites.c events.c julia.c mandelbrot.c draw.c \
						 burningship.c
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = ./src
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(HEA)
					@make -C libft/
					@$(CC) $(CFLAGS) $(OBJ) $(GFLAGS) libft/libft.a -o $(NAME)
					@echo "Fractol  OK."

%.o: 			%.c $(HEA)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@rm -rf $(OBJ)
					@make -C libft clean
					@echo "Object files deleted."

fclean: 			clean
					@make -C libft fclean
					@rm -rf $(NAME)
					@echo "__DELETED__"

re: 				fclean all

.PHONY: 			all clean fclean re
