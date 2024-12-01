/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:56:11 by eproust           #+#    #+#             */
/*   Updated: 2024/12/01 14:33:07 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	error_exit(char **av, t_stack *stack, int is_malloc_av)
{
	ft_putstr_fd("Error\n", 1);
	if (is_malloc_av)
		free_matrix(av);
	if (stack)
		clear_stack(&stack);
	exit(1);
}

int	is_valid_number(char *n)
{
	if (*n == '-' || *n == '+')
		n++;
	if (!('0' <= *n && *n <= '9'))
		return (0);
	while ('0' <= *n && *n <= '9')
		n++;
	return (*n == '\0');
}
