/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixelputter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_pixel_put(t_sprite *image, int x, int y, unsigned int color)
{
	char		*dest;

	dest = image->address + (y * image->len + x * (image->b / 8));
	*(unsigned int *)dest = color;
}

void	ft_rectangle(int x, int y, t_cub3d *cube)
{
	int			i;
	int			j;
	int			width;
	int			height;
	int			color;

	i = x;
	width = cube->delta.width;
	height = cube->delta.height / 2;
	color = y == 0 ? cube->map.c : cube->map.f;
	while (i <= x + width)
	{
		j = y;
		while (j <= y + height)
		{
			ft_pixel_put(&cube->sprite, i, j, color);
			j++;
		}
		i++;
	}
}
