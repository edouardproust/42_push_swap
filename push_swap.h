/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:10:48 by eproust           #+#    #+#             */
/*   Updated: 2024/11/24 20:04:27 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

// Sort
void	sort_dispatch(t_list *a, t_list *b);
void    sort_three(t_list *lst);
void	calc_do_moves(t_list *a, t_list *b, int *size_a);

// Moves
void	move_push(char *move, t_list **from, t_list **to);
void	move_one(char *move, t_list *stack);
void	move_both(char *move, t_list *a, t_list *b);

// Utils
void	free_matrix(char **arr);
int		is_valid_number(char *n);

// List utils
int		get_val(t_list *lst);
void	del_node_content(void *content);
t_list	*get_max_node(t_list *lst);

#endif
