/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:07:31 by eproust           #+#    #+#             */
/*   Updated: 2024/11/21 13:50:40 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target_index(t_list	*an, t_list *b)
{
	t_list	*max_node;
	int		max_index;
	t_list	*target_node;
	int		target_index;
	int		i;

	target_node = NULL;
	i = 0;
	while (b)
	{
		if (*(int *)b->content > *(int *)max_node->content)
		{
			max_index = i;
			max_node = b;
		}
		if (*(int *)b->content < *(int *)an->content
			&& (!target_node || (target_node && *(int *)b->content > *(int *)target_node->content)))
		{
			target_index = i;
			target_node = b;
		}
		b = b->next;
		i++;
	}
	if (!target_node)
		target_index = max_index;
	return (target_index);
}

// TODO finish!
static int	calc_steps(int index_a, int index_b, int size_a, int size_b)
{
	int	up;
	int	down;
	int	median_a;
	int	median_b;

	median_a = size_a / 2;
	median_b = size_b / 2;
	up = index_a;
	if (index_a < index_b)
		up = index_b;
	down = size_a - index_a;
	if (down < size_a - index_b)
		down = size_b - index_b;	
	if (index_a <= median_a && index_b <= median_b) // rr
		return (up);
	else if (index_a > median_a && index_b > median_b) // rrr
		return (down);
	// TODO Finish!
	return (0);	
}

// TODO finish!
static void	do_actions(t_list *a_node, t_list *b_node, t_list **a, t_list **b, int size_a, int size_b)
{
	// TODO finish
	if (!a_node || b_node || !a || !b || size_b || !size_a)
		return ;
}

void	calc_perform_actions(t_list **a, t_list **b, int size_a, int size_b)
{
	int		cost;
	int		min_cost;
	t_list	*target_node;
	int		target_index;
	t_list	*cheapest;
	t_list	*cheapest_target;
	int		i;

	cheapest = 0;
	min_cost = INT_MAX;
	i = 0;
	while (*a && cost != 0)
	{
		target_index = get_target_index(*a, *b);
		cost = calc_steps(i, target_index, size_a, size_b);
		if (cost < min_cost)
		{
			min_cost = cost; 
			cheapest = *a;
			cheapest_target = target_node;
		}
 		*a = (*a)->next;
		i++;
 	}
	do_actions(cheapest, cheapest_target, a, b, size_a, size_b);
}
