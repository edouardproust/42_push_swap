# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 15:20:43 by eproust           #+#    #+#              #
#    Updated: 2024/11/21 19:15:25 by eproust          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

ARGS		= 1 2 3 4

FLAGS   	= -I$(ROOT_DIR) -I$(LIB_DIR) -I.

C_TEST		= test.c

ROOT_DIR	= ../
LIB_DIR		= $(ROOT_DIR)libft/
A_LIB		= $(LIB_DIR)libft.a
C_FILES		= $(filter-out $(wildcard ../*test*.c), $(wildcard ../*.c)) $(C_TEST)
H_FILES		= $(wildcard $(ROOT_DIR)*.h)
O_FILES		= $(C_FILES:.c=.o)

TEST_TITLE	= "\n┌──────────────┐\n| Test result: |\n└──────────────┘\n"

all: test

%.o: %.c Makefile $(ROOT_DIR)Makefile $(H_FILES)
	cc $(FLAGS) -c $< -o $@

test: $(NAME)
	@echo $(TEST_TITLE)
	@./$(NAME) $(ARGS)
	@rm -f $(NAME)
	
leaks: $(NAME)
	@echo $(TEST_TITLE)
	@valgrind ./$(NAME) $(ARGS)
	@rm -f $(NAME)

$(NAME): $(O_FILES) $(A_LIB)
	cc $(FLAGS) -o $@ $(O_FILES) $(A_LIB)

$(A_LIB):
	$(MAKE) -C $(LIB_DIR) bonus

clean:
	rm -f $(O_FILES) $(wildcard $(ROOT_DIR)*.o)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(A_LIB)

re: fclean
	$(MAKE) all

.PHONY: all test leaks clean fclean re
