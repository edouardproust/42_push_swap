/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:55:12 by eproust           #+#    #+#             */
/*   Updated: 2024/11/18 19:09:36 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
t_list	*ft_dlstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_dlstadd_back(t_list **lst, t_list *new)
{
	t_list	*tail;

	tail = ft_lstlast(*lst);
	if (!tail)
		*lst = new;
	else
	{
		tail->next = new;
		new->prev = tail;
	}
}
*/
