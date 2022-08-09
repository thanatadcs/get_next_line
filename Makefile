# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanukool <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 17:13:01 by tanukool          #+#    #+#              #
#    Updated: 2022/08/09 11:32:21 by tanukool         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -I. -L. -lft

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m

NORM_FILE = get_next_line_utils.c get_next_line.h get_next_line.c

define norm_check
	if [ -z $(shell norminette $(NORM_FILE) | grep 'Error!' | wc -l | awk '{print $$1}') ]; then echo "NORM: ${GREEN}PASS${RESET}"; else echo "NORM: ${RED}FAIL${RESET}"; fi
endef

define leak_check
	leaks --atExit -- $(addprefix ./, $(NAME)) 2> /dev/null | awk '/leaked/ {print "LEAK:", $$3}'
endef

NAME = test_gnl 

BUF ?= $(shell bash -c 'read -p "BUFFER_SIZE = " buf; echo $$buf')


b:
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUF) test.c get_next_line_utils_bonus.c get_next_line_bonus.c -o $(NAME)
	@$(addprefix ./, $(NAME))
	@$(call leak_check, $(NAME))
	@rm -rf $(NAME)

m:
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUF) test.c get_next_line_utils.c get_next_line.c -o $(NAME)
	@$(addprefix ./, $(NAME))
	@$(call leak_check, $(NAME))
	@rm -rf $(NAME)

test:
	@$(CC) $(CFLAGS) -D test.c get_next_line_utils.c get_next_line.c -o $(NAME)
	@$(addprefix ./, $(NAME))
	@$(call leak_check, $(NAME))
	@rm -rf $(NAME)

norm:
	@norminette $(NORM_FILE)

fclean:
	@rm -f test_gnl

.PHONY: u m b all fclean
