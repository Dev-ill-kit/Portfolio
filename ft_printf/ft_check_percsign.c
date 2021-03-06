/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_percsign.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:34:31 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:34:43 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_check_percsign(t_type flag)
{
	int			chars;

	chars = 0;
	if (flag.negative == 1)
		chars += ft_putstr_precision("%", 1);
	chars += ft_check_len(flag.len, 1, flag.zero);
	if (flag.negative == 0)
		chars += ft_putstr_precision("%", 1);
	return (chars);
}
