/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** slab_detection
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"

static void update_map(game_object_t *game)
{
    free_2d_map(game);
    game->maps.map_2d = create_2d_map(game->maps.og_map, game);
    display_game(game);
    sfRenderWindow_display(game->window);
}

static void update_slab(game_object_t *game, sfVector2i in_map, int modify,
                        sfVector2i pos)
{
    int stabilize = 0;

    game->maps.og_map[in_map.y][in_map.x] += modify;
    stabilize = game->maps.og_map[in_map.y][in_map.x];
    game->maps.og_map[in_map.y + pos.y][in_map.x + pos.x] = stabilize;
    game->maps.og_map[in_map.y + pos.y][in_map.x] = stabilize;
    game->maps.og_map[in_map.y][in_map.x + pos.x] = stabilize;
}

static sfVector2i which_slab(sfVector2f **map, sfVector2i mouse, sfVector2i pos)
{
    sfVector2i slab = {0};

    if (mouse.x <= map[pos.y][pos.x].x && pos.x > 0)
        slab.x = -1;
    else if (mouse.x > map[pos.y][pos.x].x && pos.x < MAP_X - 1)
        slab.x = 1;
    if (mouse.y <= map[pos.y][pos.x].y && pos.y > 0)
        slab.y = -1;
    else if (mouse.y > map[pos.y][pos.x].y && pos.y < MAP_Y - 1)
        slab.y = 1;
    return slab;
}

int slab_detection(game_object_t *game, sfEvent event)
{
    sfVector2i pos = sfMouse_getPosition(NULL);
    sfVector2i in_map = is_in_map(game->maps.map_2d, pos);
    sfVector2i slab = {0};

    if (in_map.x < 0)
        return FAILURE;
    slab = which_slab(game->maps.map_2d, pos, in_map);
    while (sfMouse_isButtonPressed(event.mouseButton.button)) {
        pos = sfMouse_getPosition(NULL);
        sfRenderWindow_clear(game->window, sfBlack);
        if (game->maps.map_2d[in_map.y][in_map.x].y <= pos.y)
            update_slab(game, in_map, -5, slab);
        if (game->maps.map_2d[in_map.y][in_map.x].y > pos.y)
            update_slab(game, in_map, 5, slab);
        update_map(game);
    }
    return SUCCESS;
}
