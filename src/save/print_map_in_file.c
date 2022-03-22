/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** print_map_in_file
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "myworld/game.h"
#include "myworld.h"
#include "my.h"

int print_map_in_file(int **map, int nb_rows, int nb_cols, char *file)
{
    FILE *fd = fopen((file == NULL ? "default" : file), "w+");
    char *nb = NULL;

    if (!fd || !map)
        return FAILURE;
    for (int i = 0; i < nb_rows; i += 1) {
        for (int j = 0; j < nb_cols; j += 1) {
            nb = my_int_to_str(map[i][j]);
            fwrite(nb, my_strlen(nb), 1, fd);
            fwrite(" ", 1, 1, fd);
            free(nb);
        }
        fwrite("\n", 1, 1, fd);
    }
    fclose(fd);
    return SUCCESS;
}
