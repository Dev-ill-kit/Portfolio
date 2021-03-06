/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_player(char side, int x, int y, t_cub3d *cube)
{
	if (cube->camera.angle != -1 || cube->camera.x != 0 || cube->camera.y != 0)
		ft_exiter("Error\nPlayer error", cube);
	cube->camera.x = x;
	cube->camera.y = y;
	if (side == 'N')
		cube->camera.angle = M_PI / 2;
	else if (side == 'S')
		cube->camera.angle = 3 * M_PI / 2;
	else if (side == 'W')
		cube->camera.angle = M_PI;
	else if (side == 'E')
		cube->camera.angle = 0;
}

static void	ft_sprite_params(t_cub3d *cube, t_list *lst)
{
	int i;
	int x;
	int y;

	y = 0;
	i = 0;
	cube->object = malloc(sizeof(t_object) * (cube->map.objs));
	if (cube->object == NULL)
		ft_exiter("Error\nMemory error", cube);
	while (cube->map.map[y])
	{
		x = 0;
		while (cube->map.map[y][x])
		{
			if (cube->map.map[y][x] == '2')
			{
				cube->object[i].x = (x + 0.5) * cube->map.line;
				cube->object[i].y = (y + 0.5) * cube->map.line;
				i++;
			}
			x++;
		}
		y++;
	}
	ft_lstfreeman(lst);
}

static void	ft_line(char *str, int y, t_cub3d *cube)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == 'N' || str[x] == 'S' || str[x] == 'W' || str[x] == 'E')
			ft_player(str[x], x, y, cube);
		else if (str[x] == '2')
			cube->map.objs++;
		else if (str[x] != '0' && str[x] != '1' && str[x] != ' ')
			ft_exiter("Error\nMap error", cube);
		x++;
	}
}

static void	ft_save_map(t_cub3d *cube, int end)
{
	int		i;
	char	*save;

	i = 0;
	while (cube->map.map[i] != NULL)
	{
		save = cube->map.map[i];
		cube->map.map[i] = malloc(sizeof(char) * end + 1);
		ft_memset(cube->map.map[i], ' ', end);
		cube->map.map[i][end] = '\0';
		ft_memcpy(cube->map.map[i], save, ft_strlen(save));
		free(save);
		i++;
	}
	cube->map.x = end;
	cube->map.y = i;
}

void		ft_map(t_cub3d *cube, t_list *ptr, t_list *lst)
{
	size_t	i;
	size_t	end;

	i = 0;
	end = 0;
	while (ptr && ft_atoi(ptr->content) == 0)
		ptr = ptr->next;
	if (!(cube->map.map = malloc(sizeof(char *) * (ft_lstsize(ptr) + 1))))
		ft_exiter("Error\nMemory error", cube);
	while (ptr)
	{
		ft_line(ptr->content, i, cube);
		cube->map.map[i++] = ptr->content;
		end = end < ft_strlen(ptr->content) ? ft_strlen(ptr->content) : end;
		ptr = ptr->next;
	}
	cube->map.map[i] = NULL;
	ft_save_map(cube, end);
	ft_check_map(cube, cube->map.map);
	end = end < i ? i : end;
	cube->map.line = cube->delta.height > cube->delta.width \
	? cube->delta.height / end : cube->delta.width / end;
	cube->camera.x *= cube->map.line;
	cube->camera.y *= cube->map.line;
	ft_sprite_params(cube, lst);
}
