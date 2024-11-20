/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:34:57 by eproust           #+#    #+#             */
/*   Updated: 2024/11/20 19:59:30 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_list_sorted(t_list *lst);
void		ft_sort_3(t_list **lst);
static void	ft_sort_lists(t_list **a, t_list **b, int size_a);

void	sort_dispatch(t_list **a, t_list **b)
{
	int	a_size;

	if (is_list_sorted(*a))
		return ;
	a_size = ft_lstsize(a);
	if (a_size == 2)
		ft_do("sa", a, b);
	else if (a_size == 3)
		ft_sort_3(a);
	else
		ft_sort_turc(a, b);
}

static int	is_list_sorted(t_list *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (*(int *)lst->content > *(int *)lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_sort_3(t_list **lst)
{
	t_list	*max;

	max = get_max_node(*lst);
	if (max == *a)
		ft_do("ra", a); // TODO Change actions dispatch logic so we only pass &a
	else if (max == (*a)->next)
		ft_do("rra", a);
	if (*(int *)(*lst)->content > *(int *)(*lst)->next->content)
		ft_do("sa", &a);
}

static void	ft_sort_lists(t_list **a, t_list **b, int size_a)
{
	// TODO
}
