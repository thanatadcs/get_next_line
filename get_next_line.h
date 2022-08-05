/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 07:04:35 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/05 21:51:36 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

// get_next_line_utils.c
ssize_t	get_newline_index(char *s1, ssize_t s1_len);
size_t	my_strlen(char *str);
void	concat(char **s1, char *s2, ssize_t s2_len);
char	*get_newline(char *s1, ssize_t newline_index);

#endif
