/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:10:48 by eproust           #+#    #+#             */
/*   Updated: 2024/11/19 22:53:06 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO Update list of .c files in Makefile

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

void	ft_do(char *action, t_list **a, t_list **b);

//TODO Remove the follwing calls + corresponding files:
#include <stdio.h>
void	ft_debug(const char *action, t_list **a, t_list **b);
t_list	*parse_args(t_list **stack, char ***args, int is_malloc_args); // TODO Set as static in push_swap.c

#endif
