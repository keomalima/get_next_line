/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:01:45 by keomalima         #+#    #+#             */
/*   Updated: 2024/11/29 09:34:09 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
				return (free(line), NULL);
			buf[bytes_read] = '\0';
		}
		i = 0;
		while (buf[i] && buf[i] != '\n')
			i++;
		line = ft_strnjoin(line, buf, i + (buf[i] == '\n'));
		if (!line)
			return (NULL);
		if (buf[i] == '\n')
			return (ft_mmove(buf, buf + i + 1, ft_len(buf + i + 1) + 1), line);
		ft_bzero(buf, BUFFER_SIZE + 1);
	}
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	return (get_line(fd, buf, line));
}
