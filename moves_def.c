/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:55:12 by eproust           #+#    #+#             */
/*   Updated: 2024/11/25 17:41:54 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// TODO To move to another file (norminette):
int	do_push(t_list **from, t_list **to);
int	do_swap(t_list **stack);
int	do_rotate(t_list **stack);
int	do_rev_rotate(t_list **stack);

/*
 * Execute a push: move the top node of stack 'from' to the top of stack 'to'.
 * Also update value of size_a and value of szie_b.
 */
void	move_push(char *move, t_list **a, t_list **b, int *size_a, int *size_b)
{
	int	success;

	success = 0;
	if (move[1] == 'b')
	{
		success = do_push(a, b);
		*size_a -= 1;
		*size_b += 1;
	}
	else
	{
		success = do_push(b, a);
		*size_a += 1;
		*size_b -= 1;
	}
	if (success)
	{
		ft_putstr_fd(move, 1);
		ft_putchar_fd('\n', 1);	
		ft_debug("PRINT_LISTS", *a, *b); // TODO Delete line
	}
}

/*
 * Executes a single move on a stack:
 * swap (0), rotate (1), or reverse rotate (-1).
 */
void	move_one(char *move, t_list **stack)
{
	int	success;

	success = 0;
	if (move[0] == 's')
		success = do_swap(stack);
	else if (move[0] == 'r' && move[1] != 'r')
		success = do_rotate(stack);
	else if (ft_strncmp(move, "rr", 2) == 0)
		success = do_rev_rotate(stack);
	if (success)
	{
			ft_putstr_fd(move, 1);
			ft_putchar_fd('\n', 1);
			ft_debug(ft_strrchr(move, 'a') ? "PRINT_LIST_A" : "PRINT_LIST_B", *stack); // TODO Delete line
	}
}

/*
	 * Execute a same single move on both stacks simultaneously:
 * swap (0), rotate (1), or reverse rotate (-1).
 */
void	move_both(char *move, t_list **a, t_list **b)
{
	int	success;

	success = 0;
	if (ft_strncmp(move, "ss", 3) == 0)
	{
		success = do_swap(a);
		success |= do_swap(b);
	}
	else if (ft_strncmp(move, "rr", 3) == 0)
	{
		success = do_rotate(a);
		success |= do_rotate(b);
	}
	else if (ft_strncmp(move, "rrr", 4) == 0)
	{
		success = do_rev_rotate(a);
		success |= do_rev_rotate(b);
	}
	if (success)
	{
		ft_putstr_fd(move, 1);	
		ft_putchar_fd('\n', 1);
		ft_debug("PRINT_LISTS", *a, *b); // TODO Delete line
	}
}

int	do_push(t_list **from, t_list **to)
{
	t_list	*f2;

	if (!(*from))
		return (0);
	f2 = (*from)->next;
	ft_lstadd_front(to, *from);
	*from = f2; 
	return (1);
}

int	do_swap(t_list **stack)
{
	t_list	*n2;

	if (!*stack || !(*stack)->next)
		return (0);
	n2 = (*stack)->next;
	(*stack)->next = n2->next;
	n2->next = (*stack);
	*stack = n2;
	return (1);
}

int	do_rotate(t_list **stack)
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
	return (1);
}

int	do_rev_rotate(t_list **stack)
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
