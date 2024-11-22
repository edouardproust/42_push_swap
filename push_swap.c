/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:00:07 by eproust           #+#    #+#             */
/*   Updated: 2024/11/22 20:42:03 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_stack(t_list *stack);

t_list	*parse_args(t_list **stack, char ***args, int is_malloc_args)
{
	t_list	*node;
	long	*n_ptr;
	int		i;

	i = 0;
	while ((*args)[i])
	{
		if (!is_valid_number((*args)[i]))
			break;
		n_ptr = malloc(sizeof(long));
		if (!n_ptr)
			break;
		*n_ptr = ft_atoi((*args)[i]);
		node = ft_lstnew(n_ptr);
		if (!node)
		{	
			free(n_ptr);
			break;
		}
		ft_lstadd_back(stack, node);
		i++;
	}
	// If `(*args)[i]` is not NULL: there was an error in the whioe loop above	
	if ((*args)[i] != NULL || !check_stack(*stack))
	{
		if (is_malloc_args)
			free_matrix(*args);
		return (ft_lstclear(stack, del_node_content), NULL);
	}
	if (is_malloc_args)
		free_matrix(*args);
	return (*stack);
}

int	main(int ac, char **av)
{
	t_list	*a;
	char	**args;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
		exit(2);
	args = av + 1;
	if (ac == 2)
		args = ft_split((const char *)(*args), ' ');
	a = parse_args(&a, &args, ac == 2);
	if (!a)
	{
		ft_putstr_fd("Error\n", 1);
		exit(2);
	}
	sort_dispatch(a, b);
	ft_lstclear(&a, del_node_content);
	return (0);
}

/*
 * Check that the stack contains values that are unique and can be stored in an int.
 */
int	check_stack(t_list *stack)
{
	int		n;
	t_list	*nex;

	if (!stack)
		return (0);
	while (stack)
	{
		n = *(int *)(stack->content); 
		if (n > INT_MAX || n < INT_MIN)
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
