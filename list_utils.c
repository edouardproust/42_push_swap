/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:47:29 by eproust           #+#    #+#             */
/*   Updated: 2024/11/20 19:52:53 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*get_max_node(t_list *lst)
{
	t_list  *biggest;

	biggest = lst;
	lst = lst->next;
	while (lst)
	{
		if (*(int *)lst->content > *(int *)biggest->content)
			biggest = lst;
		lst = lst->next;
	}
	return (biggest);
}
