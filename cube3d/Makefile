NAME = cub3D

SRCS_DIR = game/
OBJS_DIR = compiled/
HEADER_BIT = -L ft_screenshot.h
HEADER_CUB = -L ft_cub3d.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

#MLX = -L minilibx_opengl -lmlx -framework OpenGL -framework AppKit
MLX = -L minilibx-linux -lmlx -L /usr/include/../lib -lXext -lX11 -lm -lbsd
LIB = -L libft -lft

SRCS = ft_lstfreeman.c ft_cub3d.c ft_mcparser.c ft_map.c ft_exiter.c ft_render.c ft_params.c  \
	ft_pixelputter.c ft_checker.c ft_texture.c ft_raycasting.c ft_sprite.c ft_clr.c \
	ft_screenshot.c

OBJS = $(SRCS:c=o)

all: $(NAME)

$(NAME): $(OBJS)
	#make -C minilibx_opengl
	make -C minilibx-linux
	make -C libft
	$(CC) -o $(NAME) $(HEADER_BIT) $(HEADER_CUB) $(OBJS) $(LIB) $(MLX)

$(OBJS): %.o : %.c
	$(CC) $(FLAGS) $(HEADER_BIT) $(HEADER_CUB) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	rm -rf screenshot.bmp

re: fclean all

run: re 
	./cub3D map.cub
