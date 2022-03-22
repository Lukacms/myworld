/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** window_initialization
*/

#include <SFML/Graphics.h>
#include "myworld/game.h"

int window_init(game_object_t *game)
{
    sfVideoMode mode = {1920, 1080, 32};
    char const *title = "MyWorld";

    game->window = sfRenderWindow_create(mode, title,
                    sfResize | sfClose, NULL);
    if (!game->window)
        return FAILURE;
    sfRenderWindow_setFramerateLimit(game->window, 60);
    return SUCCESS;
}
