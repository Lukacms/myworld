/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** rotation
*/

#include <SFML/Graphics.h>
#include "myworld.h"

void rotate_management(game_object_t *game, sfEvent event)
{
    if (event.key.code == sfKeyLeft && game->maps.angles.x < 45) {
        free_2d_map(game);
        game->maps.angles.x += 5;
        game->maps.map_2d = create_2d_map(game->maps.og_map, game);
    } else if (event.key.code == sfKeyRight && game->maps.angles.x > 0) {
        game->maps.angles.x -= 5;
        game->maps.map_2d = create_2d_map(game->maps.og_map, game);
    }
    if (event.key.code == sfKeyUp && game->maps.angles.y < 45) {
        free_2d_map(game);
        game->maps.angles.y += 5;
        game->maps.map_2d = create_2d_map(game->maps.og_map, game);
    } else if (event.key.code == sfKeyDown && game->maps.angles.y > -45) {
        free_2d_map(game);
        game->maps.angles.y -= 5;
        game->maps.map_2d = create_2d_map(game->maps.og_map, game);
    }
}
