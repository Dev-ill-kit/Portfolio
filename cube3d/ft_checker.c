/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_check_line(char *line, t_cub3d *cube)
{
	while (ft_isblank(*line) && *line)
		line++;
	if (*line != '1' && *line != '\0')
		ft_exiter("Error\nConfig error", cube);
}

void	ft_check_color(char *line, char type, t_cub3d *cube)
{
	int i;

	i = 0;
	if (type == 'F' && cube->map.f != -1)
		ft_exiter("Error\nFloor color error", cube);
	if (type == 'C' && cube->map.c != -1)
		ft_exiter("Error\nCeiling color error", cube);
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ',' && !ft_isspace(line[i]))
			ft_exiter("Error\nColor error", cube);
		i++;
	}
}

int		ft_check_args(int argc, char **argv, t_cub3d *cube)
{
	int			i;
	int			len;

	i = FALSE;
	cube->delta.mlx = NULL;
	if (argc == 1)
		ft_exiter("Error\n1st arg error", cube);
	if (argc >= 2)
	{
		len = ft_strlen(argv[1]) - 4;
		if (len <= 0 || ft_memcmp(argv[1] + len, ".cub\0", 5) != 0)
			ft_exiter("Error\n1st arg error", cube);
	}
	if (argc == 3)
		if (ft_memcmp(argv[2], "--save\0", 7) == 0)
			i = TRUE;
		else
			ft_exiter("Error\n2nd arg error", cube);
	if (argc > 3)
		ft_exiter("Error\nToo much args", cube);
	return (i);
}

void	ft_check_params(t_cub3d *cube)
{
	if (cube->delta.width == -1 || cube->delta.height == -1)
		ft_exiter("Error\nResolution error", cube);
	if (cube->textures.so.image == NULL)
		ft_exiter("Error\nSouth testure error", cube);
	if (cube->textures.no.image == NULL)
		ft_exiter("Error\nNorth testure error", cube);
	if (cube->textures.we.image == NULL)
		ft_exiter("Error\nWest texture error", cube);
	if (cube->textures.ea.image == NULL)
		ft_exiter("Error\nEast texture error", cube);
	if (cube->textures.sprite.image == NULL)
		ft_exiter("Error\nSprite texture error", cube);
	if (cube->map.c == -1)
		ft_exiter("Error\nCeiling color error", cube);
	if (cube->map.f == -1)
		ft_exiter("Error\nFloor color error", cube);
}

void	ft_check_map(t_cub3d *cube, char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if (j == 0 || j == cube->map.x - 1)
					ft_exiter("Error\nInvalid map", cube);
				if (i == 0 || i == cube->map.y - 1)
					ft_exiter("Error\nInvalid map", cube);
				if (j + 1 < cube->map.x && map[i][j + 1] == ' ')
					ft_exiter("Error\nInvalid map", cube);
				if (map[i][j - 1] == ' ' || map[i - 1][j] == ' ')
					ft_exiter("Error\nInvalid map", cube);
				if (i + 1 < cube->map.y && map[i + 1][j] == ' ')
					ft_exiter("Error\nInvalid map", cube);
			}
		}
	}
}
