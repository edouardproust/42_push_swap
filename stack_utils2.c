/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:47:29 by eproust           #+#    #+#             */
/*   Updated: 2024/12/01 05:15:03 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void update_stack_data(t_stack *stack, int updte_indexes, int updte_ssize)
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

t_stack	*minmax_node(t_stack *stack, int find_max)
{
	t_stack  *minmax;

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
