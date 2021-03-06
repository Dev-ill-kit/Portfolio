/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*substr;

	str = (char *)big;
	substr = (char *)little;
	if (!*little)
		return (str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == substr[j] && str[i + j] && \
		substr[j] && i + j <= len)
		{
			j++;
			if (substr[j] == '\0')
				return (str + i);
		}
		i++;
	}
	return (NULL);
}
