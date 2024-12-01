/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:46:10 by eproust           #+#    #+#             */
/*   Updated: 2024/11/30 02:43:14 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "debug.h"

static void	print_tab_line(int cols, int max_digits_a, int max_digits_b, t_stack *a, t_stack *b, t_stack *a_start, t_stack *b_start)
{
	printf("│ ");
	if (!a)
		repeat_char(" ", max_digits_a);
	else {
		printf("%d", a->nb);
		repeat_char(" ", max_digits_a - get_digits_nb(a->nb));
	}
	if (!b)
		repeat_char(" ", b_start ? max_digits_b + 1 : max_digits_b);
	else {
		if (a_start)
			printf(" ");
		printf("%d", b->nb);
		repeat_char(" ", max_digits_b - get_digits_nb(b->nb));
	}
	printf(" │");
	if (a) {
		print_node_data("A", a, b ? 0 : 1);
	}
	if (b)
		print_node_data("B", b, 1);
}

static void	print_tab_top(int cols)
{
	printf("┌"); repeat_char("─", cols); printf("┐\n");
}

static void	print_tab_bottom(int cols, int digits_a, int digits_b, t_stack *a, t_stack *b)
{
	printf("├"); repeat_char("─", cols); printf("┤\n");
	printf("│ ");
	if (a) {
		printf("A"); repeat_char(" ", digits_a - 1);
		if (b)
			printf(" ");
	}
	if (b) {
		printf("B"); repeat_char(" ", digits_b - 1);
	}
	printf(" │\n"); 
	printf("└"); repeat_char("─", cols); printf("┘\n");
}

void	ft_debug(t_stack *a, t_stack *b)
{
	int	digits_a = 0;
	int	digits_b = 0;
	if (a)
		digits_a = max_digits_nb(a);
	if (b)
		digits_b = max_digits_nb(b);
	int	cols = get_cols(digits_a, digits_b);
	
	print_tab_top(cols);
	t_stack *a_cpy = a;
	t_stack *b_cpy = b;
	while (a_cpy || b_cpy)
	{
		print_tab_line(cols, digits_a, digits_b, a_cpy, b_cpy, a, b);
		if (a_cpy)
			a_cpy = a_cpy->next;
		if (b_cpy)
			b_cpy = b_cpy->next;
	}
	print_tab_bottom(cols, digits_a, digits_b, a, b);
}
