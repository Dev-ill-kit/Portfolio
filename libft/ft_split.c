/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:13:18 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:13:19 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_words(char const *s, char c)
{
	size_t		i;
	size_t		w;

	i = 0;
	w = 0;
	if (*s)
	{
		while (*(s + i) && *(s + i + 1) != '\0')
		{
			if (i == 0 && *(s + i) != c)
				w++;
			if (*(s + i) == c && *(s + i + 1) != c)
				w++;
			i++;
		}
		return (w);
	}
	return (0);
}

static char			*ft_word(char const *s, char c, size_t *w)
{
	char		*str;
	size_t		i;

	i = 0;
	if (!(str = (char *)malloc(ft_strlen(s) + 1)))
		return (0);
	while (*(s + *w) && *(s + *w) != c)
	{
		*(str + i) = *(s + *w);
		i++;
		*w += 1;
	}
	*(str + i) = '\0';
	while (*(s + *w) == c && *(s + *w))
	{
		*w += 1;
	}
	return (str);
}

char				**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		w;
	char		**str;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	w = ft_words(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (w + 1))))
		return (0);
	while (*(s + i) && *(s + i) == c)
		i++;
	while (*(s + i) && j < w)
	{
		*(str + j) = ft_word(s, c, &i);
		j++;
	}
	*(str + j) = 0;
	return (str);
}
