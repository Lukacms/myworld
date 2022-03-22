/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** validity
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"
#include "my.h"

int validity(game_object_t *game)
{
    if (game->menu.load == SEED)
        return validity_of_seed(game);
    return validity_of_file(game);
}
