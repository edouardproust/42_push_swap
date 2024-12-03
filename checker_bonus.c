/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:24:20 by eproust           #+#    #+#             */
/*   Updated: 2024/12/03 04:51:03 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*inputs;
	int		result;

	a = NULL;
	b = NULL;
	av = handle_arguments(ac, av);
	if (!av)
		return (ft_putstr_fd("Error\n", 1), 1);
	a = build_stack(a, av, ac == 2);
	set_inputs(&inputs);
	if (!inputs)
	{
		clear_stack(&a);
		return (ft_putstr_fd("Error\n", 1), 1);
	}
	result = check_do_moves(inputs, &a, &b);
	free(inputs);
	print_result_clear(result, &a, &b);
	return (0);
}
