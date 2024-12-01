/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:43:16 by eproust           #+#    #+#             */
/*   Updated: 2024/12/01 02:55:16 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stacks_simult_rotate(char *move, t_stack **s1, t_stack **s2, t_cost *c)
{
	while (c->from_cost > 0 && c->to_cost > 0)
	{
		move_both(move, s1, s2);
		(c->from_cost)--;
		(c->to_cost)--;
	}
}

static void	stack_rotate(int dir, t_stack **stack, int n)
{
	char	*move;

	move = "r";
	if (dir == -1)
		move = "rr";	
	while (n-- > 0)
		move_one(move, stack);
}

void	rotate_nodes_on_top(t_stack **from, t_stack **to, t_cost *c)
{
	if (c->from_dir == 1 && c->to_dir == 1)
		stacks_simult_rotate("rr", from, to, c);
	if (c->from_dir == -1 && c->to_dir == -1)
		stacks_simult_rotate("rrr", from, to, c);
	stack_rotate(c->from_dir, from, c->from_cost);
	stack_rotate(c->to_dir, to, c->to_cost);
}

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

