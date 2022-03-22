/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** slab_or_corner
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"

static void is_corner(game_object_t *game, sfMouseButtonEvent button)
{
    if (is_in_box(game->toolbar.corner, button.x, button.y, game->scaling)
        == true)
        game->maps.status = CORNER;
}

static void is_slab(game_object_t *game, sfMouseButtonEvent button)
{
    if (is_in_box(game->toolbar.slab, button.x, button.y, game->scaling)
        == true)
        game->maps.status = SLAB;
}

void slab_or_corner(game_object_t *game, sfMouseButtonEvent button)
{
    is_corner(game, button);
    is_slab(game, button);
}
