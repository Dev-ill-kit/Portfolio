/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:12:46 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:12:46 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*c;

	i = 0;
	if (!s)
	{
		return (0);
	}
	c = (char *)malloc(sizeof(char) * len + 1);
	if (!c)
	{
		return (0);
	}
	if (start + 1 <= len)
	{
		while (i < len)
		{
			*(c + i) = *(s + start + i);
			i++;
		}
	}
	*(c + i) = '\0';
	return (c);
}
