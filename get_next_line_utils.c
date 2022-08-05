/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:09:51 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/05 22:00:25 by tanukool         ###   ########.fr       */
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

// Return length of input string
// Note: str guarantee to be null terminated
size_t	my_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Concatenate two strings and store in s1
// Note: s1 guarantee to be null terminated, s2 is not (s2_len provided).
void	concat(char **s1, char *s2, ssize_t s2_len)
{
	size_t	s1_len;
	size_t	i;
	size_t	j;
	char	*new_s1;

	if (s2_len <= 0)
		return ;
	s1_len = my_strlen(*s1);
	new_s1 = malloc(((s1_len + (size_t)s2_len) * sizeof(char)) + 1);
	if (new_s1 == 0)
	{
		*s1 = 0;
		return ;
	}
	i = 0;
	while (i < s1_len)
	{
		new_s1[i] = (*s1)[i];
		i++;
	}
	j = 0;
	while (j < (size_t)s2_len)
		new_s1[i++] = s2[j++];
	free(*s1);
	*s1 = new_s1;
}

// Return new string up until a newline character in s1
// Note: Break when newline_index overflow
char	*get_newline(char *s1, ssize_t newline_index)
{
	char	*to_return;
	ssize_t	i;

	if (newline_index < 0)
		return (0);
	to_return = malloc((newline_index * sizeof(char)) + 1);
	if (to_return == 0)
		return (0);
	i = -1;
	while (++i <= newline_index)
		to_return[i] = s1[i];
	to_return[i] = '\0';
	return (to_return);
}

/*
void	update_storage(char *storage, newline_index)
{
}
*/
