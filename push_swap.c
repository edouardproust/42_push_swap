/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:00:07 by eproust           #+#    #+#             */
/*   Updated: 2024/12/01 01:22:21 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static t_stack	*build_stack(t_stack *stack, char **av, int is_malloc_av)
{
	t_stack	*node;
	int		nb;
	char	**args;

	args = av;
	while (*av)
	{
		if (!is_valid_number(*av))
			error_exit(args, stack, is_malloc_av);
		nb = ft_atoi(*av);
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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
		error_exit(av, NULL, 0);
	av++;
	if (ac == 2)
		av = ft_split((const char *)(*av), ' ');
	a = build_stack(a, av, ac == 2);
	sort_dispatch(&a, &b);
	clear_stack(&a);
	return (0);
}
