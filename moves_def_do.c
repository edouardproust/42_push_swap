/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_def_do.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:22:36 by eproust           #+#    #+#             */
/*   Updated: 2024/12/02 00:25:43 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Performs a push operation from the `from` stack to the `to` stack.
 * 
 * The first element of the `from` stack is moved to the front of the `to` stack.
 * The `from` stack is updated to remove the first element, and the `to` stack is
 * updated to include the pushed element at the front.
 * 
 * @param from A pointer to the source stack.
 * @param to A pointer to the destination stack.
 * @return 1 if the operation was successful, 0 otherwise.
 */
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

/**
 * Performs a swap operation on the first two elements of the stack.
 * 
 * If the stack has fewer than two elements, no operation is performed.
 * If the operation is successful, the top two elements of the stack are swapped.
 * The `index` values of the two top elements are also updated.
 * 
 * @param stack A pointer to the stack on which to perform the swap.
 * @return 1 if the operation was successful, 0 otherwise.
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
 * Performs a rotate operation on the stack.
 * 
 * The stack is rotated upwards, meaning the top element is moved to the bottom.
 * If the stack has fewer than two elements, no operation is performed.
 * 
 * @param stack A pointer to the stack on which to perform the rotate.
 * @return 1 if the operation was successful, 0 otherwise.
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
	update_stack_data(*stack, 1, 0);
	return (1);
}

/**
 * Performs a reverse rotate operation on the stack.
 * 
 * The stack is rotated downwards, meaning the bottom element is moved to
 * the top. If the stack has fewer than two elements, no operation is
 * performed.
 * 
 * @param stack A pointer to the stack on which to perform the reverse rotate.
 * @return 1 if the operation was successful, 0 otherwise.
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
	before_last->index = i;
	tail = before_last->next;
	tail->index = 0;
	before_last->next = NULL;
	tail->next = *stack;
	*stack = tail;
	return (1);
}
