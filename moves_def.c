/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:55:12 by eproust           #+#    #+#             */
/*   Updated: 2024/12/02 21:44:05 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * Executes a push operation between two stacks.
 *
 * The top element of the `from` stack is moved to the top of the `to` stack.
 * If the operation is successful, the move is printed in the format:
 * "pX\n", where `X` is the name of the `to` stack.
 *
 * @param from A pointer to the source stack.
 * @param to A pointer to the destination stack.
 */
void	move_push(t_stack **from, t_stack **to)
{
	int	success;

	success = do_push(from, to);
	if (success)
	{
		ft_putchar_fd('p', 1);
		ft_putchar_fd((*to)->sname, 1);
		ft_putchar_fd('\n', 1);
	}
}

/**
 * Executes a single move operation on a stack.
 *
 * Depending on the `move` string, this function performs one of the following:
 * - "s" : Swap the first two elements of the stack.
 * - "r" : Rotate the stack upwards (first element becomes last).
 * - "rr": Reverse rotate the stack (last element becomes first).
 *
 * If the operation is successful, the move is printed in the format:
 * "moveX\n", where `X` is the name of the stack.
 *
 * @param move A string representing the move to execute ("s", "r", "rr").
 * @param stack A pointer to the stack on which to perform the move.
 */
void	move_one(char *move, t_stack **stack)
{
	int	success;

	success = 0;
	if (ft_strncmp(move, "s", 2) == 0)
		success = do_swap(stack);
	else if (ft_strncmp(move, "r", 2) == 0)
		success = do_rotate(stack);
	else if (ft_strncmp(move, "rr", 3) == 0)
		success = do_rev_rotate(stack);
	if (success)
	{
		ft_putstr_fd(move, 1);
		ft_putchar_fd((*stack)->sname, 1);
		ft_putchar_fd('\n', 1);
	}
}

/**
 * Executes a simultaneous move operation on two stacks.
 *
 * Depending on the `move` string, this function performs one of the following:
 * - "ss" : Swap the first two elements of both stacks.
 * - "rr" : Rotate both stacks upwards.
 * - "rrr": Reverse rotate both stacks.
 *
 * If any operation is successful, the move is printed in the format:
 * "move\n".
 *
 * @param move A string representing the move to execute ("ss", "rr", "rrr").
 * @param a A pointer to the first stack.
 * @param b A pointer to the second stack.
 */
void	move_both(char *move, t_stack **a, t_stack **b, int print)
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
	if (print && success)
	{
		ft_putstr_fd(move, 1);
		ft_putchar_fd('\n', 1);
	}
}
