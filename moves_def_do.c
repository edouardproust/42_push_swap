/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_def_do.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:22:36 by eproust           #+#    #+#             */
/*   Updated: 2024/11/28 21:23:49 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Moves the top element from one stack to another, updating both
 * stacks' indices.
 *
 * @param from	Pointer to the source stack (t_stack**).
 * @param to	Pointer to the destination stack (t_stack**).
 * @return		1 if successful, 0 if the source stack is empty.
 */
int	do_push(t_stack **from, t_stack **to)
{
	t_stack	*f2;

	if (!(*from))
		return (0);
	f2 = (*from)->next;
	add_node_front(to, *from);
	*from = f2;
	update_indexes(*from);
	return (1);
}

/**
 * Swaps the first two elements of the stack and updates their indices.
 *
 * @param stack Pointer to the stack (t_stack**), modified in place.
 * @return      1 if swap is successful, 0 if stack is empty or has one
 * 				element.
 */
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

/**
 * Performs a rotation on the stack, moving the first element to the bottom
 * and updating the indices.
 *
 * @param stack	Pointer to the stack (t_stack**), modified in place.
 * @return		1 if rotation successful, 0 if stack is empty or has one
 * 				element.
 */
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
	update_indexes(*stack);	
	return (1);
}

/**
 * Performs a reverse rotation on the stack, moving the last element to the top
 * and updating indices.
 *
 * @param stack	Pointer to the stack (t_stack**), modified in place.
 * @return		1 if rotation successful, 0 if stack is empty or has one
 * 				element.
 */
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
	tail = before_last->next;
	tail->index = 0;
	before_last->next = NULL;
	tail->next = *stack;
	*stack = tail;
	return (1);
}
