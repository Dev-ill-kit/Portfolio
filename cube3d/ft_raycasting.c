/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static double		ft_calc_angle(double angle)
{
	angle = remainder(angle, M_PI * 2);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

static double		ft_dist(double x1, double x2, double y1, double y2)
{
	double		result;

	result = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (result);
}

static t_ray		ft_vertical(t_cub3d *cube, t_raycast *ray)
{
	t_ray		vert;

	vert.distance = INT_MAX;
	vert.x = floor(cube->camera.x / cube->map.line) * cube->map.line;
	vert.x += ray->right ? cube->map.line : 0;
	vert.y = cube->camera.y + (vert.x - cube->camera.x) * tan(ray->angle);
	if (vert.y < 0 || vert.y > cube->delta.height)
		return (vert);
	vert.xx = cube->map.line * (ray->left ? -1 : 1);
	vert.yy = cube->map.line * tan(ray->angle);
	vert.yy *= (ray->up && vert.yy > 0) ? -1 : 1;
	vert.yy *= (ray->down && vert.yy < 0) ? -1 : 1;
	while (vert.x >= 0 && vert.x <= cube->delta.width \
	&& vert.y >= 0 && vert.y <= cube->delta.height)
	{
		if (ft_wallcheck(vert.x - (ray->left ? 1 : 0), vert.y, cube) == TRUE)
		{
			vert.distance = ft_dist(cube->camera.x, \
			vert.x, cube->camera.y, vert.y);
			return (vert);
		}
		vert.x += vert.xx;
		vert.y += vert.yy;
	}
	return (vert);
}

static t_ray		ft_horisontal(t_cub3d *cube, t_raycast *ray)
{
	t_ray		hor;

	hor.distance = INT_MAX;
	hor.y = floor(cube->camera.y / cube->map.line) * cube->map.line;
	hor.y += ray->down ? cube->map.line : 0;
	hor.x = cube->camera.x + (hor.y - cube->camera.y) / tan(ray->angle);
	if (hor.y < 0 || hor.y > cube->delta.width)
		return (hor);
	hor.yy = cube->map.line * (ray->up ? -1 : 1);
	hor.xx = cube->map.line / tan(ray->angle);
	hor.xx *= (ray->left && hor.xx > 0) ? -1 : 1;
	hor.xx *= (ray->right && hor.xx < 0) ? -1 : 1;
	while (hor.x >= 0 && hor.x <= cube->delta.width \
	&& hor.y >= 0 && hor.y <= cube->delta.height)
	{
		if (ft_wallcheck(hor.x, hor.y - (ray->up ? 1 : 0), cube) == TRUE)
		{
			hor.distance = ft_dist(cube->camera.x, \
			hor.x, cube->camera.y, hor.y);
			return (hor);
		}
		hor.x += hor.xx;
		hor.y += hor.yy;
	}
	return (hor);
}

void				ft_raycasting(t_cub3d *cube)
{
	int				i;
	double			angle;
	t_ray			hor;
	t_ray			vert;

	i = 0;
	angle = cube->camera.angle - FOV / 2;
	while (i < cube->delta.width)
	{
		angle = ft_calc_angle(angle);
		cube->raycast[i].angle = angle;
		cube->raycast[i].down = angle > 0 && angle < M_PI;
		cube->raycast[i].up = !cube->raycast[i].down;
		cube->raycast[i].right = angle < (M_PI / 2) || angle > (M_PI * 1.5);
		cube->raycast[i].left = !cube->raycast[i].right;
		vert = ft_vertical(cube, &cube->raycast[i]);
		hor = ft_horisontal(cube, &cube->raycast[i]);
		cube->raycast[i].distance = vert.distance > \
		hor.distance ? hor.distance : vert.distance;
		cube->raycast[i].ray_x = vert.distance > hor.distance ? hor.x : vert.x;
		cube->raycast[i].ray_y = vert.distance > hor.distance ? hor.y : vert.y;
		cube->raycast[i].vertical = vert.distance > hor.distance ? FALSE : TRUE;
		angle += FOV / cube->delta.width;
		i++;
	}
}
