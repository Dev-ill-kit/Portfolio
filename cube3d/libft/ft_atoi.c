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

int		ft_atoi(const char *nptr)
{
	int		i;
	long	num;
	long	pre_num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (nptr[i] && (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' || \
	nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		pre_num = num;
		num = num * 10 + (nptr[i++] - '0');
		if (pre_num > num)
			return (sign == 1 ? -1 : 0);
	}
	return ((int)(num * sign));
}
