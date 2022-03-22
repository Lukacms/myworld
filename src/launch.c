/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "myworld.h"

static const game_status_t game_handler[] = {
    {.status = MENU, .scene_handler = &draw_menu},
    {.status = GAME, .scene_handler = &display_game},
    {.status = TOOL, .scene_handler = &display_game},
    {0}
};

static void get_events(game_object_t *game)
{
    sfEvent event = {0};

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
            event.key.code == sfKeyEscape))
            sfRenderWindow_close(game->window);
        analyse_events(game, event);
    }
}

static void execute_actions(game_object_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    get_events(game);
    for (int i = 0; game_handler[i].scene_handler; i += 1) {
        if (game->status == game_handler[i].status) {
            game_handler[i].scene_handler(game);
            sfRenderWindow_display(game->window);
            return;
        }
    }
}

static void game_loop(game_object_t *game)
{
    sfTime time = {0};
    float seconds = 0.0;

    while (sfRenderWindow_isOpen(game->window)) {
        time = sfClock_getElapsedTime(game->game_clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.01) {
            execute_actions(game);
            sfClock_restart(game->game_clock);
        }
    }
}

int launch(void)
{
    game_object_t *game = malloc(sizeof(game_object_t));

    if (!game)
        return FAILURE;
    if (init_game(game) != SUCCESS)
        return FAILURE;
    sfMusic_play(game->music);
    game_loop(game);
    if (game->status != MENU)
        print_map_in_file(game->maps.og_map, MAP_Y, MAP_X, "default");
    destroy_resources(game);
    free(game);
    return SUCCESS;
}
