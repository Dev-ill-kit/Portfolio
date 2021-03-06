/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:17:02 by student           #+#    #+#             */
/*   Updated: 2020/07/13 13:17:44 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_type
{
	int					counter;
	int					type;
	int					len;
	int					negative;
	int					zero;
	int					point;
	int					star;
}						t_type;

int						ft_printf(const char *format, ...);
int						ft_type(int nbr);
int						ft_flag(int nbr);
int						ft_checker(int nbr, t_type flag, va_list args);
int						ft_check_len(int len, int neg, int zero);
int						ft_putstr_precision(char *str, int precision);
int						ft_print_char(char c, t_type flag);
int						ft_print_str(char *s, t_type flag);
int						ft_print_int(int nbr, t_type flag);
int						ft_check_percsign(t_type flag);
int						ft_print_hex(unsigned int nbr, int n, t_type flag);
int						ft_print_uint(unsigned int nbr, t_type flag);
int						ft_dot(const char *c, int nbr, t_type *flag,
						va_list args);
int						ft_putchar(int n);
int						ft_points(unsigned long long ptr, t_type flag);
char					*ft_unsignedll_check(unsigned long long nbr, int n);
char					*ft_unsigned_itoa(unsigned int n);
char					*ft_conv_str(char *s);
t_type					ft_fnegative(t_type flag);
t_type					ft_flen(va_list args, t_type flag);
t_type					ft_fnums(char c, t_type flag);
size_t					ft_strlen(const char *s);
void					*ft_memcpy(void *dst, const void *src, size_t n);
char					*ft_strdup(const char *s);
void					ft_putchar_fd(char c, int fd);
int						ft_isdigit(int c);
int						ft_tolower(int c);
char					*ft_itoa(int n);

#endif
