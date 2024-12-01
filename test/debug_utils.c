/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:49:57 by eproust           #+#    #+#             */
/*   Updated: 2024/12/01 06:19:10 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "debug.h"

int	get_digits_nb(int n)
{
	int	count = 1;
	if (n == INT_MIN)
		return (11);	
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	max_digits_nb(t_stack *stack)
{
	int	min = INT_MAX;
	int	max = INT_MIN;
	int	digits_min;
	int	digits_max;

	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nb < min)
			min = stack->nb;
		if (stack->nb > max)
			max = stack->nb;
		stack = stack->next;
	}
	digits_min = get_digits_nb(min);
	digits_max = get_digits_nb(max);
	if (digits_min >= digits_max)
		return (digits_min);
	return (digits_max);
}

void	print_node_data(char *prefix, t_stack *stack, int nl)
{
	char *gray = "\033[90m";
	char *white = "\033[0m";
	if (!stack)
		return ;
	printf(" %s%s%d[ ", gray, prefix, stack->index);
	if (stack->target)
		printf("target:%d ", stack->target->nb);
	if (stack->ssize)
		printf("ssize:%d ", stack->ssize);
	if (stack->sname)
		printf("sname:%c ", stack->sname);
	if (stack->next)
		printf("next:%d ", stack->next->nb);
	printf("]%s%s", white, nl ? "\n" : "");
}

void repeat_char(char *c, int n)
{
	while (n > 0) {
		printf("%s", c);
		n--;
	}
}

int	get_cols(int digits_a, int digits_b)
{
	int cols = digits_a + digits_b + 2;
	if (digits_a > 0 && digits_b > 0)
		cols++;
	return (cols);
}

