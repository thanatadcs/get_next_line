#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/*
void	test_get_newline(char *storage, char *expected)
{
	char	*actual = get_newline_update_storage(&storage, get_char_index(storage, '\n'));
	printf("%s ", (ft_strcmp(actual, expected) == 0) ? GREEN"PASS"RESET : RED"FAIL"RESET);
	free(actual);
}

void	test_update_storage(char *storage, char *expected)
{
	char *actual = ft_strdup(storage);
	update_storage(&actual, get_char_index(storage, '\n'));
	printf("%s ", (ft_strcmp(actual, expected) == 0) ? GREEN"PASS"RESET : RED"FAIL"RESET);
	free(actual);
}
*/

// printf("%s ", (my_strcmp(actual, expected) == 0) ? GREEN"PASS"RESET : RED"FAIL"RESET);

int	main(void)
{
/*
	printf("get_newline: ");
	test_get_newline("\n", "\n");
	test_get_newline("\n\n", "\n");
	test_get_newline("hello\n", "hello\n");
	test_get_newline("hello\nworld", "hello\n");
	test_get_newline("hello\nworld\n", "hello\n");
	printf("\n");

	printf("update_storage: ");
	test_update_storage("\n", "");
	test_update_storage("\n\n", "\n");
	test_update_storage("\n\n\n", "\n\n");
	test_update_storage("hello\n", "");
	test_update_storage("hello\nworld", "world");
	test_update_storage("hello\nworld\n", "world\n");
	printf("\n");

	// TEST: char *read_line(char *storage, int fd)
	printf("--------------------- read_line: reading from ./texts/sample.txt --------------------- \n");
	int	fd = open("./texts/sample.txt", O_RDONLY);
	char *storage = ft_strdup("");
	char *buf;
	for (int i = 0; i < 1; i++)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read_line(&storage, buf, fd);
		printf("%s", storage);
	}
	free(storage);
	close(fd);
	printf("\n--------------------- read_line: end closed file --------------------- \n");
	// TEST: char *get_next_line(int fd)
	printf("--------------------- get_next_line: reading from ./texts/sample.txt --------------------- \n");
	*/
	int fd = open("./texts/43_with_nl", O_RDONLY);
	char *line;
	for (int i=0; i<2;i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("\n--------------------- get_next_line: end closed file --------------------- \n");
}
