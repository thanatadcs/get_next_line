/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:58:06 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/06 17:41:36 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*to_return;
	char		*old_storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	storage = read_line(storage, fd);
	if (storage != 0 || *storage != '\0')
	{
		old_storage = storage;
		to_return = get_return_line(storage);
		storage = update_storage(storage);
		free(old_storage);
		if (to_return == 0)
		{
			free(storage);
			return (0);
		}
		return (to_return);
	}
	return (0);
}
