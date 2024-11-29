# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 15:20:43 by eproust           #+#    #+#              #
#    Updated: 2024/11/29 05:31:17 by eproust          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

ARGS		= 4 2 3 1

FLAGS		= -I$(ROOT_DIR) -I$(LIB_DIR) -I.

C_TEST		= test.c

ROOT_DIR	= ../
LIB_DIR		= $(ROOT_DIR)libft/
A_LIB		= $(LIB_DIR)libft.a
C_FILES		= $(filter-out $(wildcard ../*test*.c), $(wildcard ../*.c)) $(C_TEST)
H_FILES		= $(wildcard $(ROOT_DIR)*.h)
O_FILES		= $(C_FILES:.c=.o)

all: moves count check

%.o: %.c Makefile $(ROOT_DIR)Makefile $(H_FILES)
	cc $(FLAGS) -c $< -o $@

check: $(NAME)
	@echo "             ┌────────────────┐"
	@echo "─────────────┤ Checker output ├─────────────"
	@echo "             └────────────────┘"
	@ARG="$(ARGS)"; ./push_swap $$ARG | ./checker_linux $$ARG

count: $(NAME)
	@echo "              ┌─────────────┐"
	@echo "──────────────┤ Moves count ├───────────────"
	@echo "              └─────────────┘"
	@ARG="$(ARGS)"; ./push_swap $$ARG | grep -a -E '^(pa|pb|ra|rb|rra|rrb|sa|sb|rr|rrr)$$' | wc -l

moves: $(NAME)
	@echo "              ┌────────────┐"
	@echo "──────────────┤ Moves list ├────────────────"
	@echo "              └────────────┘"
	@./$(NAME) $(ARGS)

valgrind: $(NAME)
	@echo "             ┌───────────────┐"
	@echo "─────────────┤ Valgrind test ├──────────────"
	@echo "             └───────────────┘"
	@valgrind ./$(NAME) $(ARGS)

$(NAME): $(O_FILES) $(A_LIB)
	cc $(FLAGS) -o $@ $(O_FILES) $(A_LIB)

$(A_LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	rm -f $(O_FILES) $(wildcard $(ROOT_DIR)*.o)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(A_LIB)

re: fclean
	$(MAKE) all

.PHONY: all test leaks clean fclean re
