/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 08:14:48 by keomalima         #+#    #+#             */
/*   Updated: 2024/12/02 09:02:38 by kricci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_mmove(void *dest, const void *src, size_t n);
char	*ft_strnjoin(char *line, char *buffer, size_t size);
char	*clear_line(char *line);
void	ft_bzero(void *s, size_t n);
size_t	ft_len(const char *s);

#endif
