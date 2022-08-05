# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanukool <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 17:13:01 by tanukool          #+#    #+#              #
#    Updated: 2022/08/05 18:03:52 by tanukool         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -I.

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m

NORM_FILE = get_next_line_utils.c get_next_line.h

define norm_check
	if [ -z $(norminette $(1) | grep 'Error!')]; then echo "NORM: ${GREEN}PASS${RESET}"; else echo "NORM: ${RED}FAIL${RESET}"; fi
endef

NAME = test_gnl 

u: norm
	@$(CC) $(CFLAGS) test.c get_next_line_utils.c -o $(NAME)
	@./test_gnl
	@rm -f test_gnl

m:

b:

norm:
	@$(call norm_check, $(NORM_FILE))

fclean:
	@rm -f test_gnl

.PHONY: u m b all fclean
