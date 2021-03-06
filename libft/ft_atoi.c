/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:10:31 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:10:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *nptr)
{
	size_t					i;
	unsigned long long		count;
	unsigned long long		minus;

	i = 0;
	count = 0;
	minus = 1;
	while (*(nptr + i) == 9 || *(nptr + i) == 10 || *(nptr + i) == 11 ||
	*(nptr + i) == 12 || *(nptr + i) == 13 || *(nptr + i) == 32)
		i++;
	if (*(nptr + i) == '-')
		minus *= -1;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
		i++;
	while (*(nptr + i))
	{
		if ((*(nptr + i) < 48 || *(nptr + i) > 57))
			break ;
		else
			count = count * 10 + (*(nptr + i) - 48);
		i++;
	}
	if (count >= 9223372036854775808ull)
		return (minus == 1 ? -1 : 0);
	return (count * minus);
}
