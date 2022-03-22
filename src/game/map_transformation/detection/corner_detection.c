/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** corner_detection
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"

int corner_detection(game_object_t *game, sfEvent event)
{
    sfVector2i pos = sfMouse_getPosition(NULL);
    sfVector2i in_map = is_in_map(game->maps.map_2d, pos);

    if (in_map.x < 0)
        return FAILURE;
    while (sfMouse_isButtonPressed(event.mouseButton.button)) {
        pos = sfMouse_getPosition(NULL);
        sfRenderWindow_clear(game->window, sfBlack);
        if (game->maps.map_2d[in_map.y][in_map.x].y <= pos.y)
            game->maps.og_map[in_map.y][in_map.x] -= 5;
        if (game->maps.map_2d[in_map.y][in_map.x].y > pos.y)
            game->maps.og_map[in_map.y][in_map.x] += 5;
        free_2d_map(game);
        game->maps.map_2d = create_2d_map(game->maps.og_map, game);
        display_game(game);
        sfRenderWindow_display(game->window);
    }
    return SUCCESS;
}
