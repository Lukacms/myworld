/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** fill_with_noise
*/

#include <SFML/Graphics.h>
#include "myworld.h"

static int interpolate(int x, int y, int t)
{
    return (1 - t) * x + t * y;
}

static void last_line(int x, int y, int **map)
{
    if (x >= MAP_X - 2)
        map[y][x] = interpolate(map[y][x], map[y][x], x % 2);
    else
        map[y][x] = interpolate(map[y][x], map[y][x + 1], x % 2);
}

int **fill_with_noise(int **map)
{
    for (int y = 0; y < MAP_Y; y += 1) {
        for (int x = 0; x < MAP_X; x += 1)
            map[y][x] = two_d_noise(x, y);
    }
    for (int y = 0; y < MAP_Y; y += 1) {
        for (int x = 0; x < MAP_X; x += 1)
            last_line(x, y, map);
    }
    return map;
}
