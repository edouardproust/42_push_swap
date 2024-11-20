/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_def.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:55:12 by eproust           #+#    #+#             */
/*   Updated: 2024/11/20 19:59:38 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_handle_single(char *action, t_list **a, t_list **b, int len);
static int	ft_handle_double(char *action, t_list **a, t_list **b, int len);
//TODO Move to another file:
static int	ft_swap(t_list **stack);
static int	ft_push(t_list **from, t_list **to);
static int	ft_rotate(t_list **stack);
static int	ft_rev_rotate(t_list **stack);

void	ft_do(char *action, t_list **a, t_list **b)
{
	int	success;
	int	len;

	if (!action)
		return ;
	len = ft_strlen(action);
	success = ft_handle_single(action, a, b, len);
	success |= ft_handle_double(action, a, b, len);
	if (success)
	{
		ft_putstr_fd(action, 1);
		ft_putchar_fd('\n', 1);
	}
}

static int	ft_handle_single(char *action, t_list **a, t_list **b, int len)
{
	if (!ft_strncmp("sa", action, len))
		return (ft_swap(a));
	if (!ft_strncmp("sb", action, len))
		return (ft_swap(b));
	if (!ft_strncmp("pa", action, len))
		return (ft_push(b, a));
	if (!ft_strncmp("pb", action, len))
		return (ft_push(a, b));
	if (!ft_strncmp("ra", action, len))
		return (ft_rotate(a));
	if (!ft_strncmp("rb", action, len))
		return (ft_rotate(b));
	if (!ft_strncmp("rra", action, len))
		return (ft_rev_rotate(a));
	if (!ft_strncmp("rrb", action, len))
		return (ft_rev_rotate(b));
	return (0);
}

static int	ft_handle_double(char *action, t_list **a, t_list **b, int len)
{
	int	success;

	success = 0;
	if (!ft_strncmp("ss", action, len))
	{
		success = ft_swap(a);
		success |= ft_swap(b);
	}
	else if (!ft_strncmp("rr", action, len))
	{
		success = ft_rotate(a);
		success |= ft_rotate(b);
	}
	else if (!ft_strncmp("rrr", action, len))
	{
		success = ft_rev_rotate(a);
		success |= ft_rev_rotate(b);
	}
	return (success);
}

static int	ft_swap(t_list **stack)
{
	t_list	*n2;

	if (!(*stack) || !(*stack)->next)
		return (0);
	n2 = (*stack)->next;
	(*stack)->next = n2->next;
	n2->next = (*stack);
	*stack = n2;		
	return (1);
}

static int	ft_push(t_list **from, t_list **to)
{
	t_list	*f2;

	if (!(*from))
		return (0);
	f2 = (*from)->next;
	ft_lstadd_front(to,	*from);
	*from = f2; 
	return (1);
}

static int	ft_rotate(t_list **stack)
{
	t_list	*tail;
	t_list	*n2;

	if (!*stack || !(*stack)->next)
		return (0);
	tail = ft_lstlast(*stack);
	n2 = (*stack)->next;
	tail->next = *stack;
	(*stack)->next = NULL;
	*stack = n2;
}

static int	ft_rev_rotate(t_list **stack)
{
	t_list	*tail;
	t_list	*before_last;

	if (!*stack || !(*stack)->next)
		return (0);
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	tail = before_last->next;
	before_last->next = NULL;
	tail->next = *stack;
	*stack = tail;
	return (1);
}
