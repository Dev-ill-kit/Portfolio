/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:12:34 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:12:34 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*c;
	size_t	len;

	len = ft_strlen(s1) + 1;
	c = malloc(sizeof(char) * len);
	if (!c)
		return (0);
	c = ft_memcpy(c, s1, len);
	return (c);
}
