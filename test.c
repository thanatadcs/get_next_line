#include "get_next_line.h"
#include <stdio.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

int	my_strcmp(char *s1, char *s2)
{
	if (s1 == 0|| s2 == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	test_get_newline_index(char *s1, ssize_t s1_len, ssize_t expected)
{
	ssize_t actual = get_newline_index(s1, s1_len);
	printf("%s ", (expected == actual) ? GREEN"PASS"RESET : RED"FAIL"RESET);
}

void	test_concat(char *s1, char *s2, ssize_t s2_len, char *expected)
{
	char	*s1_in;
	size_t	s1_len = my_strlen(s1);
	size_t	i;
	s1_in = malloc((s1_len * sizeof(char)) + 1);
	i = 0;
	while (s1[i])
	{
		s1_in[i] = s1[i];
		i++;
	}
	s1_in[i] = '\0';
	concat(&s1_in, s2, s2_len);
	i = 0;
	while (s1[i] && expected[i] && s1[i] == expected[i])
		i++;
	printf("%s ", (s1_in[i] - expected[i] == 0) ? GREEN"PASS"RESET : RED"FAIL"RESET);
	free(s1_in);
	return ;	
}

void	test_get_newline(char *s1, ssize_t newline_index, char *expected)
{
	char	*actual = get_newline(s1, newline_index);
	printf("%s ", (my_strcmp(actual, expected) == 0) ? GREEN"PASS"RESET : RED"FAIL"RESET);
	free(actual);
}

int	main(void)
{
	// TEST: ssize_t get_newline_index(char *s1, ssize_t s1_len)
	printf("TEST get_newline_index: ");
	test_get_newline_index("", 0, -1);
	test_get_newline_index(0, -1, -1);
	test_get_newline_index("abcde", 5, -1);
	test_get_newline_index("Helloworld", 10, -1);
	test_get_newline_index("Hello\nworld", 11, 5);
	test_get_newline_index("Helloworld\n", 11, 10);
	test_get_newline_index("Hello\nworld\n", 12, 5);
	test_get_newline_index("Hello\nworld\n", 5, -1);
	printf("\n");

	// TEST: void    concat(char **s1, char *s2, ssize_t s2_len)
	printf("TEST concat: ");
	test_concat("", "", 0, "");
	test_concat("hello", "world", 5, "helloworld");
	test_concat("hello", "world", 3, "hellowor");
	test_concat("hello", "world", 0, "hello");
	test_concat("", "world", 5, "world");
	test_concat("", "world", 3, "wor");
	test_concat("hello", "", 0, "hello");
	test_concat("hello", "", -7, "hello");
	printf("\n");

	// TEST: char    *get_newline(char *s1, ssize_t newline_index)
	printf("TEST get_newline: ");
	test_get_newline("", -1, 0);
	test_get_newline("\n", 0, "\n");
	test_get_newline("\n\n", 0, "\n");
	test_get_newline("hello\nworld", 5, "hello\n");
	test_get_newline("hello\nworld\n", 5, "hello\n");
	printf("\n");
}
