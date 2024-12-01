/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_def_do.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:22:36 by eproust           #+#    #+#             */
/*   Updated: 2024/12/01 14:20:14 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_push(t_stack **from, t_stack **to)
{
	t_stack	*f2;

	if (!(*from))
		return (0);
	f2 = (*from)->next;
	add_node_front(to, *from);
	*from = f2;
	update_stack_data(*from, 1, 1);
	return (1);
}

int	do_swap(t_stack **stack)
{
	t_stack	*n2;

	if (!*stack || !(*stack)->next)
		return (0);
	n2 = (*stack)->next;
	(*stack)->next = n2->next;
	n2->next = (*stack);
	*stack = n2;
	(*stack)->index = 0;
	(*stack)->next->index = 1;
	return (1);
}

int	do_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*n2;

	if (!*stack || !(*stack)->next)
		return (0);
	tail = last_node(*stack);
	n2 = (*stack)->next;
	tail->next = *stack;
	(*stack)->next = NULL;
	*stack = n2;
	update_stack_data(*stack, 1, 0);
	return (1);
}

int	do_rev_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*before_last;
	int		i;

	if (!*stack || !(*stack)->next)
		return (0);
	before_last = *stack;
	i = 1;
	while (before_last->next->next)
	{
		before_last->index = i++;
		before_last = before_last->next;
	}
	before_last->index = i;
	tail = before_last->next;
	tail->index = 0;
	before_last->next = NULL;
	tail->next = *stack;
	*stack = tail;
	return (1);
}
