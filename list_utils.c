/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:47:29 by eproust           #+#    #+#             */
/*   Updated: 2024/11/25 20:47:23 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_val(t_list *node)
{
	if (!node)
		return (INT_MIN);
	return *(int *)node->content;	
}

int	get_vall(t_list *node)
{
	if (!node)
		return (INT_MAX);
	return *(int *)node->content;	
}

void	del_node_content(void *content)
{
	if (content)
		free(content);
}

/**
 * Returns the index of the minimum or maximum value (boundary).
 * boundary: 0 for min, 1 for max
 */
int	get_bound_index(int boundary, t_list *lst)
{
	t_list  *bound_node;
	int		bound_index;
	int		i;

	bound_node = lst;
	bound_index = 0;
	lst = lst->next;
	i = 1;
	while (lst)
	{
		if ((boundary == 1 && get_val(lst) > get_val(bound_node))
			|| (boundary == 0 && get_val(lst) < get_val(bound_node)))
		{
			bound_node = lst;
			bound_index = i;
		}
		lst = lst->next;
		i++;
	}
	return (bound_index);
}
