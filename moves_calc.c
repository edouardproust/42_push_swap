/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:07:31 by eproust           #+#    #+#             */
/*   Updated: 2024/11/27 03:54:42 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct	s_cost
{
	int	dir_a;
	int	dir_b;
	int	cost_a;
	int	cost_b;
	int	left_b;
}	t_cost;

// TODO Add the 'ss' move case
t_cost	get_move_data(int index_a, int index_b, int size_a, int size_b)
{
	t_cost data = {0}; // Tous les champs sont mis à 0

	// If a above median: rotate a. Else, rev_rotate a.
	data.cost_a = index_a;
	data.dir_a = 1;
	if (index_a > size_a / 2)
	{
		data.cost_a = size_a - index_a;
		data.dir_a = -1;
	}
	// Do the same for b: Calculate cost_b independently of dir
	data.cost_b = index_b;
	data.dir_b = 1;
	if (index_b > size_b / 2)
	{
		data.cost_b = size_b - index_b;
		data.dir_b = -1;
	}
	// Deduct potential simultaneous moves
	if (size_a == 2)
		data.dir_a = data.dir_b;
	if (data.dir_a == 1)
		data.left_b = index_b - data.cost_a;
	else if (data.dir_a == -1)
		data.left_b = (size_b - index_b) - data.cost_a;
	return (data);
}

/*
 * Calculates the minimum moves to position elements at `index_a` and `index_b` 
 * on top of stacks A and B, respectively.
 * Move directions: 1 for rotate, -1 for reverse rotate.
 */
static int	get_move_cost(int index_a, int index_b, int size_a, int size_b)
{
	t_cost	c;

	c = get_move_data(index_a, index_b, size_a, size_b);
	if (c.left_b < 0) // b has reached top of stack using simultaneous moves only. TODO refactoring using `left_b = ft_max(left_b, 0);`
		c.left_b = 0;
	if (c.left_b < c.cost_b) // TODO Refactoring using `cost_b = ft_min(cost_b, left_b);`
		c.cost_b = c.left_b;
	return (c.cost_a + c.cost_b);
}

// TODO Add the 'ss' move case
static void	do_moves(t_list *a_node, t_list *b_node, t_list **a, t_list **b, int *size_a, int *size_b)
{		
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

void	get_cheapest(int find_smaller, t_stack **cheapest, t_stack **cheapest_target, t_stack *a, t_stack *b, int *size_a, int *size_b)
{
	t_list	*target;
	int		cost;
	int		min_cost;
	int		i;

	*cheapest = NULL;
	*cheapest_target = NULL;
	min_cost = INT_MAX;
	
	i = 0;
	while (a && cost != 0)
	{
		target = get_target(find_smaller, a, b, size_b, &target_node);	
		cost = get_move_cost(i, target, *size_a, *size_b);
		if (cost < min_cost)
		{
			min_cost = cost; 
			*cheapest = a;
			*cheapest_target = target_node;
		}
		printf("(%d: nb = %d | target_index = %d | cost = %d)\n", i, a->nb, target_index, cost); // TODO Delete this line
		a = a->next;
		i++;
	}
}

void	move_cheapest(t_list **a, t_list **b, int *size_a, int *size_b)
{
	t_list	*cheapest;
	t_list	*cheapest_target;

	get_cheapest(1, &cheapest, &cheapest_target, *a, *b, size_a, size_b);
	printf("[cheapest: nb = %d | target_nb = %d]\n", cheapest->nb, cheapest_target->nb); // TODO Delete this line	
	do_moves(cheapest, cheapest_target, a, b, size_a, size_b);
}

void	push_all_back_to_a(t_list **a, t_list **b, int *size_a, int *size_b)
{
	t_list	*cheapest;
	t_list	*cheapest_target;

	get_cheapest(0, &cheapest, &cheapest_target, *b, *a, size_b, size_a);
	do_moves2(cheapest, cheapest_target, b, a, size_b, size_a);
}

/**
 * get_move_cost():

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
*/


/**
 * do_move():

	// Rotate stacks
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
