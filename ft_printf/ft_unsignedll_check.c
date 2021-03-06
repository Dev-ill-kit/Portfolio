/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedll_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:23:25 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:23:43 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_checkull(unsigned long long nbr, int n, char *c,
								int counter)
{
	while (nbr != 0)
	{
		if ((nbr % n) < 10)
			c[counter - 1] = nbr % n + 48;
		else
			c[counter - 1] = nbr % n + 55;
		nbr /= n;
		counter--;
	}
	return (c);
}

char				*ft_unsignedll_check(unsigned long long nbr, int n)
{
	char						*c;
	unsigned long long			num;
	int							counter;

	c = 0;
	counter = 0;
	num = nbr;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr != 0)
	{
		nbr /= n;
		counter++;
	}
	if (!(c = malloc(sizeof(char) * (counter + 1))))
		return (0);
	c[counter] = '\0';
	c = ft_checkull(num, n, c, counter);
	return (c);
}
