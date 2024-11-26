/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:10:28 by keomalima         #+#    #+#             */
/*   Updated: 2024/11/26 09:53:38 by kricci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

char	*update_stash(char *stash)
{
	char	*new_stash;
	char	*newline;
	size_t	len;

	newline = ft_strchr(stash, '\n');
	new_stash = NULL;
	if (newline)
	{
		len = (ft_strlen(stash) - (newline - stash));
		new_stash = ft_calloc(len + 1, sizeof(char));
		if (new_stash)
			ft_strncpy(new_stash, newline + 1, len);
	}
	free(stash);
	return (new_stash);
}

static char	*get_line(char *stash)
{
	char	*line;
	char	*newline;
	size_t	len;

	if (!stash || !*stash)
		return (NULL);
	newline = ft_strchr(stash, '\n');
	if (newline)
		len = (newline - stash) + 1;
	else
		len = ft_strlen(stash);
	line = ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	ft_strncpy(line, stash, len);
	return (line);
}

char	*fill_stash(int fd, char *buffer, char *stash)
{
	size_t	read_bytes;

	while (1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			if (stash)
				return (stash);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		if (!stash)
			stash = ft_calloc(1, 1);
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*buffer;
	char		*line;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer || read(fd, 0, 0) < 0)
	{
		free(buffer);
		if (stash[fd])
		{
			free(stash[fd]);
			stash[fd] = NULL;
		}
		return (NULL);
	}
	stash[fd] = fill_stash(fd, buffer, stash[fd]);
	free(buffer);
	if (!stash[fd])
		return (NULL);
	line = get_line(stash[fd]);
	stash[fd] = update_stash(stash[fd]);
	return (line);
}
