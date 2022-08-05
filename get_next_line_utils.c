/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:09:51 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/05 17:23:41 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Return index of newline character, return -1 otherwise
// Note: s1 is not guarantee to be null terminated (s1_len must be correct).
ssize_t	get_newline_index(char *s1, ssize_t s1_len)
{
	ssize_t	i;

	if (s1 == 0 || s1_len <= 0)
		return (-1);
	i = -1;
	while (++i < s1_len)
		if (s1[i] == '\n')
			return (i);
	return (-1);
}

/* TODO
// Concatenate two strings and store in s1
// Note: s1 guarantee to be null terminated, s2 is not (s2_len provided).
void	concat(char **s1, char *s2, ssize_t s2_len)
{
	return ;
}

char	*get_newline(char *s1, newline_index)
{
}

void	update_storage(char *storage, newline_index)
{
}
*/
