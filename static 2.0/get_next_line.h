/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:03:46 by keomalima         #+#    #+#             */
/*   Updated: 2024/12/02 08:59:23 by kricci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_mmove(void *dest, const void *src, size_t n);
char	*clear_line(char *line);
char	*ft_strnjoin(char *line, char *buffer, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_len(const char *s);

#endif
