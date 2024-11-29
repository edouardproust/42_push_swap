/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:55:12 by eproust           #+#    #+#             */
/*   Updated: 2024/11/29 06:02:36 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
 * Execute a push: move the top node of stack 'from' to the top of stack 'to'.
 * Also update value of size_a and value of szie_b.
 *
 * To debug, use this before function closing bracket:
 * 	to_name == 'b' ? ft_debug("PRINT_STACKS", *from, *to) : 
 * 	ft_debug("PRINT_STACKS", *to, *from);
 */
void	move_push(t_stack **from, t_stack **to, char to_name, int *size_from, int *size_to)
{
	int	success;

	success = 0;
	success = do_push(from, to);
	*size_from -= 1;
	*size_to += 1;
	if (success)
	{
		ft_putchar_fd('p', 1);
		ft_putchar_fd(to_name, 1);
		ft_putchar_fd('\n', 1);	
	}
//	to_name == 'b' ? ft_debug("PRINT_STACKS", *from, *to) : ft_debug("PRINT_STACKS", *to, *from); //TODO
}

/*
 * Executes a single move on a stack:
 * swap (0), rotate (1), or reverse rotate (-1).
 *
 * To debug, add this before function closing bracket:
 * 	ft_debug(ft_strrchr(move, 'a') ? "PRINT_STACK_A" : "PRINT_STACK_B", *stack);
 */
void	move_one(char *move, t_stack **stack, char stack_name)
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
			ft_putchar_fd(stack_name, 1);
			ft_putchar_fd('\n', 1);
	}
//	ft_debug(ft_strrchr(move, 'a') ? "PRINT_STACK_A" : "PRINT_STACK_B", *stack); //TODO
}

/*
 * Execute a same single move on both stacks simultaneously:
 * swap (0), rotate (1), or reverse rotate (-1).
 *
 * To debug, add this before function closing bracket:
 * 	ft_debug("PRINT_STACKS", *a, *b);
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
	}
//	ft_debug("PRINT_STACKS", *a, *b); // TODO
}
