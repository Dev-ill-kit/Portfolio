/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:13:42 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:13:43 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_size(int n)
{
	size_t		size;
	long		num;

	num = n;
	size = 1;
	if (num < 0)
	{
		size++;
		num = -num;
	}
	while (num >= 10)
	{
		size++;
		num /= 10;
	}
	return (size);
}

char				*ft_itoa(int n)
{
	size_t		size;
	long		num;
	int			i;
	char		*result;

	i = 0;
	num = n;
	size = ft_size(n);
	result = (char *)malloc(sizeof(char) * size + 1);
	if (!result)
		return (0);
	if (n < 0)
		*result = '-';
	if (num < 0)
	{
		num = -num;
	}
	*(result + (size - i++)) = '\0';
	while (num >= 10)
	{
		*(result + (size - i++)) = num % 10 + 48;
		num /= 10;
	}
	*(result + (size - i++)) = num % 10 + 48;
	return (result);
}
