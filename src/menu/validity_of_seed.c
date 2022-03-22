/*
** EPITECH PROJECT, 2022
** MyWorld [WSL: Manjaro]
** File description:
** validity_of_seed
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"
#include "my.h"

static void create_map(game_object_t *game)
{
    game->maps.og_map = mem_alloc_int(MAP_Y, MAP_X);
    game->maps.og_map = fill_with_noise(game->maps.og_map);
    game->maps.map_2d = create_2d_map(game->maps.og_map, game);
}

static void changing_status(game_object_t *game)
{
    int nbr = my_getnbr(game->menu.user_input);

    srand(nbr);
    create_map(game);
    game->status = GAME;
}

static int check_validity(game_object_t *game, int i)
{
    if (game->menu.user_input[i] < '0' || game->menu.user_input[i] > '9') {
        if (game->menu.user_input)
            free(game->menu.user_input);
        game->menu.user_input = malloc(sizeof(char) * 1);
        game->menu.user_input[0] = '\0';
        sfText_setColor(game->menu.input, sfRed);
        return FAILURE;
    }
    return SUCCESS;
}

int validity_of_seed(game_object_t *game)
{
    for (int i = 0; game->menu.user_input[i] != '\0'; i += 1) {
        if (check_validity(game, i) != SUCCESS)
            return FAILURE;
    }
    changing_status(game);
    return SUCCESS;
}
