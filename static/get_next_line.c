/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:01:45 by keomalima         #+#    #+#             */
/*   Updated: 2024/11/29 09:38:07 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_fd(int fd, char *buffer, char *line)
{
	size_t	i;
	ssize_t	bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 || (bytes_read == 0 && !line))
			return (free(line), NULL);
		if (bytes_read == 0 && line)
			return (line);
		buffer[bytes_read] = '\0';
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		line = ft_strnjoin(line, buffer, i + 1);
		if (!line)
			return (NULL);
		if (buffer[i] == '\n')
		{
			ft_mmove(buffer, buffer + i + 1, (ft_len(buffer + i + 1) + 1));
			break ;
		}
		ft_bzero(buffer, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	i = 0;
	if (buf[i])
	{
		while (buf[i] && buf[i] != '\n')
			i++;
		line = ft_strnjoin(line, buf, i + 1);
		if (!line)
				return (NULL);
		if (buf[i] == '\n')
		{
			return(ft_mmove(buf, buf + i + 1, (ft_len(buf + i + 1) + 1)), line);
			return (line);
		}
		ft_bzero(buf, BUFFER_SIZE);
	}
	return (read_fd(fd, buf, line));
}

/*
int	main (int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	free(line);
	while ((line = get_next_line(fd)))
	{
		printf("[%s]", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/