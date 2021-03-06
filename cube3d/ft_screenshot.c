/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "ft_screenshot.h"

t_screenshot			ft_screenshoter(t_cub3d *cube)
{
	t_screenshot		scr;

	scr.type = 0x4D42;
	scr.size = sizeof(t_screenshot) + sizeof(t_screenshot_info) \
	+ cube->delta.width * cube->delta.height * 4;
	scr.fst = 0;
	scr.scd = 0;
	scr.off = sizeof(t_screenshot) + sizeof(t_screenshot_info);
	return (scr);
}

t_screenshot_info		ft_screenshotinfo(t_cub3d *cube)
{
	t_screenshot_info	scri;

	scri.size = 40;
	scri.width = cube->delta.width;
	scri.height = (cube->delta.height - 1) * (-1);
	scri.places = 1;
	scri.bits = cube->sprite.b;
	scri.compression = 0;
	scri.size_screenshot = 0;
	scri.x = 0;
	scri.y = 0;
	scri.used = 0;
	scri.best = 0;
	return (scri);
}

void					ft_screenshot(t_cub3d *cube)
{
	int					fd;
	t_screenshot		scr;
	t_screenshot_info	scri;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	scr = ft_screenshoter(cube);
	scri = ft_screenshotinfo(cube);
	if (!write(fd, &scr, sizeof(scr)))
		ft_exiter("Error\nScreenshot error", cube);
	if (!write(fd, &scri, sizeof(scri)))
		ft_exiter("Error\nScreenshot error", cube);
	if (!write(fd, cube->sprite.address, \
	cube->delta.width * cube->delta.height * 4))
		ft_exiter("Error\nScreenshot error", cube);
	close(fd);
	ft_exiter("Screenshot success", cube);
}
