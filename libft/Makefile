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

NAME = libft.a
BONUSNAME = libft.a

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
    ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c \
    ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
    ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
    ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
		
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
    ft_lstclear.c ft_lstiter.c ft_lstmap.c

HEADER = libft.h

CC = gcc

CFLAGS = -c -Wall -Werror -Wextra

RM = rm -f

AR = ar rcs

OBJ = $(SRCS:c=o)

BONUSOBJ = $(BONUS:c=o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(AR) $@ $(OBJ)

bonus: $(OBJ) $(BONUSOBJ)
	$(AR) $(NAME) $(OBJ) $(BONUSOBJ)

clean:
	$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all