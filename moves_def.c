/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:55:12 by eproust           #+#    #+#             */
/*   Updated: 2024/11/28 21:35:34 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
 * Execute a push: move the top node of stack 'from' to the top of stack 'to'.
 * Also update value of size_a and value of szie_b.
 */
void	move_push(char *move, t_stack **from, t_stack **to, int *size_a, int *size_b)
{
	int	success;

	success = 0;
	success = do_push(from, to);
	*size_a -= 1;
	*size_b += 1;
	if (success)
	{
		ft_putstr_fd(move, 1);
		ft_putchar_fd('\n', 1);	
		move[1] == 'b' ? ft_debug("PRINT_STACKS", *from, *to) : ft_debug("PRINT_STACKS", *to, *from); // TODO Delete line
	}
}

/*
 * Executes a single move on a stack:
 * swap (0), rotate (1), or reverse rotate (-1).
 */
void	move_one(char *move, t_stack **stack)
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
			ft_debug(ft_strrchr(move, 'a') ? "PRINT_STACK_A" : "PRINT_STACK_B", *stack); // TODO Delete line
	}
}

/*
	 * Execute a same single move on both stacks simultaneously:
 * swap (0), rotate (1), or reverse rotate (-1).
 */
void	move_both(char *move, t_stack **a, t_stack **b)
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
		ft_debug("PRINT_STACKS", *a, *b); // TODO Delete line
	}
}
