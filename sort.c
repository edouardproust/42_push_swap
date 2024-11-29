/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:34:57 by eproust           #+#    #+#             */
/*   Updated: 2024/11/29 04:55:40 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Moves the smallest node to the top of the stack.
 *
 * Rotates or reverse-rotates the stack based on the smallest node's
 * position to minimize the number of moves.
 *
 * @param stack	Pointer to the stack to modify.
 * @param size	The size of the stack.
 */
static void	rotate_smallest_on_top(t_stack **stack, int size)
{
	t_stack	*min;
	int		rotations;
	char	*move;

	if (!stack)
		return ;
	min = minmax_node(*stack, 0);
	rotations = min->index;
	move = "r";
	if (min->index > size / 2)
	{
		rotations = size - min->index;
		move = "rr";
	}
	while (rotations-- > 0)
		move_one(move, stack, 'a');
}

/**
 * Sorts a stack of size 3 by performing rotations and swaps.
 *
 * The function places the largest element at the top of the stack,
 * then places the stack in ascending order.
 * 
 * @param stack  A pointer to the stack to sort (of size 3).
 */
static void	sort_three(t_stack **stack)
{
	t_stack	*max;

	max = minmax_node(*stack, 1);
	if (max->index == 0)
		move_one("r", stack, 'a');
	else if (max->index == 1)
		move_one("rr", stack, 'a');
	if ((*stack)->nb > (*stack)->next->nb)
		move_one("s", stack, 'a');
}

/**
 * Sorts stack 'a' when it contains more than 3 nodes.
 * 
 * 1. Move up to 2 nodes to stack 'b'.
 * 2. Continue moving nodes to stack 'b' in decreasing order.
 * 3. Sort the remaining 3 nodes in stack 'a'.
 * 4. Push all nodes back from 'b' to 'a' in increasing order.
 * 5. Position the smallest node at the top of stack 'a'.
 *
 * @param a        A pointer to the first stack.
 * @param b        A pointer to the second stack.
 * @param size_a   The size of stack 'a'.
 */
static void	sort_lists(t_stack **a, t_stack **b, int size_a)
{
	int		size_b;

	size_b = 0;
	while (size_a > 3 && size_b < 2)
		move_push(a, b, 'b', &size_a, &size_b);
	while (size_a > 3)
		push_cheapest('b', a, b, &size_a, &size_b);
	sort_three(a);
	while (size_b > 0)
		push_cheapest('a', b, a, &size_b, &size_a);		
	rotate_smallest_on_top(a, size_a);
}

/**
 * Dispatches sorting based on the size of stack 'a'.
 *
 * Sorts directly for stacks with 2 or 3 nodes, delegates to 
 * 'sort_lists' for larger stacks. 
 * 
 * @param a    A pointer to the first stack.
 * @param b    A pointer to the second stack.
 */
void	sort_dispatch(t_stack **a, t_stack **b)
{
	int	size_a;

	if (is_stack_sorted(*a))
		return ;
	size_a = stack_size(*a);
	if (size_a == 2)
		move_one("s", a, 'a');
	else if (size_a == 3)
		sort_three(a);
	else
		sort_lists(a, b, size_a);
}
