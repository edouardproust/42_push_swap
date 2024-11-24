/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:32:10 by eproust           #+#    #+#             */
/*   Updated: 2024/11/24 19:46:13 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include <stdio.h>

void	ft_debug(const char *move, t_list *a, t_list *b);
t_list	*parse_args(t_list **stack, char ***args, int is_malloc_args);

#endif
