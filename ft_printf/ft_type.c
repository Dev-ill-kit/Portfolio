/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:31:06 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:31:23 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_type(int nbr)
{
	return ((nbr == 'c') || (nbr == 's') || (nbr == 'p') || (nbr == 'd')
	|| (nbr == 'i') || (nbr == 'u') || (nbr == 'x')
	|| (nbr == 'X') || (nbr == '%'));
}
