# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 17:34:31 by vde-sain     #+#   ##    ##    #+#        #
#    Updated: 2018/11/22 12:49:50 by vde-sain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_bzero.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_isdigit.c \
	  ft_isalpha.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_strchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strrchr.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putnbr.c \
	  ft_putendl.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strsplit.c \
	  ft_strdel.c \
	  ft_itoa.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_putnstrn.c \
	  ft_strndup.c \
	  ft_isblank.c \
	  ft_isupper.c \
	  ft_list_last.c \
	  ft_range.c \
	  get_next_line.c \
	  ft_abs.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@ar rcs $(NAME) $(OBJ)
		@ranlib $(NAME)

%.o: %.c
		@gcc -c -Wall -Werror -Wextra -I. $(SRC)
		@echo "\033[1;32mLIBFT				OK\033[0m"

clean:
		@rm -f *.o
		@echo "\033[1;31mCLEAN LIBFT			OK\033[0m"

fclean: clean
		@rm -f $(NAME)
		@echo "\033[1;31mFCLEAN LIBFT			OK\033[0m"

re: fclean all
