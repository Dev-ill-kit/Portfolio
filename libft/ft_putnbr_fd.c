/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:15:36 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:15:37 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int		num;
	size_t				editednum;

	if (n < 0)
	{
		write(fd, "-", 1);
		num = (unsigned int)n * -1;
	}
	else
	{
		num = (unsigned int)n;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	editednum = num % 10 + 48;
	write(fd, &editednum, 1);
}
