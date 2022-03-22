/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** toolbar_events
*/

#include <SFML/Graphics.h>
#include "myworld.h"
#include "myworld/game.h"

static void default_button_size(game_object_t *game)
{
    sfSprite_setScale(game->toolbar.reinit, (sfVector2f){0.05, 0.05});
    if (game->maps.status == SLAB) {
        sfSprite_setScale(game->toolbar.slab, (sfVector2f){0.70, 0.70});
        sfSprite_setScale(game->toolbar.corner, (sfVector2f){0.6, 0.6});
    } else {
        sfSprite_setScale(game->toolbar.corner, (sfVector2f){0.70, 0.70});
        sfSprite_setScale(game->toolbar.slab, (sfVector2f){0.6, 0.6});
    }
    sfSprite_setScale(game->toolbar.rand, (sfVector2f){0.6, 0.6});
    sfSprite_setScale(game->toolbar.spr_load, (sfVector2f){0.45, 0.45});
    sfSprite_setScale(game->toolbar.spr_save, (sfVector2f){0.25, 0.25});
}

static void is_game(game_object_t *game, sfMouseButtonEvent button)
{
    int offset = game->toolbar.x_offset;

    if (button.x > 0 + offset && button.x < 52 + offset
        && button.y > 210 && button.y < 290)
        game->status = GAME;
}

int analyse_toolbar_events(game_object_t *game, sfEvent event)
{
    default_button_size(game);
    if (event.type == sfEvtTextEntered)
        manage_text_entered(game, event);
    if (event.type == sfEvtMouseButtonPressed) {
        is_game(game, event.mouseButton);
        is_bin(game, event.mouseButton);
        is_save(game, event.mouseButton);
        is_load(game, event.mouseButton);
        is_randomizer(game, event.mouseButton);
        slab_or_corner(game, event.mouseButton);
    } else if (event.type == sfEvtMouseMoved)
        display_help(game, event.mouseMove);
    return SUCCESS;
}
