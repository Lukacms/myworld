/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** mem_alloc_int
*/

#include <string.h>
#include <stdlib.h>

int **mem_alloc_int(int nb_rows, int nb_cols)
{
    int **dest = malloc(sizeof(int *) * nb_rows);

    for (int i = 0; i < nb_rows; i += 1) {
        dest[i] = malloc(sizeof(int) * nb_cols);
        memset(dest[i], 0, nb_cols * 4);
    }
    return dest;
}
