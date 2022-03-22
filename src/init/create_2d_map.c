/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** create_twod_map
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include "myworld.h"

sfVector2f **create_2d_map(int * const map[], game_object_t *game)
{
    sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * MAP_X);

    for (int i = 0; i < MAP_Y; i++) {
        map_2d[i] = malloc(sizeof(sfVector2f) * MAP_X);
        for (int j = 0; j < MAP_X; j++) {
            map_2d[i][j] = project_iso_point(i * game->maps.sampling,
                                j * game->maps.sampling, map[i][j], game);
        }
    }
    return map_2d;
}
