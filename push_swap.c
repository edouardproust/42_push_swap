/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:00:07 by eproust           #+#    #+#             */
/*   Updated: 2024/12/03 02:59:04 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * `push_swap` sorts in asc. order the input list of integers, using the 
 * minimum number of moves among the operations allowed (listed below)
 * between 2 stacks (linked lists).
 *
 * Allowed moves:
 * - push the top element of a stack on top of another
 * - swap the first 2 elements of a stack
 * - rotate a stack (2nd element becomes first, 1st becomes last)
 * - reverse rotate a stack (1st element becomes 2nd, last becomes 1st)
 * - swap both stack simultaneously (counts as 1 move)
 * - rotate both stacks simultaneously (counts as 1 move)
 * - reverse rotate both stack simultaneously (counts a 1 move)
 */
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	av++;
	if (ac == 2)
	{
		av = ft_split((const char *)(*av), ' ');
		if (!av)
			error_exit(NULL, NULL, 0);
	}
	a = build_stack(a, av, ac == 2);
	sort_dispatch(&a, &b);
	clear_stack(&a);
	return (0);
}
