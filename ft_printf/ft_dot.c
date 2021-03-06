/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:47:49 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:48:05 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_dot(const char *c, int nbr, t_type *flag, va_list args)
{
	int			counter;

	counter = nbr;
	counter++;
	if (c[counter] == '*')
	{
		flag->point = va_arg(args, int);
		counter++;
	}
	else
	{
		flag->point = 0;
		while (ft_isdigit(c[counter]))
			flag->point = (flag->point * 10) + (c[counter++] - '0');
	}
	return (counter);
}
