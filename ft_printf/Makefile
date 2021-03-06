# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: student <ctora@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/07 08:49:49 by student           #+#    #+#              #
#    Updated: 2020/05/07 08:49:52 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_check_len.c ft_check_percsign.c ft_print_str.c ft_checker.c \
	ft_conv_str.c ft_dot.c ft_flag.c ft_flen.c ft_fnegative.c ft_fnums.c \
	ft_isdigit.c ft_points.c ft_print_char.c ft_print_hex.c ft_print_int.c \
	ft_print_uint.c ft_printf.c ft_putchar_fd.c ft_putchar.c ft_putstr_precision.c \
	ft_strdup.c ft_strlen.c ft_type.c ft_unsigned_itoa.c ft_unsignedll_check.c ft_tolower.c \
	ft_itoa.c ft_memcpy.c

CC = gcc

CFLAGS = -c -Wall -Werror -Wextra

RM = rm -f

AR = ar rcs

OBJ = $(SRCS:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all