/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** validity_of_file
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"
#include "my.h"

int validity_of_file(game_object_t *game)
{
    if (load_map(game, game->menu.user_input) != SUCCESS) {
        if (game->menu.user_input[0] != '\0')
            free(game->menu.user_input);
        game->menu.user_input = malloc(sizeof(char) * 1);
        game->menu.user_input[0] = '\0';
        sfText_setColor(game->menu.input, sfRed);
        return FAILURE;
    }
    game->maps.map_2d = create_2d_map(game->maps.og_map, game);
    game->status = GAME;
    return SUCCESS;
}
