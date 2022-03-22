/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** display_game
*/

#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"

int display_game(game_object_t *game)
{
    draw_map(game);
    draw_toolbar(game);
    return SUCCESS;
}
