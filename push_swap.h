/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:10:48 by eproust           #+#    #+#             */
/*   Updated: 2024/11/29 03:49:41 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				nb;
	int				index;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

// Sort
void	sort_dispatch(t_stack **a, t_stack **b);
void    push_cheapest(char to_name, t_stack **from, t_stack **to,
			int *size_from, int *size_to);
void	get_cheapest(char to_name, t_stack **cheapest, t_stack **target,
			t_stack *a, t_stack *b, int *size_a, int *size_b);

// Moves calculation
void	set_target(char to_name, t_stack *from_node, t_stack *to_stack,
			int *to_size);

// Moves definition
void	move_push(t_stack **from, t_stack **to, char to_name, int *size_a, int *size_b);
void	move_one(char *move, t_stack **stack, char stack_name);
void	move_both(char *move, t_stack **a, t_stack **b);
int		do_push(t_stack **from, t_stack **to);
int		do_swap(t_stack **stack);
int		do_rotate(t_stack **stack);
int		do_rev_rotate(t_stack **stack);

// Utils
void	free_matrix(char **arr);
void	error_exit(char **av, t_stack *stack, int is_malloc_av);
int		is_valid_number(char *n);

// Stack utils
void	update_indexes(t_stack *stack);
int		stack_size(t_stack *stack);
t_stack	*new_node(int nb, int index);
t_stack	*last_node(t_stack *stack);
void	add_node_back(t_stack **stack, t_stack *new_node);
void	add_node_front(t_stack **stack, t_stack *new_node);
void	clear_stack(t_stack **stack);

// Stack extras
t_stack	*minmax_node(t_stack *stack, int find_max);
int		is_stack_sorted(t_stack *stack);

#endif
