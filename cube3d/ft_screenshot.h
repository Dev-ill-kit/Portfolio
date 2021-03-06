/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCREENSHOT_H
# define FT_SCREENSHOT_H

# include <stdint.h>
# pragma pack(push, 1)

typedef struct	s_screenshot
{
	uint16_t	type;
	uint32_t	size;
	uint16_t	fst;
	uint16_t	scd;
	uint32_t	off;
}				t_screenshot;

typedef struct	s_screenshot_info
{
	uint32_t	size;
	int32_t		width;
	int32_t		height;
	uint16_t	places;
	uint16_t	bits;
	uint32_t	compression;
	uint32_t	size_screenshot;
	int16_t		x;
	int16_t		y;
	uint32_t	used;
	uint32_t	best;
}				t_screenshot_info;

# pragma pack(pop)
#endif
