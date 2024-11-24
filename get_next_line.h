/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:14:34 by keomalima         #+#    #+#             */
/*   Updated: 2024/11/22 15:25:48 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct s_gnl
{
	char			*line;
	struct s_gnl	*next;
}	t_gnl;

char	*get_next_line(int fd);
void	*ft_callocset(size_t count, size_t size);
void	ft_lstadd_back_new(t_gnl **lst, char *buffer);
char	*ft_strchr(char *str, char c);
char	*ft_strdup(char *s);
int	get_line_len(t_gnl *current);

#endif
