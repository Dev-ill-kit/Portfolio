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

#include "ft_printf.h"

static int		ft_check(long n)
{
	size_t	len;
	int		minus;

	len = 0;
	minus = 0;
	if (n < 0)
	{
		len++;
		minus++;
		n = -n;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char		*ft_get(char *c, long nbr, int len, int minus)
{
	if (nbr != 0)
		c = malloc(sizeof(char) * (len + 1));
	else
		return (c = ft_strdup("0"));
	if (!c)
		return (0);
	minus = 0;
	if (nbr < 0)
	{
		minus++;
		nbr = -nbr;
	}
	c[len] = '\0';
	while (--len)
	{
		c[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (minus == 1)
		c[0] = '-';
	else
		c[0] = (nbr % 10) + '0';
	return (c);
}

char			*ft_unsigned_itoa(unsigned int n)
{
	int		len;
	char	*c;
	long	nbr;
	int		minus;

	nbr = n;
	len = ft_check(nbr);
	c = 0;
	minus = 0;
	if (!(c = ft_get(c, nbr, len, minus)))
		return (0);
	return (c);
}
