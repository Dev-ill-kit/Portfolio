/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void		ft_sprite_params(t_cub3d *cube)
{
	int	i;

	i = 0;
	while (i < cube->map.objs)
	{
		cube->object[i].angle = atan2(cube->object[i].y - \
		cube->camera.y, cube->object[i].x - cube->camera.x);
		while (cube->object[i].angle - cube->camera.angle > M_PI)
			cube->object[i].angle -= 2.0 * M_PI;
		while (cube->object[i].angle - cube->camera.angle < -M_PI)
			cube->object[i].angle += 2.0 * M_PI;
		cube->object[i].angle -= cube->camera.angle;
		cube->object[i].distance = sqrt(pow(cube->object[i].x - \
		cube->camera.x, 2) + pow(cube->object[i].y - cube->camera.y, 2));
		cube->object[i].size = (cube->map.line / cube->object[i].distance) \
		* (cube->delta.width / 2) / tan(FOV / 2);
		cube->object[i].xx = cube->delta.width / (FOV * (180 / M_PI)) \
		* ((180 / M_PI * cube->object[i].angle) + 30) \
		- cube->object[i].size / 2;
		cube->object[i].yy = cube->delta.height / 2 - cube->object[i].size / 2;
		cube->object[i].step = cube->textures.sprite.height \
		/ cube->object[i].size;
		cube->object[i].position = 0;
		i++;
	}
}

static void		ft_spriteierarchy(t_cub3d *cube)
{
	int			i;
	int			j;
	t_object	obj;

	i = 0;
	while (i < cube->map.objs)
	{
		j = 0;
		while (j < cube->map.objs - 1)
		{
			if (cube->object[j].distance < cube->object[j + 1].distance)
			{
				obj = cube->object[j];
				cube->object[j] = cube->object[j + 1];
				cube->object[j + 1] = obj;
			}
			j++;
		}
		i++;
	}
}

static t_object	ft_lighter(int y, int x, t_object obj, t_cub3d *cube)
{
	obj.ptr = (unsigned int *)(cube->textures.sprite.address \
	+ (y * cube->textures.sprite.len + x * \
	(cube->textures.sprite.b / 8)));
	return (obj);
}

static void		ft_show(t_cub3d *cube, t_object obj)
{
	int				i;
	int				j;
	int				x;
	int				y;

	i = -1;
	while (++i < obj.size)
	{
		if (obj.xx + i > cube->delta.width || obj.xx + i < 0 \
		|| cube->raycast[i + (int)obj.xx].distance < obj.distance)
			continue;
		x = i / obj.size * cube->textures.sprite.width;
		obj.position = 0;
		j = -1;
		while (++j < obj.size)
		{
			y = (unsigned int)obj.position & (cube->textures.sprite.height - 1);
			obj.ptr = ft_lighter(y, x, obj, cube).ptr;
			obj.position += obj.step;
			if (obj.yy + j > cube->delta.height || \
			obj.yy + j < 0 || *obj.ptr == 0x0)
				continue;
			ft_pixel_put(&cube->sprite, obj.xx + i, obj.yy + j, *obj.ptr);
		}
	}
}

void			ft_sprite(t_cub3d *cube)
{
	int	i;

	i = 0;
	ft_sprite_params(cube);
	ft_spriteierarchy(cube);
	while (i < cube->map.objs)
	{
		ft_show(cube, cube->object[i]);
		i++;
	}
}
