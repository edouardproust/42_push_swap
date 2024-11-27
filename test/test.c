/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:46:10 by eproust           #+#    #+#             */
/*   Updated: 2024/11/26 20:01:03 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test.h"

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

	if (!action)
		return ;
	t_stack *a_cpy = a;
	if(!ft_strncmp("PRINT_LIST_", action, 11))
	{
		printf("%s", header_1);
		while (a_cpy)
		{
			printf("│%d\t│\n", val(a_cpy));
			a_cpy = a_cpy->next;
		}
		printf("%s", footer_1_1);
		printf("%s", footer_1_2_1);
		if (ft_strncmp("PRINT_LIST_A", action, 12) == 0)
			printf("A");
		else
			printf("B");
		printf("%s", footer_1_2_2);
		printf("%s", footer_1_3);
	}
	else if (!ft_strncmp("PRINT_LISTS", action, 12))
	{
		printf("%s", header_2);
		t_list *b_cpy = b;
		while (a_cpy || b_cpy)
		{
			if (!a_cpy && b_cpy)
				printf("│\t");
			if (a_cpy)
			{
				printf("│%d", val(a_cpy));
				a_cpy = a_cpy->next;
				if (b_cpy)
					printf("\t");
				else
					printf("\t\t│\n");
			}
			if (b_cpy)
			{
				printf(" %d\t│\n", val(b_cpy));
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
