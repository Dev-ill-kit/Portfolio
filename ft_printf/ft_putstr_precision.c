/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:52:03 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:52:17 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putstr_precision(char *str, int precision)
{
	int counter;

	counter = 0;
	while (str[counter] && counter < precision)
		ft_putchar(str[counter++]);
	return (counter);
}
