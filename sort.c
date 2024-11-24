/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:34:57 by eproust           #+#    #+#             */
/*   Updated: 2024/11/24 20:19:39 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_list_sorted(t_list *lst);
static void	sort_lists(t_list *a, t_list *b, int size_a);

void	sort_dispatch(t_list *a, t_list *b)
{
	int	size_a;

	if (is_list_sorted(a))
		return ;
	ft_debug("PRINT_LISTS", a, b); // TODO Delete line
	size_a = ft_lstsize(a);
	if (size_a == 2)
		move_one("sa", a);
	else if (size_a == 3)
		sort_three(a);
	else
		sort_lists(a, b, size_a);
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

void	sort_three(t_list *lst)
{
	t_list	*max;

	max = get_max_node(lst);
	if (max == lst)
		move_one("ra", lst);
	else if (max == lst->next)
		move_one("rra", lst);
	if (get_val(lst) > get_val(lst->next))
		move_one("sa", lst);
}

//TODO finish function
/* Sorting algorythm used when stack a contains more than 3 ints.
 * 1. Until there are only 3 nodes lefts in A:
 *    1a. Move up to 2 nodes to stack B
 *    2b. Then move the other node to B so that:
 *        - nodes in B are in descreasing order
 *        - using the minimum number of moves
 * 2. Push all nodes from B to A
 * 3. Rotate / Re_rotate A so the smallest int is on top
 */
static void	sort_lists(t_list *a, t_list *b, int size_a)
{
	// 1a.
	int	count;

	count = 0;
	while (size_a > 3 && count < 2)
	{
		move_push("pb", &a, &b);
		size_a--;
		count++;
	}
	// 1b. While lstsize(a) > 3:
	//while (size_a > 3)
		calc_do_moves(a, b, &size_a);
}
