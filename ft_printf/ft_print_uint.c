/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:32:06 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:32:18 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_check(char *c, t_type flag)
{
	int			chars;

	chars = 0;
	if (flag.point >= 0)
		chars += ft_check_len(flag.point - 1, ft_strlen(c) - 1, 1);
	chars += ft_putstr_precision(c, ft_strlen(c));
	return (chars);
}

static int			ft_uint(char *c, t_type flag)
{
	int			chars;

	chars = 0;
	if (flag.negative == 1)
		chars += ft_check(c, flag);
	if (flag.point >= 0 && (size_t)flag.point < ft_strlen(c))
		flag.point = ft_strlen(c);
	if (flag.point >= 0)
	{
		flag.len -= flag.point;
		chars += ft_check_len(flag.len, 0, 0);
	}
	else
		chars += ft_check_len(flag.len, ft_strlen(c), flag.zero);
	if (flag.negative == 0)
		chars += ft_check(c, flag);
	return (chars);
}

int					ft_print_uint(unsigned int nbr, t_type flag)
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
	c = ft_unsigned_itoa(nbr);
	chars += ft_uint(c, flag);
	free(c);
	return (chars);
}
