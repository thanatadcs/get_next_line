/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:58:06 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/06 20:06:26 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Extract string until newline character (inclusive).
// Note: Does not free input storage.
char	*get_return_line(char *storage)
{
	size_t	storage_len;
	size_t	i;
	char	*to_return;

	storage_len = 0;
	while (storage[storage_len] && storage[storage_len] != '\n')
		storage_len++;
	storage_len++;
	to_return = malloc((storage_len + 1) * sizeof(char));
	if (to_return == 0)
		return (0);
	i = 0;
	while (i < storage_len)
	{
		to_return[i] = storage[i];
		i++;
	}
	to_return[i] = '\0';
	return (to_return);
}

// Get new storage with no character until first newline character.
// Note: Does not free input storage.
char	*update_storage(char *storage)
{
	size_t	storage_len;
	size_t	newline_len;
	size_t	i;
	char	*to_return;

	storage_len = 0;
	while (storage[storage_len])
		storage_len++;
	newline_len = 0;
	while (storage[newline_len] && storage[newline_len] != '\n')
		newline_len++;
	if (storage[newline_len] == '\n')
		newline_len++;
	to_return = malloc((storage_len - newline_len + 1) * sizeof(char));
	if (to_return == 0)
		return (0);
	i = 0;
	while (storage[newline_len + i])
	{
		to_return[i] = storage[newline_len + i];
		i++;
	}
	to_return[i] = '\0';
	return (to_return);
}

// Note: buf_len guarantee to be positive
char	*my_strjoin(char *storage, char *buf, ssize_t buf_len)
{
	char	*to_return;
	size_t	storage_len;
	size_t	i;
	ssize_t	j;

	if (storage == 0)
		storage = "";
	storage_len = 0;
	while (storage[storage_len])
		storage_len++;
	to_return = malloc((storage_len + buf_len + 1) * sizeof(char));
	if (to_return == 0)
		return (0);
	i = 0;
	while (i < storage_len)
	{
		to_return[i] = storage[i];
		i++;
	}
	j = -1;
	while (++j < buf_len)
		to_return[i++] = buf[j];
	to_return[i] = '\0';
	return (to_return);
}

// Append strings to storage until newline, eof, or error
// Note: Does free input storage.
char	*read_line(char *storage, int fd)
{
	ssize_t	read_num;
	char	*buf;
	char	*old_storage;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == 0)
		return (0);
	buf[BUFFER_SIZE] = '\0';
	read_num = read(fd, buf, BUFFER_SIZE);
	while (read_num != 0)
	{
		if (read_num == -1)
		{
			free(buf);
			return (0);
		}
		old_storage = storage;
		storage = my_strjoin(storage, buf, read_num);
		free(old_storage);
		if (is_contains(buf, '\n') || storage == 0)
			break ;
		read_num = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (storage);
}

int	is_contains(char *str, char c)
{
	if (str == 0)
		return (0);
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}
