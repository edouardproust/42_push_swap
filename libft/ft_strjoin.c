/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:41:42 by eproust           #+#    #+#             */
/*   Updated: 2024/09/19 16:51:16 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*start;

	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	start = join;
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (start);
}

/*
#include <stdio.h>

int	main(void)
{
	char *s1 = "Hello";
	char *s2 = ", World!";	

	char *join = ft_strjoin(s1, s2);
	printf("s1: '%s'\ns2: '%s'\nft_join(s1, s2): '%s'\n", s1, s2, join);
	free(join);
	return (0);
}
*/
