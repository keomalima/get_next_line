/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:13:53 by keomalima         #+#    #+#             */
/*   Updated: 2024/11/23 15:06:51 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line_len(t_gnl *current)
{
	char	*ptr;
	int		len;

	len = 0;
	while (current)
	{
		ptr = current->line;
		while (*ptr && *ptr++ != '\n')
			len++;
		if (*ptr == '\n')
		{
			len++;
			break;
		}
		current = current->next;
	}
	return (len);
}

void	*ft_callocset(size_t count, size_t size)
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

char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	int		len;
	char	*str;

	len = 0;
	while (s[len])
		len++;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	len = 0;
	while (*s)
		str[len++] = *s++;
	str[len] = '\0';
	return (str);
}

void	ft_lstadd_back_new(t_gnl **lst, char *buffer)
{
	t_gnl	*new;
	t_gnl	*temp;

	if (!lst || !buffer)
		return ;
	new = malloc(sizeof(t_gnl));
	if (!new)
		return ;
	new->line = ft_strdup(buffer);
	if (!new->line)
	{
		free(new);
		return ;
	}
	new->next = NULL;
	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp && temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
