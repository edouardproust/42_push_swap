/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:00:07 by eproust           #+#    #+#             */
/*   Updated: 2024/11/19 22:51:39 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_stack(t_list *stack);
//TODO Move to utils:
static void	free_2d_array(char **arr);
static int	is_valid_number(char *n);
static void del_node_content(void *content);

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
			free_2d_array(*args);
		return (ft_lstclear(stack, del_node_content), NULL);
	}
	if (is_malloc_args)
		free_2d_array(*args);
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

	// TESTS
//	ft_debug("DUMMY_B", &a, &b);
	ft_debug("PRINT_LISTS", &a, &b);	
	ft_do("sa", &a, NULL);
	ft_debug("PRINT_LISTS", &a, &b);	
	ft_do("pb", &a, &b);
	ft_do("pb", &a, &b);
	ft_do("pb", &a, &b);
	ft_debug("PRINT_LISTS", &a, &b);	
	ft_do("rrr", &a, &b);
	ft_debug("PRINT_LISTS", &a, &b);	
	//ft_do("ss", &a, &b);
	//ft_debug("PRINT_LISTS", &a, &b);	

	ft_lstclear(&a, del_node_content);
	ft_lstclear(&b, del_node_content);

	return (0);
}

/*
 * Check that the stack contains values that are unique and can be stored in an int.
 */
static int	check_stack(t_list *stack)
{
	t_list	*nex;

	if (!stack)
		return (0);
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

static void	free_2d_array(char **arr)
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

// TODO: ask if this is enough checks
static int	is_valid_number(char *n)
{
	if (*n == '-' || *n == '+')
		n++;
	if (!('0' <= *n && *n <= '9'))
		return (0);
	while ('0' <= *n && *n <= '9')
		n++;
	return (*n == '\0');
}


static void	del_node_content(void *content)
{
	if (content)
		free(content);
}


