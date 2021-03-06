/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_getkeydown(int keycode, t_cub3d *cube)
{
	if (keycode == ESC)
		ft_closer(cube);
	if (keycode == LEFT)
		cube->camera.turn = -1;
	else if (keycode == RIGHT)
		cube->camera.turn = 1;
	else if (keycode == W)
		cube->camera.walk = 1;
	else if (keycode == S)
		cube->camera.walk = -1;
	else if (keycode == D)
	{
		cube->camera.walk = -1;
		cube->camera.side = TRUE;
	}
	else if (keycode == A)
	{
		cube->camera.walk = 1;
		cube->camera.side = TRUE;
	}
	ft_render(cube);
	mlx_put_image_to_window(cube->delta.mlx, \
	cube->delta.window, cube->sprite.image, 0, 0);
	return (1);
}

int		ft_getkeyup(int keycode, t_cub3d *cube)
{
	if (keycode == LEFT)
		cube->camera.turn = 0;
	else if (keycode == RIGHT)
		cube->camera.turn = 0;
	else if (keycode == W)
		cube->camera.walk = 0;
	else if (keycode == S)
		cube->camera.walk = 0;
	else if (keycode == D)
	{
		cube->camera.walk = 0;
		cube->camera.side = FALSE;
	}
	else if (keycode == A)
	{
		cube->camera.walk = 0;
		cube->camera.side = FALSE;
	}
	ft_render(cube);
	mlx_put_image_to_window(cube->delta.mlx, \
	cube->delta.window, cube->sprite.image, 0, 0);
	return (1);
}

int		ft_wallcheck(double x, double y, t_cub3d *cube)
{
	int xx;
	int yy;

	if (x < 0 || x > cube->delta.width || y < 0 || y > cube->delta.height)
		return (OUT);
	xx = (int)((x / cube->map.line));
	yy = (int)((y / cube->map.line));
	if (xx < 0 || xx >= cube->map.x || yy < 0 || yy >= cube->map.y)
		return (OUT);
	if (cube->map.map[yy][xx] == '2')
		return (TEX);
	return (cube->map.map[yy][xx] == '1');
}

void	ft_playerposition(t_cub3d *cube)
{
	double x;
	double y;
	double move;
	double side;

	side = cube->camera.side ? M_PI / 2 * cube->camera.walk : 0;
	move = cube->camera.walk * cube->camera.wspeed;
	move = cube->camera.side && move < 0 ? -move : move;
	cube->camera.angle += cube->camera.turn * cube->camera.tspeed;
	x = cube->camera.x + cos(cube->camera.angle - side) * move * 2;
	y = cube->camera.y + sin(cube->camera.angle - side) * move * 2;
	if (!ft_wallcheck(x, y, cube))
	{
		cube->camera.x = cube->camera.x + cos(cube->camera.angle - side) * move;
		cube->camera.y = cube->camera.y + sin(cube->camera.angle - side) * move;
	}
	cube->camera.turn = 0;
	cube->camera.walk = 0;
	cube->camera.side = 0;
}

int		main(int argc, char **argv)
{
	t_cub3d		cube;
	int			screenshot;

	screenshot = ft_check_args(argc, argv, &cube);
	ft_params(&cube, argv[1], screenshot);
	mlx_hook(cube.delta.window, 17, 1Lu << 17u, ft_closer, &cube);
	mlx_hook(cube.delta.window, 2, 1Lu << 0u, ft_getkeydown, &cube);
	mlx_hook(cube.delta.window, 3, 1Lu << 1u, ft_getkeyup, &cube);
	mlx_loop(cube.delta.mlx);
	return (0);
}
