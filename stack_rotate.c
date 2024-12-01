/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:43:16 by eproust           #+#    #+#             */
/*   Updated: 2024/12/02 00:03:31 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Simultaneously rotates two stacks in the same direction.
 *
 * Applies the "rr" or "rrr" operation to both stacks while decrementing
 * the respective costs in `t_cost`. Stops when either cost reaches 0.
 *
 * @param move A string representing the operation ("rr" or "rrr").
 * @param s1 A pointer to the first stack.
 * @param s2 A pointer to the second stack.
 * @param c A pointer to the cost structure.
 */
static void	stacks_simult_rotate(char *move, t_stack **s1, t_stack **s2,
	t_cost *c)
{
	while (c->from_cost > 0 && c->to_cost > 0)
	{
		move_both(move, s1, s2);
		(c->from_cost)--;
		(c->to_cost)--;
	}
}

/**
 * Rotates a stack in a specified direction for a given number of moves.
 *
 * Performs either a "rotate" (r) or "reverse rotate" (rr) operation on
 * the stack `n` times, based on the direction.
 *
 * @param dir The direction of rotation: 1 for "r", -1 for "rr".
 * @param stack A pointer to the stack to rotate.
 * @param n The number of rotations to perform.
 */
static void	stack_rotate(int dir, t_stack **stack, int n)
{
	char	*move;

	move = "r";
	if (dir == -1)
		move = "rr";
	while (n-- > 0)
		move_one(move, stack);
}

/**
 * Adjusts two stacks so that the targeted nodes are positioned on top.
 *
 * Combines simultaneous rotations ("rr" or "rrr") if possible to optimize
 * movement, then completes the required rotations for each stack individually.
 *
 * @param from A pointer to the source stack.
 * @param to A pointer to the destination stack.
 * @param c A pointer to the cost structure containing direction and costs.
 */
void	rotate_nodes_on_top(t_stack **from, t_stack **to, t_cost *c)
{
	if (c->from_dir == 1 && c->to_dir == 1)
		stacks_simult_rotate("rr", from, to, c);
	if (c->from_dir == -1 && c->to_dir == -1)
		stacks_simult_rotate("rrr", from, to, c);
	stack_rotate(c->from_dir, from, c->from_cost);
	stack_rotate(c->to_dir, to, c->to_cost);
}

/**
 * Rotates the stack to bring the smallest element to the top.
 *
 * Identifies the node with the smallest value in the stack and rotates
 * the stack in the most efficient direction to place it at the top.
 *
 * @param stack A pointer to the stack to adjust.
 */
void	rotate_smallest_on_top(t_stack **stack)
{
	t_stack	*min;

	if (!stack)
		return ;
	min = minmax_node(*stack, 0);
	if (min->index > (*stack)->ssize / 2)
		stack_rotate(-1, stack, (*stack)->ssize - min->index);
	else
		stack_rotate(1, stack, min->index);
}
