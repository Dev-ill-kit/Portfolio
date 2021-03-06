/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:51:17 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:51:31 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_check_len(int len, int neg, int zero)
{
	int			chars;

	chars = 0;
	while (len - neg > 0)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len -= 1;
		chars++;
	}
	return (chars);
}
