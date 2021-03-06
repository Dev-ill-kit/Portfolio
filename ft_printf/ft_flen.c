/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:50:33 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:50:45 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type		ft_flen(va_list args, t_type flag)
{
	flag.star = 1;
	flag.len = va_arg(args, int);
	if (!flag.zero)
	{
		if (flag.len < 0)
		{
			flag.negative = 1;
			flag.len *= -1;
		}
	}
	if (flag.zero && flag.len < 0)
	{
		flag.zero = 0;
		flag.len = -flag.len;
		flag.negative = 1;
	}
	return (flag);
}
