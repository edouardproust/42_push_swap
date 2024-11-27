/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_extras.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:47:29 by eproust           #+#    #+#             */
/*   Updated: 2024/11/27 02:37:13 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Finds the node with the minimum or maximum value in the stack.
 *
 * @param stack		The stack to search through.
 * @param find_max	1 to find the maximum value, 0 for the minimum.
 * @return			The node containing the min or max value.
 */
int	minmax_node(t_stack *stack, int find_max)
{
	t_stack  *minmax;

	if (!stack)
		return (NULL);
	minmax = stack;
	stack = stack->next;
	while (stack)
	{
		if ((find_max && stack->nb > minmax->nb)
			|| (!find_max && stack->nb < minmax->nb))
			minmax = stack;
		stack = stack->next;
	}
	return (minmax);
}

/**
 * Check if the list is sorted in ascending order
 * (based on the content of each node)
 */
int	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

