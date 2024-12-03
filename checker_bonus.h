/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 04:39:48 by eproust           #+#    #+#             */
/*   Updated: 2024/12/03 04:52:06 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include <unistd.h>

# define BUF_SIZE 20

int		do_move(char *move, t_stack **a, t_stack **b);
int		check_do_moves(char *inputs, t_stack **a, t_stack **b);
void	print_result_clear(int moves_res, t_stack **a, t_stack **b);
void	set_inputs(char **inputs);
char	**handle_arguments(int ac, char **av);

#endif
