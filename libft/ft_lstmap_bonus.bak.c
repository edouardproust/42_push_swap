/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:09:27 by eproust           #+#    #+#             */
/*   Updated: 2024/09/25 12:09:28 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*lst_cpy;
	t_list	*nod_cpy;

	current = lst;
	lst_cpy = NULL;
	while (current)
	{
		nod_cpy = ft_lstnew(f(current->content));
		if (!nod_cpy)
		{
			ft_lstclear(&lst_cpy, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_cpy, nod_cpy);
		current = current->next;
	}
	return (lst_cpy);
}

/*
#include <stdio.h>
#include <string.h>

static void	del_content(void *content)
{
	if (content)
	{
		printf("Deleting content '%s'...\n", (char *)content);
		free(content);
	}
}

static void	*uppercase_content(void *content)
{
	char *cpy = strdup((char *)content); // do a copy to prevent error 
		// when freeing the node (the 'del' fn tries to free content as well)
	char *start = cpy;

	while (*cpy)
	{
		if ('a' <= *cpy && *cpy <= 'z')
			*cpy -= 32;
		cpy++;
	}
	return (start);
}

int	main(void)
{
	// Create list
	t_list *node1 = ft_lstnew(strdup("Node 1"));
	t_list *node2 = ft_lstnew(strdup("Node 2"));
	t_list *node3 = ft_lstnew(strdup("Node 3"));
	t_list *node4 = ft_lstnew(strdup("Node 4"));
	if (!node1 || !node2 || !node3 || !node4)
		return (1);
	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);
	ft_lstadd_back(&node1, node4);

	// Copy the list with uppercased content
	t_list *lst_upper = ft_lstmap(node1, uppercase_content, del_content);
	if (!lst_upper)
		return (1);

	// Print list copy + clear both list
	t_list *current = lst_upper;
	while (current)
	{
		printf("- %s\n", (char *)current->content);	
		current = current->next;
	}
	printf("\n");
	ft_lstclear(&node1, del_content);
	printf("\n");
	ft_lstclear(&lst_upper, del_content);

	return (0);
}
*/
