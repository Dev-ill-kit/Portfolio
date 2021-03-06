/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int			ft_closer(t_cub3d *cube)
{
	ft_exiter("Cub3d ended", cube);
	return (0);
}

static void	ft_closer_mlx(t_cub3d *cube)
{
	if (cube->delta.mlx == NULL)
		return ;
	if (cube->delta.window)
		mlx_destroy_window(cube->delta.mlx, cube->delta.window);
	if (cube->textures.ea.image)
		mlx_destroy_image(cube->delta.mlx, cube->textures.ea.image);
	if (cube->textures.we.image)
		mlx_destroy_image(cube->delta.mlx, cube->textures.we.image);
	if (cube->textures.no.image)
		mlx_destroy_image(cube->delta.mlx, cube->textures.no.image);
	if (cube->textures.so.image)
		mlx_destroy_image(cube->delta.mlx, cube->textures.so.image);
	if (cube->textures.sprite.image)
		mlx_destroy_image(cube->delta.mlx, cube->textures.sprite.image);
	if (cube->sprite.image)
		mlx_destroy_image(cube->delta.mlx, cube->sprite.image);
	if (cube->delta.mlx)
		free(cube->delta.mlx);
}

void		ft_exiter(char *msg, t_cub3d *cube)
{
	if (errno != 0 && errno != 11)
		perror(msg);
	else
		ft_putendl_fd(msg, 1);
	ft_closer_mlx(cube);
	free(NULL);
	errno = errno == 11 ? 0 : errno;
	exit(errno);
}
