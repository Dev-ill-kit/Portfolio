/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:09:20 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:09:21 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (*(dst + i) && i < size)
	{
		i++;
	}
	while (*(src + j) && (i + j + 1) < size)
	{
		*(dst + i + j) = *(src + j);
		j++;
	}
	if (i < size)
	{
		*(dst + i + j) = 0;
	}
	return (ft_strlen(src) + i);
}
