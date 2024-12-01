/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:55:12 by eproust           #+#    #+#             */
/*   Updated: 2024/12/01 16:21:25 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define DEBUG 1 // TODO Debug (remove line)

/**
 * To debug, add this line before function closing bracket:
 *	if (DEBUG) (*to)->sname == 'a' ? ft_debug(*to, *from) : 
 *		ft_debug(*from, *to);
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
	if (DEBUG) (*to)->sname == 'a' ? ft_debug(*to, *from) : ft_debug(*from, *to); //TODO Debug (remove line)
}

/**
 * To debug, add this line before function closing bracket:
 * if (DEBUG) (*stack)->sname == 'a' ? ft_debug(*stack, NULL) : 
 *	ft_debug(NULL, *stack);
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
	if (DEBUG) (*stack)->sname == 'a' ? ft_debug(*stack, NULL) : ft_debug(NULL, *stack); //TODO Debug (remove line)
}

/**
 * To debug, add this line before function closing bracket:
 *	if (DEBUG) ft_debug(*a, *b);
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
	if (DEBUG) ft_debug(*a, *b); //TODO
}
