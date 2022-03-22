/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** create_renderstats
*/

#include <SFML/Graphics.h>
#include "myworld/game.h"

static int check_heigth_of_point(int **map, int y, int x)
{
    if (map[y][x] > 25 && map[y + 1][x] > 25
        && map[y][x + 1] > 25 && map[y + 1][x + 1] > 25)
        return 2;
    else if (map[y][x] > 10 && map[y + 1][x] > 10
        && map[y][x + 1] > 10 && map[y + 1][x + 1] > 10)
        return 1;
    return 0;
}

sfRenderStates create_renderstates(game_object_t *game, int y, int x)
{
    sfRenderStates states = {0};
    int which_texture = check_heigth_of_point(game->maps.og_map, y, x);

    states.shader = NULL;
    if (which_texture == 2)
        states.texture = game->textures.head->next->texture;
    else if (which_texture == 1)
        states.texture = game->textures.head->prev->texture;
    else
        states.texture = game->textures.head->texture;
    states.blendMode = sfBlendNone;
    states.transform = sfTransform_Identity;
    return states;
}
