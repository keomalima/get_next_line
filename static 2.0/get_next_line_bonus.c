/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 08:15:44 by keomalima         #+#    #+#             */
/*   Updated: 2024/12/02 09:11:16 by kricci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*clear_buff(char *buf, char *line, size_t i)
{
	ft_mmove(buf, buf + i + 1, ft_len(buf + i + 1) + 1);
	return (line);
}

static char	*get_line(int fd, char *buf, char *line)
{
	size_t	i;
	ssize_t	bytes_read;

	while (1)
	{
		if (!buf[0])
		{
			bytes_read = read(fd, buf, BUFFER_SIZE);
			if (bytes_read == 0)
				return (line);
			if (bytes_read < 0)
				return (clear_line(line));
			buf[bytes_read] = '\0';
		}
		i = 0;
		while (buf[i] && buf[i] != '\n')
			i++;
		line = ft_strnjoin(line, buf, i + (buf[i] == '\n'));
		if (!line)
			return (NULL);
		if (buf[i] == '\n')
			return (clear_buff(buf, line, i));
		ft_bzero(buf, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	return (get_line(fd, buf[fd], line));
}
