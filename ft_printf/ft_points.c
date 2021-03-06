/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:33:59 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:34:11 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_check(char *ptr, t_type flag)
{
	int			chars;

	chars = 0;
	chars += ft_putstr_precision("0x", 2);
	if (flag.point >= 0)
	{
		chars += ft_check_len(flag.point, ft_strlen(ptr), 1);
		chars += ft_putstr_precision(ptr, flag.point);
	}
	else
		chars += ft_putstr_precision(ptr, ft_strlen(ptr));
	return (chars);
}

int					ft_points(unsigned long long nbr, t_type flag)
{
	char		*ptr;
	int			chars;

	chars = 0;
	if (nbr == 0 && flag.point == 0)
	{
		if (flag.len)
			while (flag.len > 2)
			{
				chars += ft_putstr_precision(" ", 1);
				flag.len--;
			}
		return (chars += ft_putstr_precision("0x", 2));
	}
	ptr = ft_unsignedll_check(nbr, 16);
	ptr = ft_conv_str(ptr);
	if ((size_t)flag.point < ft_strlen(ptr))
		flag.point = ft_strlen(ptr);
	if (flag.negative == 1)
		chars += ft_check(ptr, flag);
	chars += ft_check_len(flag.len, ft_strlen(ptr) + 2, 0);
	if (flag.negative == 0)
		chars = ft_check(ptr, flag) + chars;
	free(ptr);
	return (chars);
}
