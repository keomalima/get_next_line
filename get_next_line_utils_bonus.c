/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:24:23 by keomalima         #+#    #+#             */
/*   Updated: 2024/11/26 08:59:32 by kricci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	size_t	n;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count >= SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	n = count * size;
	i = 0;
	while (n > i)
		((unsigned char *)ptr)[i++] = 0;
	return (ptr);
}

char	*ft_strjoin(char *stash, const char *buffer)
{
	char	*join;
	size_t	i;
	size_t	j;

	join = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer)) + 1);
	if (!join)
		return (NULL);
	i = -1;
	j = -1;
	while (stash[++i])
		join[i] = stash[i];
	while (buffer[++j])
		join[i + j] = buffer[j];
	join[i + j] = '\0';
	free(stash);
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
