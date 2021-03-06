/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:48:17 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:48:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_conv_str(char *str)
{
	int			counter;

	counter = 0;
	while (str[counter++])
		str[counter] = ft_tolower(str[counter]);
	return (str);
}
