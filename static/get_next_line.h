/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:03:46 by keomalima         #+#    #+#             */
/*   Updated: 2024/11/29 08:09:59 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_mmove(void *dest, const void *src, size_t n);
char	*ft_strnjoin(char *line, char *buffer, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_len(const char *s);

#endif