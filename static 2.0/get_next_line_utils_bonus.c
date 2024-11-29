/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 08:17:25 by keomalima         #+#    #+#             */
/*   Updated: 2024/11/29 08:19:20 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strnjoin(char *line, char *buffer, size_t size)
{
	char	*join;
	size_t	i;
	size_t	j;

	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	if (!buffer)
		return (free(line), NULL);
	join = malloc(sizeof(char) * (ft_len(line) + size) + 1);
	if (!join)
		return (free(line), NULL);
	i = -1;
	while (line[++i])
		join[i] = line[i];
	j = 0;
	while (buffer[j] && size > j)
		join[i++] = buffer[j++];
	join[i] = '\0';
	free(line);
	return (join);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = '\0';
}

void	*ft_mmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (NULL);
	if (dest > src)
		while (n-- > 0)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else
	{
		i = 0;
		while (n > i)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

size_t	ft_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
