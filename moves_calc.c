/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:11:36 by eproust           #+#    #+#             */
/*   Updated: 2024/12/02 00:26:55 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Calculates the cost to move a node from one stack to another.
 * 
 * The cost is based on the index of the node in its original stack and the
 * target stack. The direction of movement (either forward or backward) is 
 * also determined by the index in relation to the stack size.
 * 
 * @param from The stack from which the node is being moved.
 * @param to The target stack where the node is being moved.
 * @return A t_cost structure containing the cost data for both stacks.
 */
static t_cost	get_cost_data(t_stack *from, t_stack *to)
{
	t_cost	c;

	c.from_cost = from->index;
	c.from_dir = 1;
	if (from->index > from->ssize / 2)
	{
		c.from_cost = from->ssize - from->index;
		c.from_dir = -1;
	}
	c.to_cost = to->index;
	c.to_dir = 1;
	if (to->index > to->ssize / 2)
	{
		c.to_cost = to->ssize - to->index;
		c.to_dir = -1;
	}
	if (from->ssize == 2)
		c.from_dir = c.to_dir;
	if (to->ssize == 2)
		c.to_dir = c.from_dir;
	if (c.from_dir == 1)
		c.to_left = to->index - c.from_cost;
	else
		c.to_left = (to->ssize - to->index) - c.from_cost;
	return (c);
}

/**
 * Calculates the total cost to move a node from one stack to another.
 * 
 * The total cost is the sum of the costs from both the `from` and `to` stacks.
 * Additionally, it ensures that if the `to_left` cost is negative, it is set
 * to 0 to avoid invalid costs.
 * 
 * @param c A t_cost structure containing the cost data.
 * @return The total cost of the move.
 */
static int	get_cost(t_cost c)
{
	if (c.to_left < 0)
		c.to_left = 0;
	if (c.to_left < c.to_cost)
		c.to_cost = c.to_left;
	return (c.from_cost + c.to_cost);
}

/**
 * Finds the cheapest move to push from one stack to another.
 * 
 * Iterates through the `from` stack, calculates the move cost for each node, 
 * selects the cheapest move, rotates both stacks as needed, and performs
 * the push.
 * 
 * @param from A pointer to the source stack from which the node is being moved.
 * @param to A pointer to the destination stack where the node will be moved.
 */
void	push_cheapest(t_stack **from, t_stack **to)
{
	t_cost	cost_data;
	t_cost	cheapest_cost_data;
	int		cost;
	int		min_cost;
	t_stack	*current;

	cost = INT_MAX;
	min_cost = INT_MAX;
	current = *from;
	while (current && cost != 0)
	{
		set_node_target(current, *to);
		cost_data = get_cost_data(current, current->target);
		cost = get_cost(cost_data);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest_cost_data = cost_data;
		}
		else
			current->target = NULL;
		current = current->next;
	}
	rotate_nodes_on_top(from, to, &cheapest_cost_data);
	move_push(from, to);
}
