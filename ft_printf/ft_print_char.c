/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:51:40 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:51:53 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_char(char c, t_type flag)
{
	int			counter;

	counter = 0;
	if (flag.negative == 1)
		ft_putchar(c);
	counter = ft_check_len(flag.len, 1, 0);
	if (flag.negative == 0)
		ft_putchar(c);
	return (counter + 1);
}
