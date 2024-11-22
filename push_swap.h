/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:10:48 by eproust           #+#    #+#             */
/*   Updated: 2024/11/22 20:42:40 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

// Sort
void	sort_dispatch(t_list *a, t_list *b);
void    ft_sort_three(t_list *lst);
void	calc_perform_actions(t_list *a, t_list *b, int *size_a);

// Actions
void    swap(char stack_letter, t_list **stack);
void    push(char stack_letter, t_list **from, t_list **to);
void    rotate(char stack_letter, t_list **stack);
void    rev_rotate(char stack_letter, t_list **stack);

// Utils
void	free_matrix(char **arr);
int		is_valid_number(char *n);

// List utils
int		get_val(t_list *lst);
void	del_node_content(void *content);
t_list	*get_max_node(t_list *lst);

#endif
