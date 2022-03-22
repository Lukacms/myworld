/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** destroy_resources
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "myworld.h"
#include "myworld/game.h"

static void destroy_maps(game_object_t *game)
{
    if (!game->maps.og_map || !game->maps.map_2d)
        return;
    for (int i = 0; i < MAP_Y; i++) {
        free(game->maps.og_map[i]);
        free(game->maps.map_2d[i]);
    }
    free(game->maps.map_2d);
    free(game->maps.og_map);
}

static void destroy_entities(game_object_t *game)
{
    sfRenderWindow_destroy(game->window);
    sfClock_destroy(game->game_clock);
}

void destroy_resources(game_object_t *game)
{
    free_list(game);
    destroy_maps(game);
    sfMusic_stop(game->music);
    sfMusic_destroy(game->music);
    destroy_entities(game);
    destroy_toolbar(game);
    destroy_menu(game);
}
