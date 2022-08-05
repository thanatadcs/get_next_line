/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:58:06 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/05 16:18:32 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		num_read;
	char		*buf;
	static char	*storage;
	char		*to_return;

	buf = malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (buf == 0)
		return (0);
	while (1)
	{
		num_read = read(fd, buf, BUFFER_SIZE);
		if (num_read < -1); // Error
		else if (num_read == 0); // End of file
		// Successful read
		// Concat
		concat(storage, buf, num_read);
		newline_index = get_newline_index(buf, num_read);
		if (newline_index >= 0) // Return newline
		{
			to_return = get_newline(storage, newline_index);
			update_storage(storage, newline-index);
			return (to_return);	
		}
		// Continue
	}
}
