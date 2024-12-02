/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:56:11 by eproust           #+#    #+#             */
/*   Updated: 2024/12/02 05:16:06 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Frees a null-terminated array of strings.
 *
 * Iterates through each string in the array, frees it, and sets the pointer
 * to NULL. Frees the array itself and sets the pointer to NULL.
 *
 * @param arr A null-terminated array of strings to free.
 */
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

/**
 * Exits the program with an error message.
 *
 * Prints "Error\n" to stdout, frees allocated resources, and exits the program.
 *
 * @param av The input arguments array, dynamically allocated if `is_malloc_av`
 *           is true.
 * @param stack The stack to free, if not NULL.
 * @param is_malloc_av Flag indicating if `av` was dynamically allocated.
 */
void	error_exit(char **av, t_stack *stack, int is_malloc_av)
{
	ft_putstr_fd("Error\n", 1);
	if (is_malloc_av)
		free_matrix(av);
	if (stack)
		clear_stack(&stack);
	exit(1);
}

/**
 * Validates if a string represents a valid integer.
 *
 * Checks if the input string is a valid representation of a number,
 * allowing an optional '+' or '-' sign at the beginning.
 *
 * @param n The string to validate.
 * @return 1 if the string is valid, 0 otherwise.
 */
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
