/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** init_game
*/

#include <SFML/Graphics.h>
#include "myworld.h"
#include "myworld/game.h"

static void init_struct(game_object_t *game)
{
    game->window = NULL;
    game->status = MENU;
    game->textures.head = NULL;
    game->textures.size = 0;
    game->maps.og_map = NULL;
    game->maps.map_2d = NULL;
    game->game_clock = NULL;
    game->maps.angles = (sfVector2i){20, 25};
    game->maps.sampling = 16;
    game->maps.pos = (sfVector2i){1920, 1080};
    game->maps.status = CORNER;
    game->scaling = (sfVector2f){1, 1};
}

int init_game(game_object_t *game)
{
    if (!game)
        return FAILURE;
    init_struct(game);
    if (window_init(game) == FAILURE)
        return FAILURE;
    if (init_textures(game) == FAILURE)
        return FAILURE;
    if (init_game_entities(game) == FAILURE)
        return FAILURE;
    if (init_menu(game) == FAILURE)
        return FAILURE;
    if (init_toolbar(game) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
