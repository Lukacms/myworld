/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** add_node
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"

static int init_node(texture_node_t *node, char const *file, texture_id_t id)
{
    node->texture = sfTexture_createFromFile(file, NULL);
    if (!node->texture)
        return FAILURE;
    node->texture_id = id;
    node->prev = node;
    node->next = node;
    return SUCCESS;
}

static void put_node_in_list(game_object_t *game, texture_node_t *node)
{
    if (!game->textures.head)
        game->textures.head = node;
    else {
        node->prev = game->textures.head->prev;
        node->next = game->textures.head;
        game->textures.head->prev->next = node;
        game->textures.head->prev = node;
    }
}

int add_node(game_object_t *game, char const *filepath, texture_id_t id)
{
    texture_node_t *node = NULL;

    if (!game)
        return FAILURE;
    node = malloc(sizeof(texture_node_t));
    if (!node)
        return FAILURE;
    if (init_node(node, filepath, id) != SUCCESS)
        return FAILURE;
    put_node_in_list(game, node);
    game->textures.size += 1;
    return SUCCESS;
}
