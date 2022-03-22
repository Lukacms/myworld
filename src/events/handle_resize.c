/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** handle_resize
*/

#include <SFML/Graphics.h>
#include "myworld.h"

void handle_resize(game_object_t *game)
{
    sfVector2u window_size = sfRenderWindow_getSize(game->window);

    game->scaling.x = (float)window_size.x / (float)1920.0;
    game->scaling.y = (float)window_size.y / (float)1080.0;
}
