/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:50:58 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/08 01:24:02 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

size_t	ft_strlen(const char *s);
int		is_mul_overflow(size_t a, size_t b);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
ssize_t	get_char_index(char *s, char c);
char	*get_newline_update_storage(char **storage_ptr, ssize_t newline_index);
void	update_storage(char **storage_ptr, ssize_t newline_index);
void	read_line(char **storage_ptr, int fd);
char	*get_next_line(int fd);

#endif
