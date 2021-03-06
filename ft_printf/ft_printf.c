/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:22:36 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:23:05 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type						ft_flags(void)
{
	t_type						flag;

	flag.point = -1;
	flag.negative = 0;
	flag.star = 0;
	flag.type = 0;
	flag.len = 0;
	flag.zero = 0;
	return (flag);
}

int							ft_find(const char *c, int counter, t_type *flag,
							va_list args)
{
	while (c[counter])
	{
		if (!ft_isdigit(c[counter]) && !ft_type(c[counter]) &&
			!ft_flag(c[counter]))
			break ;
		if (c[counter] == '0' && flag->len == 0 && flag->negative == 0)
			flag->zero = 1;
		if (c[counter] == '.')
			counter = ft_dot(c, counter, flag, args);
		if (c[counter] == '-')
			*flag = ft_fnegative(*flag);
		if (c[counter] == '*')
			*flag = ft_flen(args, *flag);
		if (ft_isdigit(c[counter]))
			*flag = ft_fnums(c[counter], *flag);
		if (ft_type(c[counter]))
		{
			flag->type = c[counter];
			break ;
		}
		counter++;
	}
	return (counter);
}

int							ft_counter(const char *c, va_list args)
{
	int			counter;
	t_type		flag;
	int			chars;

	counter = 0;
	chars = 0;
	while (1)
	{
		flag = ft_flags();
		if (!c[counter])
			break ;
		else if (c[counter] == '%' && c[counter + 1])
		{
			counter = ft_find(c, ++counter, &flag, args);
			if (ft_type(c[counter]))
				chars += ft_checker((char)flag.type, flag, args);
			else if (c[counter])
				chars += ft_putchar(c[counter]);
		}
		else if (c[counter] != '%')
			chars += ft_putchar(c[counter]);
		counter++;
	}
	return (chars);
}

int							ft_printf(const char *format, ...)
{
	const char		*c;
	va_list			args;
	int				chars;

	c = ft_strdup(format);
	chars = 0;
	va_start(args, format);
	chars += ft_counter(c, args);
	va_end(args);
	free((char *)c);
	return (chars);
}
