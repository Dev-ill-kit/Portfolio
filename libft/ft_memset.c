/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:13:34 by student           #+#    #+#             */
/*   Updated: 2020/04/30 12:13:53 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		(*((char *)s + i) = (unsigned char)c);
		i++;
	}
	return (s);
}
