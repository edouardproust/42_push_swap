/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 05:57:06 by eproust           #+#    #+#             */
/*   Updated: 2024/11/29 23:06:44 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int is_unique(int *generated, int size, int num) {
    int	i;

	i = 0;
	while (i < size) {
        if (generated[i] == num) {
            return (0);
        }
		i++;
    }
    return (1);
}

int	generate_random(int range)
{
	int random;

	random = rand() % range;
	if (rand() % 2 == 1)
		random = -random;
	return (random);
}

int main(int argc, char **argv)
{
	int size;
	int range;
	int random_num;
	int	*generated;
	int	generated_count;
	int	fails;
	int	i;

	if (argc < 2)
		return (fprintf(stderr, "Usage: %s <list_size> [range]\n", argv[0]), 1);
	size = atoi(argv[1]);
	range = RAND_MAX;
	if (argc == 3)
		range = atoi(argv[2]);
	if (size <= 0)
		return (fprintf(stderr, "List size must be a positive integer.\n"), 1);
	srand((unsigned int)(clock() * 1000000L));
	generated = (int *)malloc(size * sizeof(int));
	if (!generated)
		return (fprintf(stderr, "Malloc error.\n"), 1);
	generated_count = 0;
	fails = 0;
	while (generated_count + fails < size)
	{
		random_num = generate_random(range);
        if (is_unique(generated, generated_count, random_num))
            generated[generated_count++] = random_num;
		else
			fails++;
    }
    i = 0;
	while (i < generated_count)
        printf("%d ", generated[i++]);
    free(generated);
    return 0;
}

