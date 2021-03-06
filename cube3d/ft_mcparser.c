/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mcparser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_res(char *str, t_cub3d *cube)
{
	int width;
	int height;

	mlx_get_screen_size(cube->delta.mlx, &width, &height);
	if (cube->delta.width != -1 || cube->delta.height != -1)
		ft_exiter("Error\nConfig error", cube);
	str = ft_strchr(str, 'R');
	str++;
	cube->delta.width = ft_atoi(str);
	while (*str && ft_isspace(*str))
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	cube->delta.height = ft_atoi(str);
	if (cube->delta.width <= 0 || cube->delta.height <= 0)
		ft_exiter("Error\nResolution error", cube);
	cube->delta.width = cube->delta.width > width ? width : cube->delta.width;
	cube->delta.height = cube->delta.height > height \
	? height : cube->delta.height;
}

static void	ft_colorer(char *str, t_cub3d *cube, char type)
{
	char	**color;
	int		clr[3];
	int		i;

	while (*str && ft_isspace(*str))
		str++;
	str++;
	ft_check_color(str, type, cube);
	ft_bzero(clr, 3);
	if (!(color = ft_split(str, ',')))
		ft_exiter("Error\nMemory error", cube);
	i = 0;
	while (color && color[i] != NULL)
	{
		if ((clr[i] = ft_atoi(color[i])) > 255 || color[i] < 0 || i > 2)
			ft_exiter("Error\nColor error", cube);
		free(color[i]);
		i++;
	}
	free(color);
	if (type == 'C')
		cube->map.c = ft_clr(0, clr[0], clr[1], clr[2]);
	else if (type == 'F')
		cube->map.f = ft_clr(0, clr[0], clr[1], clr[2]);
}

static void	ft_path(char *str, t_cub3d *cube, char type)
{
	while (*str && ft_isspace(*str))
		str++;
	str = str + 2;
	while (*str && ft_isspace(*str))
		str++;
	if (type == 'N')
		ft_texture(str, &cube->textures.no, cube);
	if (type == 'S')
		ft_texture(str, &cube->textures.so, cube);
	if (type == 'W')
		ft_texture(str, &cube->textures.we, cube);
	if (type == 'E')
		ft_texture(str, &cube->textures.ea, cube);
	if (type == 's')
		ft_texture(str, &cube->textures.sprite, cube);
}

static void	ft_parse_params(t_list *list, t_cub3d *cube)
{
	int		len;

	while (list)
	{
		len = ft_strlen(list->content);
		if (ft_strnstr(list->content, "R ", len))
			ft_res(list->content, cube);
		else if (ft_strnstr(list->content, "NO ", len))
			ft_path(list->content, cube, 'N');
		else if (ft_strnstr(list->content, "SO ", len))
			ft_path(list->content, cube, 'S');
		else if (ft_strnstr(list->content, "WE ", len))
			ft_path(list->content, cube, 'W');
		else if (ft_strnstr(list->content, "EA ", len))
			ft_path(list->content, cube, 'E');
		else if (ft_strnstr(list->content, "S ", len))
			ft_path(list->content, cube, 's');
		else if (ft_strnstr(list->content, "F ", len))
			ft_colorer(list->content, cube, 'F');
		else if (ft_strnstr(list->content, "C ", len))
			ft_colorer(list->content, cube, 'C');
		else
			ft_check_line(list->content, cube);
		list = list->next;
	}
}

void		ft_mcparser(char *path, t_cub3d *cube)
{
	int		fd;
	char	*line;
	t_list	*header;
	t_list	*ptr;
	int		result;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_exiter("Error\nFile error", cube);
	header = NULL;
	while ((result = get_next_line(fd, &line)) > 0)
	{
		if (!(ptr = ft_lstnew(line)))
			ft_exiter("Error\nMemory error", cube);
		ft_lstadd_back(&header, ptr);
	}
	if (result == -1)
		ft_exiter("Error\nGnl fail", cube);
	if (!(ptr = ft_lstnew(line)))
		ft_exiter("Error\nMemory error", cube);
	ft_lstadd_back(&header, ptr);
	close(fd);
	ft_parse_params(header, cube);
	ft_check_params(cube);
	ft_map(cube, header, ptr);
}
