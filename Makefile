# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/19 13:44:20 by vde-sain     #+#   ##    ##    #+#        #
#    Updated: 2018/11/29 13:40:46 by vde-sain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

SRC = main.c \
	  display.c \
	  fox_head.c \
	  colors.c \
	  creating_map.c \
	  finalizing_map.c \
	  key_management.c \
	  shading_colors.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/

MINILIBX = ./minilibx_macos/

LIBFT.A = ./libft/libft.a

MINILIBX.A = ./minilibx_macos/libmlx.a

FRAMEWORKS = -framework OpenGL -framework AppKit

all : libs $(NAME)

$(NAME): $(OBJ) $(LIBFT.A) $(MINILIBX.A)
		@$(CC) -o $(NAME) $(OBJ) $(LIBFT.A) $(MINILIBX.A) $(FRAMEWORKS)
		@echo "\033[1;32mFDF				OK\033[0m"

libs:
		@(cd $(LIBFT) && $(MAKE))
		@(cd $(MINILIBX) && $(MAKE))

%.o: %.c fdf.h
		@$(CC) $(FLAGS) -I. -c $(SRC)

clean:
		@rm -f $(OBJ)
		@rm -f *.gch
		@(cd $(LIBFT) && $(MAKE) $@)
		@(cd $(MINILIBX) && $(MAKE) $@)
		@echo "\033[1;31mCLEAN FDF			OK\033[0m"

fclean: clean
		@rm -f $(NAME)
		@(cd $(LIBFT) && $(MAKE) $@)
		@echo "\033[1;31mFCLEAN FDF			OK\033[0m"

re: fclean all

.PHONY : all clean fclean re
