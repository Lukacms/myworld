/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** draw_menu
*/

#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"

int draw_menu(game_object_t *game)
{
    animated_button(game);
    sfRenderWindow_drawSprite(game->window, game->menu.background, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.logo, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.start, NULL);
    sfRenderWindow_drawText(game->window, game->menu.input, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.seed, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.file, NULL);
    return SUCCESS;
}
