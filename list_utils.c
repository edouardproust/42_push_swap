/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:47:29 by eproust           #+#    #+#             */
/*   Updated: 2024/11/21 17:57:36 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_val(t_list *node)
{
	return *(int *)node->content;	
}

void	del_node_content(void *content)
{
	if (content)
		free(content);
}

t_list	*get_max_node(t_list *lst)
{
	t_list  *max_node;

	max_node = lst;
	lst = lst->next;
	while (lst)
	{
		if (get_val(lst) > get_val(max_node))
			max_node = lst;
		lst = lst->next;
	}
	return (max_node);
}
