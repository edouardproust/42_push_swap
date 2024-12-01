# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 15:20:43 by eproust           #+#    #+#              #
#    Updated: 2024/12/01 18:08:12 by eproust          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ../push_swap

ARGS		= -9000 7401 -4041 8192 -4877 -8356 2027 19 128 -1261 -6008 -1961 5153 2475 7637 -5841 8413 -993 4442 -2015 4977 4472 -2244 1373 5492 6777 -124 -279 4445 -9607 6401 5072 5042 3621 -1604 -7859 8713 -9938 -9527 -2385 -6649 -2871 -606 -4754 -8609 7134 -6161 2529 977 -3392 8139 5514 9936 -4161 -9467 -835 2062 9242 -9561 -4071 4710 5885 6117 4780 4565 6027 -5776 2261 3346 -1528 -5673 -5282 -2421 -6755 -1226 6506 -4737 9512 806 -4300 -2465 -7131 8220 306 2167 732 549 5576 -9595 -1305 -5862 -9462 6555 -7805 -9619 5436 -2432 -3029 -8312 -8571

FLAGS		= -I$(ROOT_DIR) -I$(LIB_DIR) -I.

C_TEST		= debug.c debug_utils.c

ROOT_DIR	= ../
LIB_DIR		= $(ROOT_DIR)libft/
A_LIB		= $(LIB_DIR)libft.a
C_FILES		= $(filter-out $(wildcard ../*test*.c), $(wildcard ../*.c)) $(C_TEST)
H_FILES		= $(wildcard $(ROOT_DIR)*.h)
O_FILES		= $(C_FILES:.c=.o)

all: moves count check

%.o: %.c Makefile $(ROOT_DIR)Makefile $(H_FILES)
	cc $(FLAGS) -c $< -o $@

$(NAME): $(O_FILES) $(A_LIB)
	cc $(FLAGS) -o $@ $(O_FILES) $(A_LIB)

$(A_LIB):
	$(MAKE) -C $(LIB_DIR)

check: $(NAME)
	@echo "             ┌────────────────┐"
	@echo "─────────────┤ Checker output ├─────────────"
	@echo "             └────────────────┘"
	@$(NAME) $(ARGS) | ./checker_linux $(ARGS)

count: $(NAME)
	@echo "              ┌─────────────┐"
	@echo "──────────────┤ Moves count ├───────────────"
	@echo "              └─────────────┘"
	@$(NAME) $(ARGS) | wc -l

moves: $(NAME)
	@echo "              ┌────────────┐"
	@echo "──────────────┤ Moves list ├────────────────"
	@echo "              └────────────┘"
	@$(NAME) $(ARGS)

valgrind: $(NAME)
	@echo "             ┌───────────────┐"
	@echo "─────────────┤ Valgrind test ├──────────────"
	@echo "             └───────────────┘"
	@valgrind $(NAME) $(ARGS)

loop: $(NAME)
	@RESULT="$$($(NAME) $(ARGS))"; \
	LINE_COUNT=$$(echo "$$RESULT" | wc -l); \
	CHECK=$$(echo "$$RESULT" | ./checker_linux $(ARGS)); \
	echo "\n$$LINE_COUNT $$CHECK ";

clean:
	rm -f $(O_FILES) $(wildcard $(ROOT_DIR)*.o)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(A_LIB)

re: fclean
	$(MAKE) all

.PHONY: all check count moves valgrind loop clean fclean re
