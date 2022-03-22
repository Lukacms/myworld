/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** is_in_map
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"

static int in_map(sfVector2f **map, sfVector2i *p_map, sfVector2i *pos)
{
    for (pos->x = 0; pos->x < MAP_X - 1; pos->x += 1) {
        if (p_map->x >= map[pos->y][pos->x].x - 20 && p_map->x <=
        map[pos->y][pos->x].x + 20 && p_map->y >= map[pos->y][pos->x].y - 20
        && p_map->y <= map[pos->y][pos->x].y + 20)
            return SUCCESS;
    }
    return FAILURE;
}

sfVector2i is_in_map(sfVector2f **map, sfVector2i pos_map)
{
    sfVector2i pos = {0};

    for (pos.y = 0; pos.y < MAP_Y; pos.y += 1) {
        if (in_map(map, &pos_map, &pos) == SUCCESS)
            return pos;
    }
    return ((sfVector2i){-1, -1});
}
