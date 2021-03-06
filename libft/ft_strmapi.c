/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:13:58 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:13:59 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*c;
	unsigned int		i;

	i = 0;
	if (!s)
	{
		return (0);
	}
	c = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!c)
	{
		return (0);
	}
	while (*(s + i))
	{
		*(c + i) = f(i, *(s + i));
		i++;
	}
	*(c + i) = '\0';
	return (c);
}
