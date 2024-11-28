/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:46:10 by eproust           #+#    #+#             */
/*   Updated: 2024/11/28 18:27:00 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test.h"

static void	print_current_data(char stack_name, t_stack *stack, int nl)
{
	printf(" %c:{nb: %d, i: %d", stack_name, stack->nb, stack->index);
	if (stack->target)
		printf(", target->nb: %d", stack->target->nb);
	if (stack->next)
		printf(", next->nb: %d", stack->next->nb);
	printf("}%c", nl ? '\n' : 0);
}

void	ft_debug(const char *action, t_stack *a, t_stack *b)
{
	char *header_1		= "┌───────┐\n";
	char *footer_1_1	= "│―――――――│\n";
	char *footer_1_2_1	= "│   ";
	char *footer_1_2_2	= "   │\n";
	char *footer_1_3	= "└───────┘\n";
	char *header_2		= "┌───────────────┐\n";
	char *footer_2_1	= "│――――――― ―――――――│\n";
	char *footer_2_2	= "│   A       B   │\n";
	char *footer_2_3	= "└───────────────┘\n";
	char stack_name;

	if (!action)
		return ;
	t_stack *a_cpy = a;
	if(!ft_strncmp("PRINT_STACK_", action, 12))
	{
		if (ft_strncmp("PRINT_STACK_A", action, 13) == 0)
			stack_name = 'A';
		else
			stack_name = 'B';	
		printf("%s", header_1);
		while (a_cpy)
		{
			printf("│%d\t│", a_cpy->nb);
			print_current_data(stack_name, a_cpy, 1);
			a_cpy = a_cpy->next;
		}
		printf("%s", footer_1_1);
		printf("%s", footer_1_2_1);
		printf("%c", stack_name);
		printf("%s", footer_1_2_2);
		printf("%s", footer_1_3);
	}
	else if (!ft_strncmp("PRINT_STACKS", action, 12))
	{
		printf("%s", header_2);
		t_stack *b_cpy = b;
		while (a_cpy || b_cpy)
		{
			if (!a_cpy && b_cpy)
				printf("│\t");
			if (a_cpy)
			{
				printf("│%d", a_cpy->nb);
				if (b_cpy)
					printf("\t");
				else
					printf("\t\t│");
			}
			if (b_cpy)
				printf(" %d\t│", b_cpy->nb);
			if (a_cpy)
			{
				print_current_data('A', a_cpy, !b_cpy);
				a_cpy = a_cpy->next;
			}
			if (b_cpy)
			{
				print_current_data('B', b_cpy, 1);
				b_cpy = b_cpy->next;
			}
		}
		printf("%s", footer_2_1);
		printf("%s", footer_2_2);
		printf("%s", footer_2_3);
	}
	else
	{
		ft_putstr_fd("Call to fn `./debug.c:ft_debug()` has a wrong argument: \"", 1);
		ft_putstr_fd(action, 1);
		ft_putstr_fd("\"\n", 1);
	}
}
