/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_starting(t_cub3d *cube)
{
	cube->delta.window = NULL;
	cube->delta.mlx = NULL;
	cube->textures.ea.image = NULL;
	cube->textures.we.image = NULL;
	cube->textures.no.image = NULL;
	cube->textures.so.image = NULL;
	cube->textures.sprite.image = NULL;
	cube->sprite.image = NULL;
	cube->camera.x = 0;
	cube->camera.y = 0;
	cube->camera.turn = 0;
	cube->camera.walk = 0;
	cube->camera.side = FALSE;
	cube->camera.angle = -1;
	cube->camera.wspeed = 5;
	cube->camera.tspeed = 5 * (M_PI / 180);
	cube->delta.width = -1;
	cube->delta.height = -1;
	cube->map.map = NULL;
	cube->map.f = -1;
	cube->map.c = -1;
	cube->map.objs = 0;
}

static void	ft_create_sprite(t_sprite *sprite, t_delta *screen, t_cub3d *cube)
{
	sprite->image = mlx_new_image(screen->mlx, screen->width, screen->height);
	if (sprite->image == NULL)
		ft_exiter("Error\nMLX error", cube);
	sprite->address = mlx_get_data_addr(sprite->image, \
	&sprite->b, &sprite->len, &sprite->end);
	if (sprite->address == NULL)
		ft_exiter("Error\nMLX error", cube);
}

void		ft_params(t_cub3d *cube, char *path, int img)
{
	ft_starting(cube);
	cube->delta.mlx = mlx_init();
	if (cube->delta.mlx == NULL)
		ft_exiter("Error\nCube3d error", cube);
	ft_mcparser(path, cube);
	if (!(cube->raycast = malloc(sizeof(t_raycast) * cube->delta.width)))
		ft_exiter("Error\nMemory error", cube);
	ft_create_sprite(&cube->sprite, &cube->delta, cube);
	ft_render(cube);
	if (img == TRUE)
		ft_screenshot(cube);
	cube->delta.window = mlx_new_window(cube->delta.mlx, \
	cube->delta.width, cube->delta.height, "cub3d");
	if (cube->delta.window == NULL)
		ft_exiter("Error\nMLX error", cube);
	mlx_put_image_to_window(cube->delta.mlx, \
	cube->delta.window, cube->sprite.image, 0, 0);
}
