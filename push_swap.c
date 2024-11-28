/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:00:07 by eproust           #+#    #+#             */
/*   Updated: 2024/11/28 14:29:17 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *	Verifies that the stack contains unique integers and values fit in an int.
 * 
 * @param stack	The stack to check.
 * @return		1 if the stack is valid, 0 otherwise.
 */
static int	check_stack(t_stack *stack)
{
	t_stack	*next;

	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nb > INT_MAX || stack->nb < INT_MIN)
			return (0);
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
 * Builds a stack from the given arguments. Validates values and uniqueness.
 *
 * @param stack			The stack to populate.
 * @param av			The input arguments to process.
 * @param is_malloc_av	1 if `av` is dynamically allocated, 0 otherwise.
 * @return				The populated stack.
 */
static t_stack	*build_stack(t_stack *stack, char **av, int is_malloc_av)
{
	t_stack	*node;
	int		nb;

	while (*av)
	{
		if (!is_valid_number(*av))
			error_exit(av, stack, is_malloc_av);
		nb = ft_atoi(*av);
		node = new_node(nb, 0);
		if (!node)
			error_exit(av, stack, is_malloc_av);
		add_node_back(&stack, node);
		av++;
	}
	if (*av != NULL || !check_stack(stack))
		error_exit(av, stack, is_malloc_av);
	if (is_malloc_av)
		free_matrix(av);
	return (stack);
}

/**
 * Main function for the push_swap program. Parses inputs and starts sorting.
 *
 * @param ac	Argument count.
 * @param av	Argument vector.
 * @return		0 on successful execution.
 */
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
		error_exit(av, NULL, 0); // TODO Check que ca marche
	av++;
	if (ac == 2)
		av = ft_split((const char *)(*av), ' ');
	a = build_stack(a, av, ac == 2);
	sort_dispatch(&a, &b);
	clear_stack(&a);
	return (0);
}
