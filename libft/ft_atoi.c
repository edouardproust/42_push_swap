/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:03:27 by eproust           #+#    #+#             */
/*   Updated: 2024/09/17 13:03:29 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;

	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	res = 0;
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (res * sign);
}

/*
#include <stdio.h>
#include <stdlib.h>

void	main(void)
{
	char *str = "-0y45us";

	printf("string: \"%s\"\n", str);
	printf("ft_atoi: %d\n", ft_atoi(str));
	printf("atoi: %d\n", atoi(str));
}
*/
