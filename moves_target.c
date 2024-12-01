/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_target.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:36:41 by eproust           #+#    #+#             */
/*   Updated: 2024/12/02 00:30:08 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Updates the min or max node in the target stack.
 *
 * If the target stack is B, it returns the smallest number greater than
 * the current min. If the target stack is A, it returns the largest number
 * smaller than the current max.
 */
static t_stack	*update_minmax(t_stack *minmax, t_stack *to_node)
{
	if (!minmax)
		return (to_node);
	if (!to_node)
		return (minmax);
	if (to_node->sname == 'b')
	{
		if (minmax->nb > to_node->nb)
			return (minmax);
		return (to_node);
	}
	if (minmax->nb < to_node->nb)
		return (minmax);
	return (to_node);
}

/**
 * Determines the best target node for a given `from_node` in the target stack.
 *
 * - For stack B, it picks the closest smaller number to the `from_node`.
 * - For stack A, it picks the closest larger number.
 * If no valid target is found, returns the appropriate min or max.
 */
static t_stack	*update_target(t_stack *target, t_stack *from_node,
	t_stack *to_node)
{
	if (to_node->sname == 'b')
	{
		if (to_node->nb < from_node->nb
			&& (!target || to_node->nb > target->nb))
			return (to_node);
	}
	else if (to_node->nb > from_node->nb
		&& (!target || to_node->nb < target->nb))
		return (to_node);
	return (target);
}

/**
 * Sets the target node for a `from_node` by iterating over the target stack.
 *
 * The target is chosen based on the closest number (smaller or larger)
 * depending on the stack. If no target is found, the minimum or maximum
 * value is used as the fallback target.
 */
void	set_node_target(t_stack *from_node, t_stack *to_stack)
{
	t_stack	*minmax;
	t_stack	*target;

	minmax = NULL;
	target = NULL;
	while (to_stack)
	{
		target = update_target(target, from_node, to_stack);
		minmax = update_minmax(minmax, to_stack);
		to_stack = to_stack->next;
	}
	if (!target)
		target = minmax;
	from_node->target = target;
}
