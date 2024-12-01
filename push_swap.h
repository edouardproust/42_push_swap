/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:10:48 by eproust           #+#    #+#             */
/*   Updated: 2024/12/01 15:03:31 by eproust          ###   ########.fr       */
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
	char			sname;
	int				ssize;
	struct s_stack	*next;
}	t_stack;

typedef struct s_cost
{
	int	from_dir;
	int	from_cost;
	int	to_dir;
	int	to_cost;
	int	to_left;
}	t_cost;

// Sort
void	sort_dispatch(t_stack **a, t_stack **b);

// moves_calc.c
void	push_cheapest(t_stack **from, t_stack **to);

// moves_target.c
void	set_node_target(t_stack *from_node, t_stack *to_stack);

// moves_def.c
void	move_push(t_stack **from, t_stack **to);
void	move_one(char *move, t_stack **stack);
void	move_both(char *move, t_stack **a, t_stack **b);

// moves_def_do.c
int		do_push(t_stack **from, t_stack **to);
int		do_swap(t_stack **stack);
int		do_rotate(t_stack **stack);
int		do_rev_rotate(t_stack **stack);

// stack_rotate.c
void	rotate_nodes_on_top(t_stack **from, t_stack **to, t_cost *c);
void	rotate_smallest_on_top(t_stack **stack);

// stack_utils.c
t_stack	*new_node(int nb);
t_stack	*last_node(t_stack *stack);
void	add_node_back(t_stack **stack, t_stack *new_node);
void	add_node_front(t_stack **stack, t_stack *new_node);
void	clear_stack(t_stack **stack);

// stack_utils2.c
void	update_stack_data(t_stack *stack, int updte_indexes, int updte_ssize);
t_stack	*minmax_node(t_stack *stack, int find_max);
int		is_stack_sorted(t_stack *stack);

// utils.c
void	free_matrix(char **arr);
void	error_exit(char **av, t_stack *stack, int is_malloc_av);
int		is_valid_number(char *n);

#endif
