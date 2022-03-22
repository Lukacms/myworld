/*
** EPITECH PROJECT, 2022
** MyWorld [WSL: Manjaro]
** File description:
** is_randomizer
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"
#include "my.h"

static void randomize_map(game_object_t *game)
{
    int random = rand() % rand();

    srand(random);
    fill_with_noise(game->maps.og_map);
}

void is_randomizer(game_object_t *game, sfMouseButtonEvent button)
{
    if (is_in_box(game->toolbar.rand, button.x, button.y, game->scaling)
        == true) {
        randomize_map(game);
        game->maps.map_2d = create_2d_map(game->maps.og_map, game);
    }
}
