# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 17:05:43 by eproust           #+#    #+#              #
#    Updated: 2024/12/03 04:38:38 by eproust          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

C_FILES	= moves_calc.c \
moves_def.c \
moves_def_do.c \
moves_target.c \
push_swap.c \
sort.c \
stack_rotate.c \
stack_utils2.c \
stack_utils.c \
utils.c \

C_BONUS = checker_bonus.c \
checker_utils_bonus.c \
moves_def.c \
moves_def_do.c \
stack_utils2.c \
stack_utils.c \
utils.c \

O_FILES = $(C_FILES:.c=.o)
O_BONUS = $(C_BONUS:.c=.o)

H_FILES = push_swap.h
H_DIR = ./

LIB_DIR = libft/
A_LIB = $(LIB_DIR)libft.a

FLAGS = -Werror -Wall -Wextra -I $(H_DIR) -I $(LIB_DIR)

all: $(NAME)

%.o: %.c Makefile $(H_FILES)
	cc $(FLAGS) -c $< -o $@

$(NAME): $(O_FILES) $(A_LIB)
	cc $(FLAGS) -o $@ $(O_FILES) $(A_LIB)

bonus: $(O_BONUS) $(A_LIB)
	cc -o $(NAME_BONUS) $(O_BONUS) $(A_LIB)

$(A_LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	rm -f $(O_FILES)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(A_LIB)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re 
