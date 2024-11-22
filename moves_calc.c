/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:07:31 by eproust           #+#    #+#             */
/*   Updated: 2024/11/24 21:01:02 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Finds the target node in stack B: returns target_index and updates value
 * of target_node.
 * Also updates value of size_b
 */
static int	get_target(t_list *an, t_list *b, int *size_b, t_list **target_node)
{
	t_list	*max_node;
	int		max_index;
	int		target_index;
	int		i;

	max_node = NULL;
	*target_node = NULL;
	i = 0;
	while (b)
	{
		if (get_val(b) > get_val(max_node))
		{
			max_index = i;
			max_node = b;
		}
		if (get_val(b) < get_val(an)
			&& (!(*target_node) || get_val(b) > get_val(*target_node)))
		{
			target_index = i;
			*target_node = b;
		}
		b = b->next;
		i++;
	}
	if (!(*target_node))
	{
		*target_node = max_node;
		target_index = max_index;
	}
	*size_b = i;
	return (target_index);
}

// TODO Add the 'ss' move case
/*
 * Calculates the minimum moves to position elements at `index_a` and `index_b` 
 * on top of stacks A and B, respectively.
 * Move directions: 1 for rotate, -1 for reverse rotate.
 */
static int	calc_moves(int index_a, int index_b, int size_a, int size_b)
{
	int	dir;
	int	cost_a;
	int	cost_b;
	int	left_b;
	
	// If a above median: rotate a. Else, rev_rotate a.
	cost_a = index_a;
	dir = 1;
	if (index_a > size_a / 2)
	{
		cost_a = size_a - index_a;
		dir = -1;
	}
	// Do the same for b: Calculate cost_b independently of dir
	cost_b = index_b;
	if (index_b > size_b / 2)
		cost_b = size_b - index_b;
	// Deduct potential simultaneous moves
	if (dir == 1)
		left_b = index_b - cost_a;
	else if (dir == -1)
		left_b = (size_b - index_b) - cost_a;
	if (left_b < 0) // b has reached top of stack using simultaneous moves only. TODO refactoring using `left_b = ft_max(left_b, 0);`
		left_b = 0;
	if (left_b < cost_b) // TODO Refactoring using `cost_b = ft_min(cost_b, left_b);`
		cost_b = left_b;
	return (cost_a + cost_b);
}

// TODO Add the 'ss' move case
static void	do_moves(t_list *a_node, t_list *b_node, t_list *a, t_list *b, int *size_a, int size_b)
{	
	/* Rotate stacks
	//----- Begening similar part --------------------------//
	cost_a = index_a;
	dir = 1;
	if (index_a > size_a / 2)
	{
		cost_a = size_a - index_a;
		dir = -1;
	}
	cost_b = index_b;
	if (index_b > size_b / 2)
		cost_b = size_b - index_b;
	if (dir == 1)
		left_b = index_b - cost_a;
	else if (dir == -1)
		left_b = (size_b - index_b) - cost_a;
	//----- End of similar part ------------------------------//
	if (left_b <= 0)
		if (dir == 1)
			move_both("rr", a, b); // TODO Repeat 'cost_a + left_b' times
			move_one("ra", a); // TODO Repeat '-left_b' times
		else
			move_both("rrr", a, b); // TODO Repeat 'cost_a + left_b' times
			move_one("rra", a); // TODO Repeat '-left_b' times
	else if (left_b < cost_b)
		if (dir == 1)
			move_both("rr", a, b); // TODO Repeat 'cost_a' times
			move_one("rb", b); // TODO Repeat 'cost_b - cost-a' times 
		else
			TODO
	else if
			
	*/	

	// Push a
	move_push("pb", &a, &b);
	*size_a -= 1;
}

void	calc_do_moves(t_list *a, t_list *b, int *size_a)
{
	int		cost;
	int		min_cost;
	int		size_b;
	t_list	*target_node;
	int		target_index;
	t_list	*cheapest;
	t_list	*cheapest_target;
	int		i;
	t_list	*a_tmp; // TODO refactoring so i don't need `a_tmp` variable

	a_tmp = a;
	cheapest = 0;
	min_cost = INT_MAX;
	i = 0;
	while (a && cost != 0)
	{
		target_index = get_target(a, b, &size_b, &target_node);	
		cost = calc_moves(i, target_index, *size_a, size_b);
		if (cost < min_cost)
		{
			min_cost = cost; 
			cheapest = a;
			cheapest_target = target_node;
		}
		printf("(%d: nb = %d | target_index = %d | cost = %d)\n", i, get_val(a), target_index, cost); // TODO Delete this line
		a = (a)->next;
		i++;
 	}
	printf("[cheapest: nb = %d | target_nb = %d | min_cost = %d]\n", get_val(cheapest), get_val(cheapest_target), min_cost); // TODO Delete this line	
	do_moves(cheapest, cheapest_target, a_tmp, b, size_a, size_b);
}
