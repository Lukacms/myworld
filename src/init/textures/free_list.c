/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** free_list
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"

void free_list(game_object_t *game)
{
    texture_node_t *anchor = NULL;
    texture_node_t *tmp = NULL;

    if (!game || !game->textures.head)
        return;
    anchor = game->textures.head;
    tmp = game->textures.head;
    for (unsigned int i = 0; i < game->textures.size; i += 1) {
        anchor = anchor->next;
        sfTexture_destroy(tmp->texture);
        free(tmp);
        tmp = anchor;
    }
    game->textures.head = NULL;
    game->textures.size = 0;
}
