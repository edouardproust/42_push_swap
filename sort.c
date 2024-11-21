/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:34:57 by eproust           #+#    #+#             */
/*   Updated: 2024/11/21 18:26:24 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_list_sorted(t_list *lst);
static void	ft_sort_lists(t_list **a, t_list **b, int size_a);

void	sort_dispatch(t_list **a, t_list **b)
{
	int	size_a;

	if (is_list_sorted(*a))
		return ;
	ft_debug("PRINT_LISTS", a, b); // TODO Delete line
	size_a = ft_lstsize(*a);
	if (size_a == 2)
		swap('a', a);
	else if (size_a == 3)
		ft_sort_three(a);
	else
		ft_sort_lists(a, b, size_a);
}

static int	is_list_sorted(t_list *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (get_val(lst) > get_val(lst->next))
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_sort_three(t_list **lst)
{
	t_list	*max;

	max = get_max_node(*lst);
	if (max == *lst)
		rotate('a', lst);
	else if (max == (*lst)->next)
		rev_rotate('a', lst);
	if (get_val(*lst) > get_val((*lst)->next))
		swap('a', lst);
}

//TODO finish function
static void	ft_sort_lists(t_list **a, t_list **b, int size_a)
{
	// TODO finish
	if (!a || !b || !size_a)
		return ;
}
