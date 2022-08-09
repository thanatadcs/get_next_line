/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:50:58 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/09 03:42:53 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

typedef struct s_list
{
	char			*storage;
	int				fd;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
ssize_t	get_char_index(char *s, char c);
t_list	*lst_get_fd(t_list **head_ptr, int fd);
void	lst_del_fd(t_list **head_ptr, int fd);
char	*get_next_line(int fd);

#endif
