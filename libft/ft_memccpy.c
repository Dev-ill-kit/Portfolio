/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:07:30 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:07:34 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		chr;

	i = 0;
	chr = (unsigned char)c;
	while (i < n)
	{
		*(((char *)dest) + i) = *(((char *)src) + i);
		i++;
		if (*((unsigned char *)(dest + (i - 1))) == chr)
		{
			return (&(*((unsigned char *)(dest + i))));
		}
	}
	return (0);
}
