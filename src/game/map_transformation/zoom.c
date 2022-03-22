/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** zoom
*/

#include <SFML/Graphics.h>
#include "myworld.h"

void zoom_management(game_object_t *game, sfEvent event)
{
    if (event.key.code == sfKeyAdd || (event.type == sfEvtMouseWheelScrolled
        && event.mouseWheelScroll.delta > 0)) {
        free_2d_map(game);
        game->maps.sampling += 1;
        game->maps.map_2d = create_2d_map(game->maps.og_map, game);
    } else if ((event.key.code == sfKeySubtract && game->maps.sampling > 1) ||
                (event.type == sfEvtMouseWheelScrolled &&
                event.mouseWheelScroll.delta < 0)) {
        free_2d_map(game);
        game->maps.sampling -= 1;
        game->maps.map_2d = create_2d_map(game->maps.og_map, game);
    }
}
