/*
** EPITECH PROJECT, 2022
** MyWorld [WSL: Manjaro]
** File description:
** animated_button
*/

#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"

void animated_button(game_object_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    if (is_in_box(game->menu.start, mouse_pos.x, mouse_pos.y, game->scaling)
        == sfTrue)
        sfSprite_setScale(game->menu.start, (sfVector2f){0.55, 0.55});
    if (is_in_box(game->menu.seed, mouse_pos.x, mouse_pos.y, game->scaling)
        == sfTrue)
        sfSprite_setScale(game->menu.seed, (sfVector2f){1.1, 1.1});
    if (is_in_box(game->menu.file, mouse_pos.x, mouse_pos.y, game->scaling)
        == sfTrue)
        sfSprite_setScale(game->menu.file, (sfVector2f){1.1, 1.1});
    return;
}
