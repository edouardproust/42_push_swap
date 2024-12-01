/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:34:57 by eproust           #+#    #+#             */
/*   Updated: 2024/12/02 00:24:55 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sorts a stack containing exactly three elements.
 *
 * Identifies the largest node in the stack and rotates it to the last 
 * position if needed. If the first two elements are not in order, swaps them.
 *
 * @param stack A pointer to the stack to be sorted.
 */
static void	sort_three(t_stack **stack)
{
	t_stack	*max;

	max = minmax_node(*stack, 1);
	if (max->index == 0)
		move_one("r", stack);
	else if (max->index == 1)
		move_one("rr", stack);
	if ((*stack)->nb > (*stack)->next->nb)
		move_one("s", stack);
}

/**
 * Sorts stacks `a` and `b` using the push-swap algorithm.
 *
 * - Moves elements from stack `a` to `b` in optimal order until stack `a`
 *   contains three nodes.
 * - Sorts the remaining nodes in `a` using `sort_three`.
 * - Moves elements from `b` back to `a` in an optimal order.
 * - Rotates stack `a` to ensure the smallest element is on top.
 *
 * @param a A pointer to the first stack.
 * @param b A pointer to the second stack.
 */
static void	sort_lists(t_stack **a, t_stack **b)
{
	while ((*a)->ssize > 3 && (!*b || (*b)->ssize < 2))
		move_push(a, b);
	while ((*a)->ssize > 3)
		push_cheapest(a, b);
	sort_three(a);
	while (*b && (*b)->ssize > 0)
		push_cheapest(b, a);
	rotate_smallest_on_top(a);
}

/**
 * Determines the optimal sorting strategy and applies it.
 *
 * - If the stack is already sorted, it returns immediately.
 * - If the stack contains two or three nodes, applies specific sorting 
 *   strategies for those cases.
 * - Otherwise, delegates to `sort_lists` for larger stacks.
 *
 * @param a A pointer to the first stack.
 * @param b A pointer to the second stack (initially empty).
 *
 * @note `update_stack_data(*a, 0, 1);` is used for size synchronization.
 *       This could potentially be optimized to avoid redundant loops.
 */
void	sort_dispatch(t_stack **a, t_stack **b)
{
	if (is_stack_sorted(*a))
		return ;
	update_stack_data(*a, 0, 1);
	if ((*a)->ssize == 2)
		move_one("s", a);
	else if ((*a)->ssize == 3)
		sort_three(a);
	else
		sort_lists(a, b);
}
