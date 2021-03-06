/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:46:24 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:46:39 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_check(char *c, int nbr, t_type flag)
{
	int				chars;

	chars = 0;
	if (nbr < 0 && flag.point >= 0)
		ft_putchar('-');
	if (flag.point >= 0)
		chars += ft_check_len(flag.point - 1, ft_strlen(c) - 1, 1);
	chars += ft_putstr_precision(c, ft_strlen(c));
	return (chars);
}

static int			ft_int(char *c, int nbr, t_type flag)
{
	int				chars;

	chars = 0;
	if (flag.negative == 1)
		chars += ft_check(c, nbr, flag);
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
		chars += ft_check(c, nbr, flag);
	return (chars);
}

int					ft_print_int(int nbr, t_type flag)
{
	char			*c;
	int				n;
	int				chars;

	n = nbr;
	chars = 0;
	if (flag.point == 0 && nbr == 0)
	{
		chars += ft_check_len(flag.len, 0, 0);
		return (chars);
	}
	if (nbr < 0 && (flag.point >= 0 || flag.zero == 1))
	{
		if (flag.zero == 1 && flag.point == -1)
			ft_putstr_precision("-", 1);
		nbr *= -1;
		flag.zero = 1;
		flag.len--;
		chars++;
	}
	c = ft_itoa(nbr);
	chars += ft_int(c, n, flag);
	free(c);
	return (chars);
}
