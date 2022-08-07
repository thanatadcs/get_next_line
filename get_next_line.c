/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:19:01 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/07 13:11:37 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Guarantee that storage_ptr and *storage_ptr are not null and contains \n.
// newline_index guaranteet to be positive.
// If failed, free storage.
char	*get_newline(char **storage_ptr, ssize_t newline_index)
{
	char	*to_return;
	char	*storage;
	ssize_t	i;

	storage = *storage_ptr;
	to_return = malloc((newline_index + 1 + 1) * sizeof (char));
	if (to_return == 0)
	{
		free(storage);
		*storage_ptr = 0;
		return (0);
	}
	i = -1;
	while (++i <= newline_index)
		to_return[i] = storage[i];
	to_return[i] = '\0';
	return (to_return);	
}

// Guarantee that storage_ptr and *storage_ptr are not null and contains \n.
// newline_index guaranteet to be positive.
// If failed, free storage.
void	update_storage(char **storage_ptr, ssize_t newline_index)
{
	char	*new_storage;
	char	*storage;
	size_t	storage_len;
	ssize_t	i;

	storage = *storage_ptr;
	storage_len = 0;
	while (storage[storage_len])
		storage_len++;
	new_storage = malloc((storage_len - (size_t)newline_index - 1 + 1) * sizeof(char));
	if (new_storage == 0)
	{
		free(storage);
		*storage_ptr = 0;
		return ;
	}
	i = 0;
	while (storage[newline_index + (++i)])
		new_storage[i - 1] = storage[newline_index + i];
	new_storage[i - 1] = '\0';
	*storage_ptr = new_storage;
	free(storage);
}

void	read_line(char **storage_ptr, char *buf, int fd)
{
	ssize_t		read_num;
	char		*old_storage;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(buf);
		return ;
	}
	read_num = read(fd, buf, BUFFER_SIZE);
	while (read_num != 0)
	{
		if (read_num == -1) // Error free buf, but keep storage
		{
			free(*storage_ptr);
			*storage_ptr = 0;
			break ;
		}
		old_storage = *storage_ptr;
		*storage_ptr = ft_strjoin(*storage_ptr, buf); // Return new, does't free
		free(old_storage);
		if (get_char_index(buf, '\n') >= 0)
			break ;
		read_num = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buf;
	char		*to_return;
	ssize_t		newline_index;

	to_return = 0;
	// Error: storage = 0
	// \n: storage = \n
	// eof: storage = some non-empty line, storage = 0
	// eof2: storage = 0, return 0
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buf == 0)
		return (0);
	read_line(&storage, buf, fd); // If failed free storage
	newline_index = get_char_index(storage, '\n');
	if (newline_index >= 0) // newline
	{
		to_return = get_newline(&storage, newline_index); // Create a new copy, if fail we free storage, set storage as 0
		update_storage(&storage, newline_index); // Free old, assign new, if failed we free storage, set storage as 0
	}
	else if (storage != 0) // eof (some string but no newline)
	{
		if (*storage == '\0')
			free(storage);
		else
			to_return = storage;
		storage = 0;
	}
	return (to_return);
}
