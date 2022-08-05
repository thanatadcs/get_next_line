all:
	@gcc -Wall -Werror -Wextra test.c get_next_line_utils.c get_next_line.h
	@./a.out
	@rm a.out
