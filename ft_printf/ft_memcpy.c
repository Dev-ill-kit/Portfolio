/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:20:25 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:21:51 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dsts;
	const char	*srs;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	dsts = (char *)dst;
	srs = (const char *)src;
	while (n--)
		dsts[n] = srs[n];
	return (dst);
}
