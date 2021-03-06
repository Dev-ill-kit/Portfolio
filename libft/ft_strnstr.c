/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:01 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:03 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!*little)
	{
		return ((char *)big);
	}
	while (i < len && *(big + i) != '\0')
	{
		if (*(big + i) == *little)
		{
			j = 1;
			while (i + j < len && little[j] != '\0' && big[i + j] == little[j])
			{
				j++;
			}
			if (*(little + j) == '\0')
			{
				return ((char *)&*(big + i));
			}
		}
		i++;
	}
	return (0);
}
