/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:10:48 by eproust           #+#    #+#             */
/*   Updated: 2024/11/27 03:26:17 by eproust          ###   ########.fr       */
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
	struct s_stack	*next;
}	t_stack;

// Sort
void	sort_dispatch(t_stack **a, t_stack **b);
void	move_cheapest(t_list **a, t_list **b, int *size_a, int *size_b);

// Moves
void	move_push(char *move, t_list **a, t_list **b, int *size_a, int *size_b);
void	move_one(char *move, t_list **stack);
void	move_both(char *move, t_list **a, t_list **b);
int		get_target(int smaller, t_list *current, t_list *targets,
			int *size_targets, t_list **target_node);

// Utils
void	free_matrix(char **arr);
void	error_exit(char **av, t_stack *stack, int is_malloc_av);
int		is_valid_number(char *n);

// Stack utils
t_stack	*new_node(int nb, int index);
t_stack	*last_node(t_stack *stack);
void	add_node_back(t_stack **stack, t_stack *new_node);
void	clear_stack(t_stack **stack);

// Stack extras
int		minmax_node(t_stack *stack, int find_max);
int		is_stack_sorted(t_stack *stack);

#endif
