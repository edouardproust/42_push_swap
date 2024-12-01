/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:11:36 by eproust           #+#    #+#             */
/*   Updated: 2024/12/01 05:16:49 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_cost	get_cost_data(t_stack *from, t_stack *to)
{
	t_cost c;

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

static int	get_cost(t_cost c)
{
	if (c.to_left < 0) // b has reached top of stack using simultaneous moves only
		c.to_left = 0;
	if (c.to_left < c.to_cost)
		c.to_cost = c.to_left;
	return (c.from_cost + c.to_cost);
}

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
