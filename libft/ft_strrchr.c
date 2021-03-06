/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:09:45 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:09:48 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char		sym;
	char		*ptr;

	sym = (char)c;
	ptr = (char *)s + ft_strlen(s);
	while (ptr >= s)
	{
		if (*ptr == sym)
		{
			return (ptr);
		}
		ptr--;
	}
	return (NULL);
}
