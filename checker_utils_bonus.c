/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 04:37:17 by eproust           #+#    #+#             */
/*   Updated: 2024/12/03 04:56:35 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * Autorized moves: "sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra",
 * "rrb", "rrr"
 */
int	do_move(char *move, t_stack **a, t_stack **b)
{
	if (ft_strncmp("ss", move, 3) == 0 || ft_strncmp("rr", move, 3) == 0
		|| ft_strncmp("rrr", move, 4) == 0)
		move_both(move, a, b, 0);
	else if (ft_strncmp("pa", move, 3) == 0)
		do_push(b, a);
	else if (ft_strncmp("pb", move, 3) == 0)
		do_push(a, b);
	else if (ft_strncmp("sa", move, 3) == 0)
		do_swap(a);
	else if (ft_strncmp("sb", move, 3) == 0)
		do_swap(b);
	else if (ft_strncmp("ra", move, 3) == 0)
		do_rotate(a);
	else if (ft_strncmp("rb", move, 3) == 0)
		do_rotate(b);
	else if (ft_strncmp("rra", move, 4) == 0)
		do_rev_rotate(a);
	else if (ft_strncmp("rrb", move, 4) == 0)
		do_rev_rotate(b);
	else
		return (0);
	return (1);
}

/**
 * @leaks: If `moves = ft_split(...)` fails, we simply returns as
 * we free `inputs` and stacks in `main()`.
 */
int	check_do_moves(char *inputs, t_stack **a, t_stack **b)
{
	char	**moves;
	char	**tmp;

	moves = ft_split(inputs, '\n');
	if (!moves)
		return (0);
	tmp = moves;
	while (*tmp)
	{
		if (do_move(*tmp, a, b) == 0)
		{
			ft_putstr_fd("Error\n", 1);
			free_matrix(moves);
			return (0);
		}
		tmp++;
	}
	free_matrix(moves);
	return (1);
}

void	print_result_clear(int moves_res, t_stack **a, t_stack **b)
{
	if (moves_res)
	{
		if (is_stack_sorted(*a) && *b == NULL)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	clear_stack(a);
	clear_stack(b);
	if (!moves_res)
		exit(1);
}

/**
 * @leaks If `new_inputs = ft_strjoin(...)` fails `new_inputs` is set
 * to NULL, then we free `*inputs` and set it to NULL. So it works
 * without checking `if (!new_inputs) ...`
 */
void	set_inputs(char **inputs)
{
	ssize_t	bytes_read;
	char	buffer[BUF_SIZE + 1];
	char	*new_inputs;

	*inputs = malloc(1);
	if (!inputs)
		return ;
	*inputs[0] = '\0';
	while (1)
	{
		bytes_read = read(0, buffer, BUF_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		new_inputs = ft_strjoin(*inputs, buffer);
		free(*inputs);
		*inputs = new_inputs;
	}
}

char	**handle_arguments(int ac, char **av)
{
	if (ac == 1 || (ac == 2 && !av[1][0]))
		exit(0);
	av++;
	if (ac == 2)
	{
		av = ft_split((const char *)(*av), ' ');
		if (!av)
			return (0);
	}
	return (av);
}
