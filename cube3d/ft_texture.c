/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_texture(char *path, t_sprite *texture, t_cub3d *cube)
{
	texture->image = mlx_xpm_file_to_image(cube->delta.mlx, \
						path, &texture->width, &texture->height);
	if (texture->image == NULL)
		ft_exiter("Error\nTexture error", cube);
	texture->address = mlx_get_data_addr(texture->image, \
					&texture->b, &texture->len, &texture->end);
	if (texture->address == NULL)
		ft_exiter("Error\nTexture error", cube);
}
