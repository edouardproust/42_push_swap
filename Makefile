NAME 	= push_swap

C_FILES	= push_swap.c

O_FILES	= $(C_FILES:.c=.o)

H_FILES	= push_swap.h
H_DIR	= ./

LIB_DIR	= libft/
A_LIB	= $(LIB_DIR)libft.a

FLAGS	= -Werror -Wall -Wextra -I $(H_DIR) -I $(LIB_DIR)

all: $(NAME)

%.o: %.c Makefile $(H_FILES)
	cc $(FLAGS) -c $< -o $@

$(NAME): $(O_FILES) $(A_LIB)
	cc $(FLAGS) -o $@ $(O_FILES) $(A_LIB)

$(A_LIB):
	$(MAKE) -C $(LIB_DIR) bonus

clean:
	rm -f $(O_FILES)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(A_LIB)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re 
