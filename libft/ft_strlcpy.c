/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:09:07 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:09:09 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	if (!dst)
		return (0);
	while (*(src + i) != '\0')
	{
		i++;
	}
	if (!size)
	{
		return (i);
	}
	while (*(src + j) != '\0' && j < ((unsigned int)size - 1))
	{
		*(dst + j) = *(src + j);
		j++;
	}
	if (size)
	{
		*(dst + j) = '\0';
	}
	return (i);
}
