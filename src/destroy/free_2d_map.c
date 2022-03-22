/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** free_2d_map
*/

#include <stdlib.h>
#include "myworld/game.h"

void free_2d_map(game_object_t *game)
{
    for (int i = 0; i < MAP_Y; i++)
        free(game->maps.map_2d[i]);
    free(game->maps.map_2d);
}
