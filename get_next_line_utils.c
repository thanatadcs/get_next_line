/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 01:14:28 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/07 05:18:58 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	is_mul_overflow(size_t a, size_t b)
{
	size_t	prod;

	if (a == 0 || b == 0)
		return (0);
	prod = a * b;
	if (a == prod / b)
		return (0);
	return (1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*to_return;
	size_t	return_len;

	if (is_mul_overflow(count, size))
		return (0);
	return_len = count * size;
	to_return = malloc(return_len * sizeof(char));
	if (to_return == 0)
		return (0);
	while (return_len > 0)
		((char *) to_return)[--return_len] = 0;
	return (to_return);
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
