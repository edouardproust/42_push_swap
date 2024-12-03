/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:47:29 by eproust           #+#    #+#             */
/*   Updated: 2024/12/02 18:52:35 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Validates the stack.
 *
 * Checks if the stack contains valid integer values and ensures no duplicates.
 *
 * @param stack The stack to validate.
 * @return 1 if the stack is valid, 0 otherwise.
 */
int	check_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		while (next)
		{
			if (stack->nb == next->nb)
				return (0);
			next = next->next;
		}
		stack = stack->next;
	}
	return (1);
}

/**
 * Builds a stack from input arguments.
 *
 * Converts the input arguments into a stack of integers and performs validation.
 * Frees resources and exits if errors are detected.
 *
 * @param stack The stack to build on.
 * @param av The array of input arguments.
 * @param is_malloc_av Flag indicating if `av` was dynamically allocated.
 * @return The constructed stack.
 */
t_stack	*build_stack(t_stack *stack, char **av, int is_malloc_av)
{
	t_stack	*node;
	long	nb;
	char	**args;

	args = av;
	while (*av)
	{
		if (!is_valid_number(*av))
			error_exit(args, stack, is_malloc_av);
		nb = ft_atol(*av);
		if (nb > INT_MAX || nb < INT_MIN)
			error_exit(args, stack, is_malloc_av);
		node = new_node(nb);
		if (!node)
			error_exit(args, stack, is_malloc_av);
		add_node_back(&stack, node);
		av++;
	}
	if (*av != NULL || !check_stack(stack))
		error_exit(args, stack, is_malloc_av);
	if (is_malloc_av)
		free_matrix(args);
	return (stack);
}

/**
 * Updates the stack data such as indices and size.
 *
 * Traverses the stack to update the node indices if `updte_indexes` is true.
 * Updates the `ssize` field of all nodes if `updte_ssize` is true.
 *
 * @param stack The stack to update.
 * @param updte_indexes Set to 1 to update node indices, 0 otherwise.
 * @param updte_ssize Set to 1 to update stack size, 0 otherwise.
 */
void	update_stack_data(t_stack *stack, int updte_indexes, int updte_ssize)
{
	int		i;
	t_stack	*s;

	if (!stack)
		return ;
	i = 0;
	s = stack;
	while (s)
	{
		if (updte_indexes)
			s->index = i;
		s = s->next;
		i++;
	}
	if (updte_ssize)
	{
		s = stack;
		while (s)
		{
			s->ssize = i;
			s = s->next;
		}
	}
}

/**
 * Finds either the minimum or maximum node in a stack.
 *
 * Scans the stack to identify the node with the smallest or largest value
 * based on the `find_max` parameter.
 *
 * @param stack The stack to search.
 * @param find_max Set to 1 to find the maximum, 0 to find the minimum.
 * @return A pointer to the node with the minimum or maximum value.
 */
t_stack	*minmax_node(t_stack *stack, int find_max)
{
	t_stack	*minmax;

	if (!stack)
		return (NULL);
	minmax = stack;
	stack = stack->next;
	while (stack)
	{
		if ((find_max && stack->nb > minmax->nb)
			|| (!find_max && stack->nb < minmax->nb))
			minmax = stack;
		stack = stack->next;
	}
	return (minmax);
}

/**
 * Checks if the stack is sorted in ascending order.
 *
 * Iterates through the stack to verify that each node's value is less than
 * or equal to the value of the next node.
 *
 * @param stack The stack to check.
 * @return 1 if the stack is sorted, 0 otherwise.
 */
int	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}
