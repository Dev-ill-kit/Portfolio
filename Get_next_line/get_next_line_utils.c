/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:22:57 by student           #+#    #+#             */
/*   Updated: 2020/07/16 18:23:12 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

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

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;

	if (!s1 && !s2)
		return (0);
	c = malloc(sizeof(char) * (ft_strlen((char *)s1) +
	ft_strlen((char *)s2) + 1));
	if (!c)
		return (0);
	ft_memmove(c, s1, ft_strlen((char *)s1));
	ft_memmove(c + (ft_strlen((char *)s1)), s2, ft_strlen((char *)s2));
	c[(ft_strlen((char *)s1) + ft_strlen((char *)s2))] = '\0';
	free((char *)s1);
	return (c);
}
