/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_target.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:36:41 by eproust           #+#    #+#             */
/*   Updated: 2024/11/27 21:47:23 by eproust          ###   ########.fr       */
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
static t_stack	*update_minmax(t_stack *node1, t_stack *node2, char to_name)
{
	if (!node1)
		return (node2);
	if (!node2)
		return (node1);
	if (to_name == 'b')
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
	t_stack *target, char to_name)
{
	if (to_name == 'b')
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
 * Updates the `target` attribute of `from_node` based on its comparison 
 * with the nodes in `to_stack`. 
 * - If `find_smaller` is 1, it updates `target` to the closest smaller node.
 * - If `find_smaller` is 0, it updates `target` to the closest larger node.
 * 
 * If no valid target is found, the closest min/max node is used.
 * 
 * Also updates the size of `to_stack` (`to_size`).
 *
 * @param from_node     The node in the source stack whose target is to be 
 *                      updated
 * @param find_smaller  1 to update `target` with the closest smaller node, 
 *                      0 to update with the closest larger node
 * @param to_stack      The stack to compare against `from_node`
 * @param to_size       Pointer to the size of the destination stack, updated
 *                      by the function
 */
void	set_target(char to_name, t_stack *from_node, t_stack *to_stack,
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
		target = update_target(from_node, to_stack, target, to_name);
		minmax = update_minmax(to_stack, minmax, to_name);
		to_stack = to_stack->next;
		i++;
	}
	*to_size = i;
	if (!target)
		target = minmax;
	from_node->target = target;
}
