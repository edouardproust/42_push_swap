/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:00:07 by eproust           #+#    #+#             */
/*   Updated: 2024/12/02 05:18:12 by eproust          ###   ########.fr       */
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
static int	check_stack(t_stack *stack)
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
static t_stack	*build_stack(t_stack *stack, char **av, int is_malloc_av)
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
 * Program entry point.
 *
 * Parses arguments, builds the stack, sorts it, and clears resources.
 *
 * @param ac The argument count.
 * @param av The argument vector.
 * @return 0 on successful execution.
 */
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	av++;
	if (ac == 2)
		av = ft_split((const char *)(*av), ' ');
	a = build_stack(a, av, ac == 2);
	sort_dispatch(&a, &b);
	clear_stack(&a);
	return (0);
}
