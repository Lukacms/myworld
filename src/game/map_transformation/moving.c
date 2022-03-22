/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** moving
*/

#include <SFML/Graphics.h>
#include "myworld.h"

void moving_management(game_object_t *game, sfEvent event)
{
    if (event.key.code == sfKeyQ) {
        free_2d_map(game);
        game->maps.pos.x -= 10;
        game->maps.map_2d = create_2d_map(game->maps.og_map, game);
    } else if (event.key.code == sfKeyD) {
        free_2d_map(game);
        game->maps.pos.x += 10;
        game->maps.map_2d = create_2d_map(game->maps.og_map, game);
    }
    if (event.key.code == sfKeyZ) {
        free_2d_map(game);
        game->maps.pos.y -= 10;
        game->maps.map_2d = create_2d_map(game->maps.og_map, game);
    } else if (event.key.code == sfKeyS) {
        free_2d_map(game);
        game->maps.pos.y += 10;
        game->maps.map_2d = create_2d_map(game->maps.og_map, game);
    }
}
