/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:51:24 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/16 15:12:00 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		merge(const int fd, char **buf, int *ret)
{
	char		str[BUFF_SIZE + 1];
	char		*rmleaks;

	rmleaks = *buf;
	if ((*ret = read(fd, str, BUFF_SIZE)) <= 0)
		return ;
	str[*ret] = '\0';
	*buf = ft_strjoin(*buf, str);
	free(rmleaks);
}

int			loop(const int fd, char **buf, int *ret, char **line)
{
	char *ptr;
	char *ptr2;

	while (*ret > 0)
	{
		if ((ptr = ft_strchr(*buf, '\n')))
		{
			ptr2 = *buf;
			*ptr = '\0';
			*line = ft_strdup(*buf);
			*buf = ft_strdup(ptr + 1);
			free(ptr2);
			return (1);
		}
		merge(fd, buf, ret);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buf = NULL;
	int			ret;

	if (!line || fd < 0)
		return (-1);
	if (!buf)
		buf = ft_strnew(0);
	ret = 1;
	if (loop(fd, &buf, &ret, line))
		return (1);
	if (ret == -1)
		return (-1);
	if (*buf)
	{
		*line = ft_strdup(buf);
		ft_strdel(&buf);
		return (1);
	}
	return (0);
}
