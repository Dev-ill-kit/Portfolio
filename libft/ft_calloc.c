/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:12:20 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:12:22 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t nmemb, size_t size)
{
	char		*c;

	c = malloc(size * nmemb);
	if (!c)
	{
		return (0);
	}
	ft_memset(c, 0, nmemb * size);
	return (c);
}
