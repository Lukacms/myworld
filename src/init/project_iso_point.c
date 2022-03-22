/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** project_iso_point
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include "myworld.h"

sfVector2f project_iso_point(int x, int y, int z, game_object_t *game)
{
    sfVector2f result = {0};
    float angle_x = game->maps.angles.x * (M_PI / 180.0);
    float angle_y = game->maps.angles.y * (M_PI / 180.0);
    sfVector2i pos = game->maps.pos;

    result.x = cos(angle_x) * x - cos(angle_x) * y + pos.x / 2;
    result.y = sin(angle_y) * y + sin(angle_y) * x -
                z + (pos.y - MAP_X * 16) / 2;
    return result;
}
