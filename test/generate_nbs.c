/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_nbs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 05:57:06 by eproust           #+#    #+#             */
/*   Updated: 2024/11/29 06:33:58 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    // Vérification du nombre d'arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <taille_de_liste>\n", argv[0]);
        return 1;
    }

    // Récupération de la taille de la liste depuis l'argument
    int size = atoi(argv[1]);

    // Vérification de la validité de la taille
    if (size <= 0) {
        fprintf(stderr, "La taille de la liste doit être un entier positif.\n");
        return 1;
    }

    // Initialisation du générateur de nombres aléatoires avec une graine plus précise
    srand((unsigned int)(clock() * 1000000L)); // Multiplier par 1 million pour une plus grande granularité

    // Générer et afficher la liste d'entiers aléatoires
    for (int i = 0; i < size; i++) {
        // Générer un nombre aléatoire entre INT_MIN et INT_MAX
        int random_num = rand();

        // Pour rendre le nombre soit positif ou négatif, nous appliquons une modification
        if (rand() % 2 == 0) {
            random_num = -random_num;
        }

        // Afficher le nombre
        printf("%d ", random_num);
    }

    printf("\n");

    return 0;
}

