/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_target.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:36:41 by eproust           #+#    #+#             */
/*   Updated: 2024/12/01 14:32:25 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * If the target stack is B, the rules are:
 * 1. The target node is the closest smaller number to the origin number
 *    (in stack A).
 * 2. If the origin number (in stack A) is smaller than all numbers in B, 
 *    the target number is the biggest number in B.
 * If the target stack is A, the rules are:
 * 1. The target node (in B is the closest bigger number to the origin number
      (in stack A).
 * 2. If the origin number (in stack A) is bigger than all numbers in B, the
      target number is the smallest number in B.
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
