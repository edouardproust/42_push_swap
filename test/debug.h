/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:32:10 by eproust           #+#    #+#             */
/*   Updated: 2024/12/01 16:10:19 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include <stdio.h>

int		get_digits_nb(int n);
int		max_digits_nb(t_stack *stack);
void	print_node_data(char *prefix, t_stack *stack);
void	repeat_char(char *c, int n);
int		get_cols(int digits_a, int digits_b);

#endif
