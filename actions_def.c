/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_def.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:55:12 by eproust           #+#    #+#             */
/*   Updated: 2024/11/21 16:52:10 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(char stack_letter, t_list **stack)
{
	t_list	*n2;

	if (!*stack || !(*stack)->next)
		return ;
	n2 = (*stack)->next;
	(*stack)->next = n2->next;
	n2->next = (*stack);
	*stack = n2;
	ft_putchar_fd('s', 1);
	ft_putchar_fd(stack_letter, 1);
	ft_putchar_fd('\n', 1);
	ft_debug("PRINT_LISTS", stack, NULL); // TODO Delete line
}

void	push(char stack_letter, t_list **from, t_list **to)
{
	t_list	*f2;

	if (!(*from))
		return ;
	f2 = (*from)->next;
	ft_lstadd_front(to,	*from);
	*from = f2; 
	ft_putchar_fd('p', 1);
	ft_putchar_fd(stack_letter, 1);
	ft_putchar_fd('\n', 1);
	ft_debug("PRINT_LISTS", from, to); // TODO Delete line
}

void	rotate(char stack_letter, t_list **stack)
{
	t_list	*tail;
	t_list	*n2;

	if (!*stack || !(*stack)->next)
		return ;
	tail = ft_lstlast(*stack);
	n2 = (*stack)->next;
	tail->next = *stack;
	(*stack)->next = NULL;
	*stack = n2;
	ft_putchar_fd('r', 1);
	ft_putchar_fd(stack_letter, 1);
	ft_putchar_fd('\n', 1);
	ft_debug("PRINT_LISTS", stack, NULL); // TODO Delete line
}

void	rev_rotate(char stack_letter, t_list **stack)
{
	t_list	*tail;
	t_list	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	tail = before_last->next;
	before_last->next = NULL;
	tail->next = *stack;
	*stack = tail;
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(stack_letter, 1);
	ft_putchar_fd('\n', 1);
	ft_debug("PRINT_LISTS", stack, NULL); // TODO Delete line
}
