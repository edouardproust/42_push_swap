/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:20:36 by eproust           #+#    #+#             */
/*   Updated: 2024/12/01 23:40:39 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Creates a new node for the stack.
 *
 * Allocates memory for a new stack node, initializes its fields, and sets
 * default values.
 *
 * @param nb The value to assign to the new node.
 * @return A pointer to the created node, or NULL if allocation fails.
 */
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

/**
 * Retrieves the last node of a stack.
 *
 * Traverses the stack to find and return the last node.
 *
 * @param stack The stack to search.
 * @return A pointer to the last node, or NULL if the stack is empty.
 */
t_stack	*last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/**
 * Adds a node to the end of the stack.
 *
 * Appends a new node to the tail of the stack and updates its index.
 *
 * @param stack A pointer to the stack.
 * @param new_node The node to add.
 */
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

/**
 * Adds a node to the front of the stack.
 *
 * Prepends a new node to the head of the stack and updates its data.
 * Also alternates the `sname` field between 'a' and 'b'.
 *
 * @param stack A pointer to the stack.
 * @param new_node The node to add.
 */
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

/**
 * Clears the stack and frees all its nodes.
 *
 * Iterates through the stack, freeing each node and setting the stack pointer
 * to NULL.
 *
 * @param stack A pointer to the stack to clear.
 */
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
