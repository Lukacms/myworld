/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** create_list
*/

#include <SFML/Graphics.h>
#include "myworld.h"
#include "myworld/game.h"

int init_textures(game_object_t *game)
{
    if (!game)
        return FAILURE;
    if (add_node(game, HERB_F, HERB) != SUCCESS)
        return FAILURE;
    if (add_node(game, SNOW_F, SNOW) != SUCCESS)
        return FAILURE;
    if (add_node(game, STONE_F, STONE) != SUCCESS)
        return FAILURE;
    return SUCCESS;
}
