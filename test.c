#include "get_next_line.h"
#include <stdio.h>

void	test_get_newline_index(char *s1, ssize_t s1_len, ssize_t expected)
{
	ssize_t actual = get_newline_index(s1, s1_len);
	printf("get_newline_index(");
	for (int i=0; i<s1_len;i++)
	{
		if (s1[i] == '\n') printf("\\n");
		else printf("%c", s1[i]);
	}
	printf(", %zd): %s\n", s1_len, (expected == actual) ? "PASS" : "FAIL");
}

int	main(void)
{
	// TEST: ssize_t get_newline_index(char *s1, ssize_t s1_len)
	test_get_newline_index("", 0, -1);
	test_get_newline_index(0, -1, -1);
	test_get_newline_index("abcde", 5, -1);
	test_get_newline_index("Helloworld", 10, -1);
	test_get_newline_index("Hello\nworld", 11, 5);
	test_get_newline_index("Helloworld\n", 11, 10);
	test_get_newline_index("Hello\nworld\n", 12, 5);
	test_get_newline_index("Hello\nworld\n", 5, -1);
}
