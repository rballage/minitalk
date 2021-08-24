# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rballage <rballage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 16:39:25 by rballage          #+#    #+#              #
#    Updated: 2020/09/14 10:04:08 by rballage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = src

SRC_NAME =  handle_c.c \
			handle_d.c \
			handle_d_h.c \
			handle_d_hh.c \
			handle_d_l.c \
			handle_d_ll.c \
			handle_f.c \
			handle_f_l_maj.c \
			handle_null.c \
			handle_o.c \
			handle_o_h.c \
			handle_o_hh.c \
			handle_o_l.c \
			handle_o_ll.c \
			handle_p.c \
			handle_percent.c \
			handle_s.c \
			handle_u.c \
			handle_u_h.c \
			handle_u_hh.c \
			handle_u_l.c \
			handle_u_ll.c \
			handle_x.c \
			handle_x_h.c \
			handle_x_h_maj.c \
			handle_x_hh.c \
			handle_x_hh_maj.c \
			handle_x_l.c \
			handle_x_l_maj.c \
			handle_x_ll.c \
			handle_x_ll_maj.c \
			handle_x_maj.c \
			set_field.c \
			set_minus.c \
			set_plus.c \
			set_precision.c \
			set_sharp.c \
			set_space.c \
			set_zero.c \
			ft_baselen.c \
			search_setters.c \
			attribute_check.c \
			attributes_copy.c \
			attributes_calculs.c \
			calcul_min_field.c \
			calcul_neg_min_field.c \
			calcul_plus.c \
			calcul_precision.c \
			calcul_sharp.c \
			check_casts.c \
			check_casts_llhh.c \
			conv_hexa.c \
			conv_octal.c \
			ft_ftoa.c \
			ft_printf.c \
			list.c

CPPFLAGS = -I libft/includes/ -MMD

CC = gcc

CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj

DFLAGS =

HEADER_PATH = includes/

HEADER_NAME = ft_printf.h

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft/
	cp libft/libft.a ./$(NAME)
	ar rcs $@ $^
	ranlib $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(DFLAGS) $(CPPFLAGS) -I $(HEADER_PATH) -o $@ -c $<

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

clean:
	make clean -C libft/
	rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
	rm -f libft.a

re: fclean
	$(MAKE) all

bonus: $(NAME)

.PHONY: make clean fclean re

-include $(OBJ:.o=.d)
