/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:13:07 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:13:08 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_whileset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	size_t		size;
	char		*begin;
	char		*finish;
	char		*c;

	i = 0;
	if (!s1 || !set)
		return (0);
	while (*(s1 + i) && ft_whileset(*(s1 + i), set))
		i++;
	begin = (char *)&*(s1 + i);
	if ((i = ft_strlen(s1) - 1) != -1)
		while (i >= 0 && ft_whileset(*(s1 + i), set))
			i -= 1;
	if ((finish = (char *)&*(s1 + i)) == begin || !*s1)
		size = 2;
	else
		size = finish - begin + 2;
	if (begin >= finish)
		return (ft_strdup(""));
	if (!(c = malloc(sizeof(char) * size)))
		return (0);
	ft_strlcpy(c, begin, size);
	return (c);
}
