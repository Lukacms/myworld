/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** display_help
*/

#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"

static int save_help(toolbar_t *toolbar, sfMouseMoveEvent mouse,
                game_object_t *game)
{
    if (is_in_box(toolbar->spr_load, mouse.x, mouse.y, game->scaling)) {
        sfSprite_setScale(toolbar->spr_load, (sfVector2f){0.5, 0.5});
        sfText_setString(toolbar->help, "Load a map from a file.");
        return 1;
    } else if (is_in_box(toolbar->spr_save, mouse.x, mouse.y, game->scaling)) {
        sfSprite_setScale(toolbar->spr_save, (sfVector2f){0.3, 0.3});
        sfText_setString(toolbar->help, "Save the map in a file.");
        return 1;
    }
    return 0;
}

static int other_help(toolbar_t *toolbar, sfMouseMoveEvent mouse,
                game_object_t *game)
{
    if (is_in_box(toolbar->rand, mouse.x, mouse.y, game->scaling)) {
        sfSprite_setScale(toolbar->rand, (sfVector2f){0.65, 0.65});
        sfText_setString(toolbar->help, "Init a new map.");
        return 1;
    } else if (is_in_box(toolbar->reinit, mouse.x, mouse.y, game->scaling)) {
        sfSprite_setScale(toolbar->reinit, (sfVector2f){0.06, 0.06});
        sfText_setString(toolbar->help, "Make the map flat.");
        return 1;
    }
    return save_help(toolbar, mouse, game);
}

static int which_help(toolbar_t *toolbar, sfMouseMoveEvent mouse,
                game_object_t *game)
{
    if (is_in_box(toolbar->corner, mouse.x, mouse.y, game->scaling)) {
        sfSprite_setScale(toolbar->corner, (sfVector2f){0.65, 0.65});
        sfText_setString(toolbar->help,
                        "Change the height of the map using corners.");
        return 1;
    } else if (is_in_box(toolbar->slab, mouse.x, mouse.y, game->scaling)) {
        sfSprite_setScale(toolbar->slab, (sfVector2f){0.65, 0.65});
        sfText_setString(toolbar->help,
                    "Change the height of the map using slabs.");
        return 1;
    }
    return other_help(toolbar, mouse, game);
}

void display_help(game_object_t *game, sfMouseMoveEvent mouse)
{
    int flag = which_help(&game->toolbar, mouse, game);

    if (flag > 0)
        game->toolbar.is_help = true;
    else
        game->toolbar.is_help = false;
    return;
}
