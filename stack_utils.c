/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:20:36 by eproust           #+#    #+#             */
/*   Updated: 2024/12/01 04:00:56 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int nb)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->nb = nb;
	new_node->index = 0;
	new_node->ssize = 0;
	new_node->sname = 'a';
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
	new_node->target = NULL;
	if (new_node->sname == 'a')
		new_node->sname = 'b';
	else
		new_node->sname = 'a';
	*stack = new_node;
	update_stack_data(*stack, 1, 1);
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
