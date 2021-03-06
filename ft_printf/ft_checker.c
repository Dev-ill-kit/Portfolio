/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:30:32 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:30:51 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_checker(int nbr, t_type flag, va_list args)
{
	int			chars;

	chars = 0;
	if (nbr == 'c')
		chars = ft_print_char(va_arg(args, int), flag);
	else if (nbr == 's')
		chars = ft_print_str(va_arg(args, char *), flag);
	else if (nbr == 'p')
		chars = ft_points(va_arg(args, unsigned long long), flag);
	else if (nbr == 'd' || nbr == 'i')
		chars = ft_print_int(va_arg(args, int), flag);
	else if (nbr == 'u')
		chars += ft_print_uint((unsigned int)va_arg(args, unsigned int), flag);
	else if (nbr == 'X')
		chars += ft_print_hex(va_arg(args, unsigned int), 0, flag);
	else if (nbr == 'x')
		chars += ft_print_hex(va_arg(args, unsigned int), 1, flag);
	else if (nbr == '%')
		chars += ft_check_percsign(flag);
	return (chars);
}
