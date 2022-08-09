/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 01:14:28 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/09 13:13:03 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	ssize_t	i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

ssize_t	get_char_index(char *s, char c)
{
	ssize_t	i;

	if (s == 0)
		return (-1);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] != c)
		return (-1);
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*to_return;
	size_t	i;

	if (s1 == 0)
		s1 = "";
	else if (s2 == 0)
		s2 = "";
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	to_return = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (to_return == 0)
		return (0);
	i = 0;
	while (*s1)
		to_return[i++] = *s1++;
	while (*s2)
		to_return[i++] = *s2++;
	to_return[i] = '\0';
	return (to_return);
}

t_list	*lst_get_fd(t_list **head_ptr, int fd)
{
	t_list	*cur_node;
	t_list	*new_node;

	if (*head_ptr != 0)
	{
		cur_node = *head_ptr;
		while (cur_node->next && cur_node->fd != fd)
			cur_node = cur_node->next;
		if (cur_node->fd == fd)
			return (cur_node);
	}
	new_node = malloc(sizeof(t_list));
	if (new_node == 0)
		return (0);
	new_node->storage = 0;
	new_node->fd = fd;
	new_node->next = 0;
	if (*head_ptr == 0)
		*head_ptr = new_node;
	else
		cur_node->next = new_node;
	return (new_node);
}

// Don't have to free the storage since we will eventually return it.
void	lst_del_fd(t_list **head_ptr, int fd)
{
	t_list	*cur_node;
	t_list	*prev_node;

	if (*head_ptr != 0)
	{
		cur_node = *head_ptr;
		prev_node = 0;
		while (cur_node->next && cur_node->fd != fd)
		{
			prev_node = cur_node;
			cur_node = cur_node->next;
		}
		if (cur_node->fd == fd)
		{
			if (prev_node == 0)
				*head_ptr = cur_node->next;
			else
				prev_node->next = cur_node->next;
			free(cur_node);
		}
	}
}
