/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:09:34 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:09:35 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char		sym;
	char		*ptr;

	sym = (char)c;
	ptr = (char *)s;
	while (*ptr && !(*ptr == sym))
	{
		ptr++;
	}
	if (*ptr == sym)
	{
		return (ptr);
	}
	else
	{
		return (0);
	}
}
