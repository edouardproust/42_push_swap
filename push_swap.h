/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:10:48 by eproust           #+#    #+#             */
/*   Updated: 2024/11/25 20:43:00 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

// Sort
void	sort_dispatch(t_list *a, t_list *b);
void    sort_three(t_list **lst);
void	calc_do_moves(t_list **a, t_list **b, int *size_a, int *size_b);

// Moves
void	move_push(char *move, t_list **a, t_list **b, int *size_a, int *size_b);
void	move_one(char *move, t_list **stack);
void	move_both(char *move, t_list **a, t_list **b);

// Utils
void	free_matrix(char **arr);
int		is_valid_number(char *n);

// List utils
int		get_val(t_list *lst);
int		get_vall(t_list *lst); // Refactoring to remove this function
void	del_node_content(void *content);
int		get_bound_index(int boundary, t_list *lst);

#endif
