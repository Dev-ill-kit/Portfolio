/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:47:02 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:47:16 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_check(char *heximal, t_type flag, int n)
{
	int			chars;

	chars = 0;
	if (flag.point >= 0)
		chars += ft_check_len(flag.point - 1, ft_strlen(heximal) - 1, 1);
	if (n == 0)
		chars += ft_putstr_precision(heximal, ft_strlen(heximal));
	else
	{
		if (*heximal >= 65 && *heximal <= 90)
			*heximal += 32;
		chars += ft_putstr_precision(heximal, ft_strlen(heximal));
	}
	return (chars);
}

static int			ft_hex(char *heximal, t_type flag, int n)
{
	int			chars;

	chars = 0;
	if (flag.negative == 1)
		chars += ft_check(heximal, flag, n);
	if (flag.point >= 0 && (size_t)flag.point < ft_strlen(heximal))
		flag.point = ft_strlen(heximal);
	if (flag.point >= 0)
	{
		flag.len -= flag.point;
		chars += ft_check_len(flag.len, 0, 0);
	}
	else
		chars += ft_check_len(flag.len, ft_strlen(heximal), flag.zero);
	if (flag.negative == 0)
		chars += ft_check(heximal, flag, n);
	return (chars);
}

int					ft_print_hex(unsigned int nbr, int n, t_type flag)
{
	char		*c;
	int			chars;

	chars = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	if (flag.point == 0 && nbr == 0)
	{
		chars += ft_check_len(flag.len, 0, 0);
		return (chars);
	}
	c = ft_unsignedll_check((unsigned long long)nbr, 16);
	if (n == 1)
		c = ft_conv_str(c);
	chars += ft_hex(c, flag, n);
	free(c);
	return (chars);
}
