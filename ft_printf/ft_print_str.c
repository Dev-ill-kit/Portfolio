/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:32:31 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:32:42 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_check(char *str, t_type flag)
{
	int			chars;

	chars = 0;
	if (flag.point >= 0)
	{
		chars += ft_check_len(flag.point, ft_strlen(str), 0);
		chars += ft_putstr_precision(str, flag.point);
	}
	else
		chars += ft_putstr_precision(str, ft_strlen(str));
	return (chars);
}

int					ft_print_str(char *str, t_type flag)
{
	int			chars;

	chars = 0;
	if (!str)
		str = "(null)";
	if (flag.point >= 0 && (size_t)flag.point > ft_strlen(str))
		flag.point = ft_strlen(str);
	if (flag.negative == 1)
		chars += ft_check(str, flag);
	if (flag.point >= 0)
		chars += ft_check_len(flag.len, flag.point, 0);
	else
		chars += ft_check_len(flag.len, ft_strlen(str), 0);
	if (flag.negative == 0)
		chars += ft_check(str, flag);
	return (chars);
}
