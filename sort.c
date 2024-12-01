/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:34:57 by eproust           #+#    #+#             */
/*   Updated: 2024/12/01 05:19:30 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **stack)
{
	t_stack	*max;

	max = minmax_node(*stack, 1);
	if (max->index == 0)
		move_one("r", stack);
	else if (max->index == 1)
		move_one("rr", stack);
	if ((*stack)->nb > (*stack)->next->nb)
		move_one("s", stack);
}

static void	sort_lists(t_stack **a, t_stack **b, int size_a)
{
	while ((*a)->ssize > 3 && (!*b || (*b)->ssize < 2))
		move_push(a, b);
	while ((*a)->ssize > 3)
		push_cheapest(a, b);
	sort_three(a);
	while (*b && (*b)->ssize > 0)
		push_cheapest(b, a);
	rotate_smallest_on_top(a);
}

void	sort_dispatch(t_stack **a, t_stack **b)
{
	if (is_stack_sorted(*a))
		return ;
	update_stack_data(*a, 0, 1); // TODO Optimize (prevent double loop)
	if ((*a)->ssize == 2)
		move_one("s", a);
	else if ((*a)->ssize == 3)
		sort_three(a);
	else
		sort_lists(a, b, (*a)->ssize); // TODO size
}
