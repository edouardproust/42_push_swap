/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:20:36 by eproust           #+#    #+#             */
/*   Updated: 2024/11/28 17:11:58 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Updates the indices of all elements in the stack, starting from 0.
 *
 * @param stack	Pointer to the first element of the stack (t_stack*).
 */
void update_indexes(t_stack *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		stack->index = i++;
		stack = stack->next;
	}
}

int	stack_size(t_stack *stack)
{
	int		count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stack	*new_node(int nb, int index)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->nb = nb;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	add_node_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*tail;

	if (!*stack)
	{
		*stack = new_node;
        return ;
	}
	tail = last_node(*stack);
    new_node->index = tail->index + 1;
	tail->next = new_node;
}

void	add_node_front(t_stack **stack, t_stack *new_node)
{
	new_node->next = *stack;
	new_node->target = 0;
	*stack = new_node;
	update_indexes(*stack);
}

void	clear_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
