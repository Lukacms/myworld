/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** game_events
*/

#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"

static int is_toolbar(game_object_t *game, sfMouseButtonEvent button)
{
    if (button.x > 0 && button.x < 52 * game->scaling.x &&
        button.y > 210 * game->scaling.y && button.y < 290 * game->scaling.y) {
        game->status = TOOL;
        return SUCCESS;
    }
    return FAILURE;
}

int analyse_game_events(game_object_t *game, sfEvent event)
{
    zoom_management(game, event);
    if (event.type == sfEvtKeyPressed) {
        rotate_management(game, event);
        moving_management(game, event);
        if (event.key.code == sfKeyNumpad1)
            game->maps.status = CORNER;
        if (event.key.code == sfKeyNumpad2)
            game->maps.status = SLAB;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        if (is_toolbar(game, event.mouseButton) == SUCCESS)
            return SUCCESS;
        if (game->maps.status == CORNER)
            corner_detection(game, event);
        else
            slab_detection(game, event);
    }
    return SUCCESS;
}
