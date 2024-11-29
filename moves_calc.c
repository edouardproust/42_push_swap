/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:11:36 by eproust           #+#    #+#             */
/*   Updated: 2024/11/29 05:47:04 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct	s_cost
{
	int	dir_from;
	int	dir_to;
	int	cost_from;
	int	cost_to;
	int	left_to;
}	t_cost;

static t_cost	get_cost_data(t_stack *from, t_stack *to, int size_from, int size_to)
{
	t_cost c;

	c.cost_from = from->index;
	c.dir_from = 1;
	if (from->index > size_from / 2)
	{
		c.cost_from = size_from - from->index;
		c.dir_from = -1;
	}
	c.cost_to = to->index;
	c.dir_to = 1;
	if (to->index > size_to / 2)
	{
		c.cost_to = size_to - to->index;
		c.dir_to = -1;
	}
	if (size_from == 2)
		c.dir_from = c.dir_to;
	if (size_to == 2)
		c.dir_to = c.dir_from;
	if (c.dir_from == 1)
		c.left_to = to->index - c.cost_from;
	else
		c.left_to = (size_to - to->index) - c.cost_from;
	return (c);
}

static int	get_cost(t_cost c)
{
	if (c.left_to < 0) // b has reached top of stack using simultaneous moves only
		c.left_to = 0;
	if (c.left_to < c.cost_to)
		c.cost_to = c.left_to;
	return (c.cost_from + c.cost_to);
}

static void	rotate_both(char *move, int *cost_from, int *cost_to, t_stack **from, t_stack **to)
{
	while (*cost_from > 0 && *cost_to > 0)
	{
		move_both(move, from, to);
		(*cost_from)--;
		(*cost_to)--;
	}
}

static void	rotate_one(int dir, char stack_name, int *cost, t_stack **stack)
{
	char	*move;

	move = "r";
	if (dir == -1)
		move = "rr";	
	while ((*cost)-- > 0)
		move_one(move, stack, stack_name);
}

static void	move_nodes_on_top(t_stack **from, t_stack **to, t_cost *c, char to_name)
{
	if (c->dir_from == 1 && c->dir_to == 1)
		rotate_both("rr", &c->cost_from, &c->cost_to, from, to);
	if (c->dir_from == -1 && c->dir_to == -1)
		rotate_both("rrr", &c->cost_from, &c->cost_to, from, to);
	if (to_name == 'a')
		rotate_one(c->dir_from, 'b', &c->cost_from, from);
	else
		rotate_one(c->dir_from, 'a', &c->cost_from, from);
	rotate_one(c->dir_to, to_name, &c->cost_to, to);
}

void	push_cheapest(char to_name, t_stack **from, t_stack **to, int *size_from, int *size_to)
{
	t_cost	cost_data;
	t_cost	cheapest_cost_data;
	int		cost;
	int		min_cost;
	t_stack	*f;

	cost = INT_MAX;
	min_cost = INT_MAX;

	f = *from;
	while (f && cost != 0)
	{
		set_target(to_name, f, *to, size_to);
		cost_data = get_cost_data(f, f->target, *size_from, *size_to);
		cost = get_cost(cost_data);
	//	printf("(nb: %d, target->nb: %d, cost: %d)\n", f->nb, f->target->nb, cost); // TODO
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest_cost_data = cost_data;
		}
		f = f->next;
	}
	move_nodes_on_top(from, to, &cheapest_cost_data, to_name);
	move_push(from, to, to_name, size_from, size_to);
}
