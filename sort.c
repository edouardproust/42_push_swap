/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:34:57 by eproust           #+#    #+#             */
/*   Updated: 2024/11/25 20:57:58 by eproust          ###   ########.fr       */
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
		move_one("sa", &a);
	else if (size_a == 3)
		sort_three(&a);
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

void	sort_three(t_list **lst)
{
	int	max_index;

	max_index = get_bound_index(1, *lst);
	if (max_index == 0)
		move_one("ra", lst);
	else if (max_index == 1)
		move_one("rra", lst);
	if (get_val(*lst) > get_val((*lst)->next))
		move_one("sa", lst);
}
/*
void	sort_three(t_list **lst)
{
	t_list	*max;

	max = get_max_node(*lst);
	if (max == *lst)
		move_one("ra", lst);
	else if (max == (*lst)->next)
		move_one("rra", lst);
	if (get_val(*lst) > get_val((*lst)->next))
		move_one("sa", lst);
}
*/

//TODO finish function
/* Sorting algorythm used when stack a contains more than 3 ints.
 * 1. Until there are only 3 nodes lefts in A:
 *    1a. Move up to 2 nodes to stack B
 *    2b. Then move the other node to B so that:
 *        - nodes in B are in descreasing order
 *        - using the minimum number of moves
 * 2. Sort the 3 nodes left in stack A
 * 3. Push back all nodes from B to A
 * 4. Rotate / Re_rotate A so the smallest int is on top
 */
static void	sort_lists(t_list *a, t_list *b, int size_a)
{
	int	size_b;
	int	count;
	int	min_index;	
	int	rotations;
	int	dir;
	
	printf("===== Push A->B (max 2 nodes) =====\n"); // TODO Delete line
	count = 0;
	size_b = 0;
	while (size_a > 3 && count < 2)
	{
		move_push("pb", &a, &b, &size_a, &size_b);
		count++;
	}
	printf("===== Push A->B (turc algo #1) =====\n"); // TODO Delete line
	// 1b. While lstsize(a) > 3:
	while (size_a > 3)
		calc_do_moves(&a, &b, &size_a, &size_b);
	printf("===== sort_three on A (turc algo #2) =====\n"); // TODO Delete line
	sort_three(&a);
	printf("===== Push back all nodes B->A (turc algo #3) =====\n"); // TODO Delete line
	while (size_b != 0)
		push_all_back_to_a(&a, &b, &size_a, &size_b); // TODO: Refactoring de cette function
	// Rotate stack A
	min_index = get_bound_index(0, a);
	rotations = min_index;
	dir = 1;
	if (min_index > size_a / 2)
	{
		rotations = size_a - min_index;
		dir = -1;
	}
	while (rotations > 0)
	{
		if (dir == 1)
			move_one("ra", &a);
		else
			move_one("rra", &a);
		rotations--;
	}
}
