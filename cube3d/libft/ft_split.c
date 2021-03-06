/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] && s[i + 1])
				i++;
		}
		i++;
	}
	return (count);
}

static int	count_len(char const *str, char c)
{
	int i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

static void	*ft_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		word_count;
	char	*str;
	char	**array;

	str = (char *)s;
	i = 0;
	j = 0;
	word_count = count_words(s, c);
	if (!s || !(array = (char **)malloc((word_count + 1) * sizeof(char *))))
		return (NULL);
	while (j < word_count)
	{
		i = count_len(str, c);
		if (i > 0)
		{
			if (!(array[j++] = ft_substr(str, 0, i)))
				return (ft_free(array));
		}
		i++;
		str += i;
	}
	array[j] = NULL;
	return (array);
}
