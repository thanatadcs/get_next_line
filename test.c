#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

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

void	test_storage(char *storage, char *expected, char *(*f)(char *))
{
	char	*actual = f(storage);
	printf("%s ", (my_strcmp(actual, expected) == 0) ? GREEN"PASS"RESET : RED"FAIL"RESET);
	free(actual);
}

void	test_my_strjoin(char *storage, char *buf, char *expected)
{
	size_t	buf_len;

	buf_len = 0;
	while (buf[buf_len])
		buf_len++;
	char	*actual = my_strjoin(storage, buf, buf_len);
	printf("%s ", (my_strcmp(actual, expected) == 0) ? GREEN"PASS"RESET : RED"FAIL"RESET);
	free(actual);
}

int	main(void)
{
/*
	// TEST: char *get_return_line(char *storage);
	printf("get_return_line: ");
	test_storage("", "", get_return_line);
	test_storage("\n", "\n", get_return_line);
	test_storage("\n\n\n", "\n", get_return_line);
	test_storage("hello\nworld\nnaja\n", "hello\n", get_return_line);
	test_storage("hello", "hello", get_return_line);
	printf("\n");

	// TEST: char *update_storage(char *storage)
	printf("update_storage: ");
	test_storage("", "", update_storage);
	test_storage("\n", "", update_storage);
	test_storage("\n\n\n", "\n\n", update_storage);
	test_storage("hello\nworld\nnaja\n", "world\nnaja\n", update_storage);
	test_storage("hello", "hello", update_storage);
	printf("\n");

	// TEST: char *my_strjoin(char *storage, char *buf, ssize_t buf_len)
	printf("my_strjoin: ");
	test_my_strjoin("", "", "");
	test_my_strjoin("hi", "", "hi");
	test_my_strjoin("", "hi", "hi");
	test_my_strjoin(0, "hi", "hi");
	test_my_strjoin(0, "", "");
	test_my_strjoin("hello\n", "world\n", "hello\nworld\n");
	printf("\n");

	// TEST: char *read_line(char *storage, int fd)
	printf("--------------------- read_line: reading from ./texts/sample.txt --------------------- \n");
	int	fd = open("./texts/sample.txt", O_RDONLY);
	char *out; 
	while ((out = read_line(0, fd)))
	{
		printf("%s", out);
		free(out);
	}
	close(fd);
	printf("--------------------- read_line: end closed file --------------------- \n");

*/
	// TEST: char *get_next_line(int fd)
	printf("--------------------- read_line: reading from ./texts/sample.txt --------------------- \n");
	int fd = open("./texts/sample2.txt", O_RDONLY);
	char *line; 
	for (int i=0;i<35;i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("--------------------- read_line: end closed file --------------------- \n");
}
