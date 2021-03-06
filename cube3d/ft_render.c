/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static t_sprite			ft_side(t_cub3d *cube, t_raycast ray)
{
	if (ray.vertical)
	{
		if (ray.right)
			return (cube->textures.ea);
		else
			return (cube->textures.we);
	}
	else
	{
		if (ray.up)
			return (cube->textures.so);
		else
			return (cube->textures.no);
	}
}

static t_renderer		ft_singleline(t_cub3d *cube, int i, t_sprite texture)
{
	t_renderer			fnd;

	fnd.place = (cube->delta.width / 2.0) / tan(FOV / 2);
	cube->raycast[i].distance = cube->raycast[i].distance \
	== 0 ? 1 : cube->raycast[i].distance;
	fnd.distance = cube->raycast[i].distance * \
	cos(cube->raycast[i].angle - cube->camera.angle);
	fnd.height = (cube->map.line / fnd.distance) * fnd.place;
	fnd.ceiling = cube->delta.height / 2.0 - fnd.height / 2;
	if (cube->raycast[i].vertical)
		fnd.t_x = remainder(cube->raycast[i].ray_y, \
		cube->map.line) / cube->map.line * texture.width;
	else
		fnd.t_x = remainder(cube->raycast[i].ray_x, \
		cube->map.line) / cube->map.line * texture.width;
	fnd.t_x = fnd.t_x & (unsigned int)(texture.height - 1);
	fnd.step = texture.height / fnd.height;
	fnd.tex_pos = (fnd.ceiling - cube->delta.height \
	/ 2.0 + fnd.height / 2.0) * fnd.step;
	fnd.y = (int)fnd.ceiling;
	return (fnd);
}

static void				ft_walls(t_cub3d *cube)
{
	t_sprite			texture;
	t_renderer			c;
	int					i;

	i = 0;
	while (i < cube->delta.width)
	{
		texture = ft_side(cube, cube->raycast[i]);
		c = ft_singleline(cube, i, texture);
		while (c.y < c.ceiling + c.height)
		{
			c.t_y = (unsigned int)c.tex_pos & \
			((unsigned int)texture.height - 1);
			c.color = texture.address + \
			(c.t_y * texture.len + c.t_x * (texture.b / 8));
			c.tex_pos += c.step;
			if (c.y >= 0 && c.y <= cube->delta.height \
			&& i >= 0 && i <= cube->delta.width)
				ft_pixel_put(&cube->sprite, i, c.y, \
				*(unsigned int *)c.color);
			c.y++;
		}
		i++;
	}
}

int						ft_render(t_cub3d *cube)
{
	mlx_do_sync(cube->delta.mlx);
	ft_rectangle(0, 0, cube);
	ft_rectangle(0, cube->delta.height / 2, cube);
	ft_playerposition(cube);
	ft_raycasting(cube);
	ft_walls(cube);
	ft_sprite(cube);
	return (1);
}
