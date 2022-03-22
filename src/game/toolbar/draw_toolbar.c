/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** draw_toolbar
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"

static void moving_toolbar_elements(game_object_t *game, int x)
{
    sfSprite_move(game->toolbar.toolbar, (sfVector2f){x, 0});
    sfSprite_move(game->toolbar.reinit, (sfVector2f){x, 0});
    sfSprite_move(game->toolbar.corner, (sfVector2f){x, 0});
    sfSprite_move(game->toolbar.slab, (sfVector2f){x, 0});
    sfSprite_move(game->toolbar.rand, (sfVector2f){x, 0});
    sfSprite_move(game->toolbar.spr_load, (sfVector2f){x, 0});
    sfSprite_move(game->toolbar.spr_save, (sfVector2f){x, 0});
    sfText_move(game->toolbar.input, (sfVector2f){x, 0});
}

int draw_toolbar(game_object_t *game)
{
    if (game->toolbar.x_offset <= 255 && game->status == TOOL) {
        game->toolbar.x_offset += 5;
        moving_toolbar_elements(game, 5);
    } else if (game->toolbar.x_offset > 0 && game->status == GAME) {
        game->toolbar.x_offset -= 5;
        moving_toolbar_elements(game, -5);
    }
    sfRenderWindow_drawSprite(game->window, game->toolbar.toolbar, NULL);
    sfRenderWindow_drawSprite(game->window, game->toolbar.reinit, NULL);
    sfRenderWindow_drawSprite(game->window, game->toolbar.corner, NULL);
    sfRenderWindow_drawSprite(game->window, game->toolbar.slab, NULL);
    sfRenderWindow_drawSprite(game->window, game->toolbar.rand, NULL);
    sfRenderWindow_drawSprite(game->window, game->toolbar.spr_save, NULL);
    sfRenderWindow_drawSprite(game->window, game->toolbar.spr_load, NULL);
    sfRenderWindow_drawText(game->window, game->toolbar.input, NULL);
    if (game->toolbar.is_help == true) {
        sfRenderWindow_drawSprite(game->window, game->toolbar.s_help, NULL);
        sfRenderWindow_drawText(game->window, game->toolbar.help, NULL);
    }
    return SUCCESS;
}
