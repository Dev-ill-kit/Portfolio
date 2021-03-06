/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>

# define ESC			65307
# define LEFT			65361
# define RIGHT			65363
# define W				119
# define D				100
# define S				115
# define A				97
# define FALSE 			0
# define TRUE 			1
# define TEX 			2
# define OUT 			3
# define FOV 			60 * (M_PI / 180)

typedef struct			s_camera
{
	double				x;
	double				y;
	int					turn;
	int					walk;
	double				wspeed;
	double				tspeed;
	int					side;
	double				angle;
}						t_camera;

typedef struct			s_raycast
{
	double				angle;
	double				distance;
	int					up;
	int					down;
	int					left;
	int					right;
	int					vertical;
	double				ray_x;
	double				ray_y;
}						t_raycast;

typedef struct			s_ray
{
	double				x;
	double				y;
	double				xx;
	double				yy;
	double				distance;
	double				ray_x;
	double				ray_y;
}						t_ray;

typedef struct			s_renderer
{
	double				distance;
	double				height;
	double				place;
	double				ceiling;
	double				step;
	double				tex_pos;
	unsigned int		t_x;
	unsigned int		t_y;
	int					y;
	char				*color;
}						t_renderer;

typedef struct			s_sprite
{
	void				*image;
	char				*address;
	int					width;
	int					height;
	int					b;
	int					len;
	int					end;
}						t_sprite;

typedef struct			s_map
{
	char				**map;
	double				line;
	int					f;
	int					c;
	int					objs;
	int					x;
	int					y;
}						t_map;

typedef struct			s_object
{
	double				x;
	double				y;
	double				angle;
	double				distance;
	double				size;
	double				xx;
	double				yy;
	double				step;
	double				position;
	unsigned int		*ptr;
}						t_object;

typedef struct			s_textures
{
	t_sprite			so;
	t_sprite			no;
	t_sprite			ea;
	t_sprite			we;
	t_sprite			sprite;
}						t_textures;

typedef struct			s_delta
{
	void				*mlx;
	void				*window;
	int					width;
	int					height;

}						t_delta;

typedef struct			s_cub3d
{
	t_camera			camera;
	t_raycast			*raycast;
	t_sprite			sprite;
	t_map				map;
	t_textures			textures;
	t_object			*object;
	t_delta				delta;
}						t_cub3d;

t_list					*ft_lstfreeman(t_list *lst);
int						ft_closer(t_cub3d *cube);
void					ft_exiter(char *msg, t_cub3d *cube);
int						ft_check_args(int argc, char **argv, t_cub3d *cube);
void					ft_check_line(char *line, t_cub3d *cube);
void					ft_check_params(t_cub3d *cube);
void					ft_check_map(t_cub3d *cube, char **map);
void					ft_check_color(char *line, char type, t_cub3d *cube);
void					ft_pixel_put(t_sprite *sprite, int x, int y, \
unsigned int color);
void					ft_screenshot(t_cub3d *cube);
int						ft_render(t_cub3d *cube);
void					ft_playerposition(t_cub3d *cube);
int						ft_wallcheck(double x, double y, t_cub3d *cube);
void					ft_mcparser(char *path, t_cub3d *cube);
void					ft_map(t_cub3d *cube, t_list *list, t_list *lst);
void					ft_params(t_cub3d *cube, char *path, int img);
void					ft_rectangle(int x, int y, t_cub3d *cube);
void					ft_raycasting(t_cub3d *cube);
void					ft_texture(char *path, t_sprite *sprite, t_cub3d *cube);
int						ft_clr(int t, int r, int g, int b);
void					ft_sprite(t_cub3d *cube);

#endif
