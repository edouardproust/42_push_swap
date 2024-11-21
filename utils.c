/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:56:11 by eproust           #+#    #+#             */
/*   Updated: 2024/11/21 18:06:05 by eproust          ###   ########.fr       */
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
