/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:06:21 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:07:18 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0 || dest == src)
	{
		return (dest);
	}
	while (i < n)
	{
		*(((char *)dest) + i) = *(((char *)src) + i);
		i++;
	}
	return (dest);
}
