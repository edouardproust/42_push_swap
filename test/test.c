/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:46:10 by eproust           #+#    #+#             */
/*   Updated: 2024/11/21 19:19:44 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test.h"

void	ft_debug(const char *action, t_list **a, t_list **b)
{
	if (!action)
		return ;
	int len = ft_strlen(action);
	if (!ft_strncmp("DUMMY_B", action, len))
	{
		char **args_b = ft_split("12 -32 2 0 765 -78", ' ');
		parse_args(b, &args_b, 1);
	}
	else if (!ft_strncmp("PRINT_LISTS", action, len))
	{
		t_list *a_cpy = a ? *a : NULL;
		t_list *b_cpy = b ? *b : NULL;
		printf("┌───────────────┐\n");
		while (a_cpy || b_cpy)
		{
			if (!a_cpy && b_cpy)
				printf("|\t");
			if (a_cpy)
			{
				printf("│%d", *(int *)a_cpy->content);
				a_cpy = a_cpy->next;
				if (b_cpy)
					printf("\t");
				else
					printf("\t\t│\n");
			}
			if (b_cpy)
			{
				printf("%d\t|\n", *(int *)b_cpy->content);
				b_cpy = b_cpy->next;
			}
		}
		printf("│――――――― ―――――――│\n");
		printf("│   A       B   │\n");
		printf("└───────────────┘\n");
	}
	else
		ft_putstr_fd("Call to fn `./debug.c:ft_debug()` has a wrong argument\n", 1);
}
