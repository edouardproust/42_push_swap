/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:00:07 by eproust           #+#    #+#             */
/*   Updated: 2024/11/18 20:07:11 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2d_array(char **arr)
{
	while (*arr)
	{
		free(*arr);
		*arr = NULL;
		arr++;
	}
	free(arr);
}

// TODO: ask if this is enough checks
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

/*
 * Check that the stack contains values that are unique and can be stored in an int.
 */
int	check_stack(t_list *stack)
{
	t_list	*nex;

	while (stack)
	{
		if (*(int *)(stack->content) > INT_MAX)
			return (0);
		nex = stack->next;
		while (nex)
		{
			if (*(int *)(stack->content) == *(int *)(nex->content))
				return (0);
			nex = nex->next;
		}
		stack = stack->next;
	}
	return (1);
}

t_list	*parse_args(t_list **stack, char **args, int is_malloc_args)
{
	t_list	*node;
	long	n;

	while (*args)
	{
		if (!is_valid_number(*args))
			ft_lstclear(stack, NULL);
		n = ft_atoi(*args);
		node = ft_lstnew(&n);
		ft_lstadd_back(stack, node);
	}
//	if (is_malloc_args)
//		free_2d_array(args);
	//if (*stack && !check_stack(*stack))
	//	ft_lstclear(stack, NULL);
	return (*stack);
}

int	main(int ac, char **av)
{
	t_list	*a;
	char	**args;
	//t_list	*b;

	a = NULL;
	//b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
		exit(2);
	args = av;
	if (ac == 2)
		args = ft_split((const char *)av[1], ' ');
	a = parse_args(&a, args, ac == 2);
	if (!a)
	{
		ft_putstr_fd("Error", 1);
		exit(2);
	}
	printf("Todo bien");
	return (0);
}
