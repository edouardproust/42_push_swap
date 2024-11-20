/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:07:31 by eproust           #+#    #+#             */
/*   Updated: 2024/11/20 18:11:51 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target(int an, t_list *b)
{
	int biggest;
	int biggest_index;
	int target_val;
	int target_index;
	int	i;

	i = 0;
	while (b)
	{
		bn = *(int *)b->content;
		if (bn > biggest)
		{
			biggest = bn;
			biggest_index = i;
		}
		if (bn < an && bn > target_val)
		{
			target_val = bn;
			target_index = i;
		}
		if (target_index == -1)
			target_index = biggest_index;
		b = b->next;
		i++;
	}
	return (target_index);
}

static int	calc_steps(int a_index, int b_index, int a_size, int b_size)
{
	int	up;
	int	down;
	int	median_a;
	int	median_b;

	median_a = a_size / 2;
	median_b = b_size / 2;
	up = a_index;
	if (a_index < b_index)
		up = b_index;
	down = a_size - a_index;
	if (down < b_size - b_index)
		down = b_size - b_index;	
	if (a_index <= median_a && b_index <= median_b) // rr
		return (up);
	else if (a_index > median_a && b_index > median_b) // rrr
		return(down);
	
}

static void	do_actions(cheapest, cheapest_target, &a, &b, b_size, b_size)
{

}

void	calc_perform_actions(t_list *a, t_list *b, int *a_size, int *b_size)
{
	int		target_index;
	int		i;
	int		cost;
	int		min_cost;
	int		cheapest;
	int		cheapest_target;

	cheapest = 0;
	min_cost = INT_MAX;
	i = 0;
	while (a && cost != 0)
	{
		target_index = get_target(*(int *)a->content, b);
		cost = calc_steps(i, target_index, a_size, b_size);
		if (cost < min_cost)
		{
			min_cost = cost; 
			cheapest = i;
			cheapest_target = target_index;
		}
		i++;
 		a = a->next;
 	}
	do_actions(cheapest, cheapest_target, &a, &b, b_size, b_size);
}
