/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:22:12 by student           #+#    #+#             */
/*   Updated: 2020/07/16 18:22:30 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_get_line(char *str)
{
	char		*s;
	int			i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_get_str(char *c)
{
	char		*s;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!c)
		return (0);
	while (c[i] && c[i] != '\n')
		i++;
	if (!c[i])
	{
		free(c);
		return (0);
	}
	if (!(s = malloc(sizeof(char) * ((ft_strlen(c) - i) + 1))))
		return (0);
	i++;
	while (c[i])
		s[j++] = c[i++];
	s[j] = '\0';
	free(c);
	return (s);
}

int			ft_wellworking(char *str)
{
	int			i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char			*c;
	int					i;
	char				*buffer;

	i = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_wellworking(c) && i != 0)
	{
		if ((i = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[i] = '\0';
		c = ft_strjoin(c, buffer);
	}
	free(buffer);
	*line = ft_get_line(c);
	c = ft_get_str(c);
	if (i == 0)
		return (0);
	return (1);
}
