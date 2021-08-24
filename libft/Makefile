# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rballage <rballage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 16:39:25 by rballage          #+#    #+#              #
#    Updated: 2020/09/13 22:40:22 by rballage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = src

SRC_NAME = ft_llitoa.c ft_lutoa.c ft_abs.c ft_isalnum.c ft_isdigit.c \
	ft_memcpy.c ft_strlcat.c ft_strncmp.c ft_toupper.c ft_atoi.c \
	ft_isalpha.c  ft_isprint.c ft_memset.c ft_strlcpy.c ft_strrchr.c \
	ft_bzero.c ft_isascii.c ft_memccpy.c ft_strchr.c ft_strlen.c \
	ft_tolower.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c \
	ft_strnstr.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c \
	ft_strdup.c ft_split.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstclear.c ft_lstmap.c ft_any.c ft_count_if.c ft_foreach.c \
	ft_is_prime.c ft_is_sort.c ft_map.c ft_mapn.c ft_memalloc.c \
	ft_putchar.c ft_putstr.c ft_sqrt.c ft_strcat.c ft_strclr.c \
	ft_strcpy.c ft_strdel.c ft_strequ.c ft_strjoinf.c ft_strncat.c \
	ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strrev.c ft_swap.c \
	ft_putchar.c ft_strcmp.c ft_memdel.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

HEADER_PATH = includes/

HEADER_NAME = libft.h

HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc  -Wall -Werror -Wextra -I $(HEADER_PATH) -MMD -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: make clean fclean re

-include $(OBJ:.o=.d)
