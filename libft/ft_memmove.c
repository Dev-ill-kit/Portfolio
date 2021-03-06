/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:07:46 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:07:47 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	if (n == 0)
		return (dest);
	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			i -= 1;
			*((char *)(dest + i)) = *((char *)(src + i));
		}
	}
	else if (dest == NULL && src == NULL)
		return (0);
	else
	{
		i = 0;
		while (i < n)
		{
			*((char *)(dest + i)) = *((char *)(src + i));
			i++;
		}
	}
	return (dest);
}
