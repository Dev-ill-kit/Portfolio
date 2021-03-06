/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:21 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:22 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char		*p1;
	unsigned char		*p2;
	size_t				i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (*(p1 + i) || *(p2 + i)))
	{
		if (*(p1 + i) != *(p2 + i))
		{
			return (*(p1 + i) - *(p2 + i));
		}
		i++;
	}
	return (0);
}
