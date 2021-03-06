NAME = libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra -g

SRCS = ft_isblank.c ft_isspace.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_lstnew.c\
	ft_lstsize.c ft_calloc.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_memset.c\
	ft_bzero.c ft_memcpy.c ft_substr.c ft_memcmp.c ft_atoi.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_strlen.c ft_strcpy.c ft_strlcpy.c ft_strchr.c \
	ft_strdup.c ft_strjoin.c ft_split.c ft_strnstr.c get_next_line.c

HEADER = libft.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

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