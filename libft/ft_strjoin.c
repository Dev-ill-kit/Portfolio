/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:12:55 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:12:56 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t		count;
	char		*c;

	count = 0;
	if (!s1 || !s2)
		return (0);
	else
		c = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!c)
		return (0);
	while (*s1)
	{
		*(c + count) = *s1;
		s1++;
		count++;
	}
	while (*s2)
	{
		*(c + count) = *s2;
		s2++;
		count++;
	}
	*(c + count) = '\0';
	return (c);
}
