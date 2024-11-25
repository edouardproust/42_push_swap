/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:07:31 by eproust           #+#    #+#             */
/*   Updated: 2024/11/25 20:23:13 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Finds the closest smaller target node for the current node.
 * - returns target_index
 * - updates value of target_node (passed by reference)
 * - updates value targets stack size ('size_targets' passed by reference)
 */
static int	get_target(int smaller, t_list *current, t_list *targets, int *size_targets, t_list **target_node)
{
	t_list	*bound_node;
	int		bound_index;
	int		target_index;
	int		i;

	bound_node = NULL;
	*target_node = NULL;
	i = 0;
	while (targets)
	{
		if ((smaller && get_val(targets) > get_val(bound_node))
			|| (!smaller && get_val(targets < get_vall(bound_node))))
		{
			bound_index = i;
			bound_node = targets;
		}
		if (
			(smaller && get_val(targets) < get_val(current) && (!(*target_node) || get_val(targets) > get_val(*target_node))) || 
			(!smaller && get_val(targets) > get_val(current) && (!(*target_node) || get_val(targets) < get_val(*target_node)))
			)
		{
			target_index = i;
			*target_node = targets;
		}
		targets = targets->next;
		i++;
	}
	if (!(*target_node))
	{
		*target_node = bound_node;
		target_index = bound_index;
	}
	*size_targets = i;
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
	int	dir_b;
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
	dir_b = 1;
	if (index_b > size_b / 2)
	{
		cost_b = size_b - index_b;
		dir_b = -1;
	}
	// Deduct potential simultaneous moves
	if (size_a == 2)
		dir = dir_b;
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
static void	do_moves(t_list *a_node, t_list *b_node, t_list **a, t_list **b, int *size_a, int *size_b)
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

	// Rotate A & B
	printf("--- Rotate A & B (TODO: kernel algo) ----------------------------\n"); // TODO Delete this line
	while (a_node != *a)
		move_one("ra", a);
	while (b_node != *b)
		move_one("rb", b);
	// Push a
	move_push("pb", a, b, size_a, size_b);
}


// TODO Remove function
static void	do_moves2(t_list *a_node, t_list *b_node, t_list **a, t_list **b, int *size_a, int *size_b)
{	
	// Rotate A & B
	printf("--- Rotate A & B (TODO: BACK TRIP!) ----------------------------\n"); // TODO Delete this line
	while (b_node != *b)
		move_one("rb", b);
	while (a_node != *a)
		move_one("ra", a);
	// Push a
	move_push("pa", b, a, size_b, size_a);
}

void	get_cheapest(int smaller, t_list **cheapest, t_list **cheapest_target, t_list *a, t_list *b, int *size_a, int *size_b)
{
	t_list	*target_node;
	int		target_index;
	int		cost;
	int		min_cost;
	int		i;

	*cheapest = NULL;
	*cheapest_target = NULL;
	min_cost = INT_MAX;
	i = 0;
	while (a && cost != 0)
	{
		target_index = get_target(smaller, a, b, size_b, &target_node);	
		cost = calc_moves(i, target_index, *size_a, *size_b);
		if (cost < min_cost)
		{
			min_cost = cost; 
			*cheapest = a;
			*cheapest_target = target_node;
		}
		printf("(%d: nb = %d | target_index = %d | cost = %d)\n", i, get_val(a), target_index, cost); // TODO Delete this line
		a = a->next;
		i++;
	}
}

void	calc_do_moves(t_list **a, t_list **b, int *size_a, int *size_b)
{
	t_list	*cheapest;
	t_list	*cheapest_target;

	get_cheapest(1, &cheapest, &cheapest_target, *a, *b, size_a, size_b);
	printf("[cheapest: nb = %d | target_nb = %d]\n", get_val(cheapest), get_val(cheapest_target)); // TODO Delete this line	
	do_moves(cheapest, cheapest_target, a, b, size_a, size_b);
	//printf("{%d}", get_val(*a));
}

void	push_all_back_to_a(t_list **a, t_list **b, int *size_a, int *size_b)
{
	t_list	*cheapest;
	t_list	*cheapest_target;

	get_cheapest(0, &cheapest, &cheapest_target, *b, *a, size_b, size_a);
	//move_push("pa", a, b, size_a, size_b);
	do_moves2(cheapest, cheapest_target, b, a, size_b, size_a);
}
