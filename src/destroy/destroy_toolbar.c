/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** destroy_toolbar
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld.h"
#include "myworld/game.h"

void destroy_toolbar(game_object_t *game)
{
    sfSprite_destroy(game->toolbar.corner);
    sfSprite_destroy(game->toolbar.slab);
    sfSprite_destroy(game->toolbar.toolbar);
    sfSprite_destroy(game->toolbar.s_help);
    sfSprite_destroy(game->toolbar.spr_load);
    sfSprite_destroy(game->toolbar.spr_save);
    sfSprite_destroy(game->toolbar.rand);
    sfSprite_destroy(game->toolbar.reinit);
    sfTexture_destroy(game->toolbar.t_corner);
    sfTexture_destroy(game->toolbar.t_help);
    sfTexture_destroy(game->toolbar.t_rand);
    sfTexture_destroy(game->toolbar.t_reinit);
    sfTexture_destroy(game->toolbar.t_slab);
    sfTexture_destroy(game->toolbar.t_toolbar);
    sfTexture_destroy(game->toolbar.tex_save);
    sfText_destroy(game->toolbar.help);
    sfText_destroy(game->toolbar.input);
}