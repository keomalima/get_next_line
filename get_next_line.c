/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:14:18 by keomalima         #+#    #+#             */
/*   Updated: 2024/11/24 15:40:39 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_lst(t_gnl **current)
{
	t_gnl	*temp;

	temp = *current;
	*current = temp->next;
	free(temp);
}

void	clean_line(t_gnl **current, char *line)
{
	if ((*current)->line)
		free((*current)->line);
	if (line)
	{
		(*current)->line = ft_strdup(line);
		if (!(*current)->line)
		{
			free(*current);
			*current = NULL;
		}
	}
	else
	{
		free(*current);
		*current = NULL;
	}
}

void	copy_line(t_gnl **lst, char *line)
{
	char	*ptr;
	t_gnl	*current;
	t_gnl	*next;

	current = *lst;
	while (current)
	{
		ptr = current->line;
		while (*ptr && *ptr != '\n')
			*line++ = *ptr++;
		if (*ptr == '\n')
		{
			*line++ = *ptr++;
			clean_line(&current, ptr);
			break;
		}
		next = current->next;
		clean_lst(&current);
		current = next;
	}
	*lst = current;
	*line = '\0';
}

int	read_fd(int fd, char *buffer, t_gnl **lst)
{
	size_t	buffer_read;

	while (1)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read <= 0)
		{
			if (*lst)
				break;
			return (1);
		}
		buffer[buffer_read] = '\0';
		ft_lstadd_back_new(lst, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_gnl	*lst = NULL;
	char			*buffer;
	char			*line;
	int				read;

	buffer = ft_callocset(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer || fd < 0)
	{
		free(lst);
		free(buffer);
		return (NULL);
	}
	read = read_fd(fd, buffer, &lst);
	free(buffer);
	if (read)
		return (NULL);
	line = ft_callocset(get_line_len(lst) + 1, sizeof(char));
	copy_line(&lst, line);
	return (line);
}


int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
