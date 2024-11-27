/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_target.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:36:41 by eproust           #+#    #+#             */
/*   Updated: 2024/11/27 02:15:23 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Updates the `minmax` node based on whether the search is for the maximum
 * or the minimum value in the stack (depending on `find_max`).
 *
 * @param node1		A candidate node for comparison
 * @param node2		Another candidate node for comparison
 * @param find_max	1 to search for the maximum node, 0 for the minimum node
 * @return			The updated `minmax` node (either `node1` or `node2`)
 */
static t_stack	*update_minmax(t_stack *node1, t_stack *node2, int find_max)
{
	if (!node1)
		return (node2);
	if (!node2)
		return (node1);
	if (find_max)
	{
		if (node1->nb > node2->nb)
			return (node1);
		return (node2);
	}
	if (node1->nb < node2->nb)
		return (node1);
	return (node2);
}

/**
 * Updates the `target` node if the `to_node` is closer to `from_node`
 * based on `find_smaller`.
 *
 * @param from_node		The origin node in the source stack
 * @param to_node		The candidate node in the destination stack
 * @param target		The current closest node in the destination stack
 * 						to be updated
 * @param find_smaller	1 if looking for the closest smaller target node
						or 0 for the closest larger node
 * @return				The updated target node
 */
static t_stack	*update_target(t_stack *from_node, t_stack *to_node,
	t_stack *target, int find_smaller)
{
	if (find_smaller)
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
 * Finds the closest smaller `target` node (or closest larger if
 * `find_smaller` is 0) of the `from_node` in the `to_stack`.
 * Also updates the size of `to_stack` (`to_size` passed by reference).
 *
 * @param from_node		The node in the source stack
 * @param to_stack		The destination stack to search for the target node
 * @param find_smaller	1 if looking for the closest smaller target node
 * 						or 0 for the closest larger
 * @param to_size		Pointer to the size of the destination stack to be
 * 						updated
 * @return				The closest target node
 */
t_stack	*get_target(int find_smaller, t_stack *from_node, t_stack *to_stack,
	int *to_size)
{
	t_stack	*minmax;
	t_stack	*target;
	int		i;

	minmax = NULL;
	target = NULL;
	i = 0;
	while (to_stack)
	{
		target = update_target(from_node, to_stack, target, find_smaller);
		minmax = update_minmax(to_stack, minmax, find_smaller);
		to_stack = to_stack->next;
		i++;
	}
	*to_size = i;
	if (!target)
		target = minmax;
	return (target);
}
