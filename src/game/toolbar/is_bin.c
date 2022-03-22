/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** is_bin
*/

#include <stdbool.h>
#include <string.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"

static void reinit_map(int **map)
{
    for (int i = 0; i < MAP_Y; i += 1)
        memset(map[i], 0, MAP_X * 4);
}

void is_bin(game_object_t *game, sfMouseButtonEvent button)
{
    if (is_in_box(game->toolbar.reinit, button.x, button.y, game->scaling)
        == true) {
        reinit_map(game->maps.og_map);
        game->maps.map_2d = create_2d_map(game->maps.og_map, game);
    }
}
