/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 07:04:35 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/06 14:42:55 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

char	*get_return_line(char *storage);
char	*update_storage(char *storage);
char	*my_strjoin(char *storage, char *buf, ssize_t buf_len);
char	*read_line(char *storage, int fd);
int		is_contains(char *str, char c);
char	*get_next_line(int fd);

#endif
