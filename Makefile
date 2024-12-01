# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 17:05:43 by eproust           #+#    #+#              #
#    Updated: 2024/12/01 18:47:26 by eproust          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

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

O_FILES = $(C_FILES:.c=.o)

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
