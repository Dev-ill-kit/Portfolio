/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:15:23 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:15:24 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void		ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd((char *)s, fd);
	}
	write(fd, "\n", 1);
}
