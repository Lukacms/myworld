/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** is_save
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"
#include "my.h"

void is_save(game_object_t *game, sfMouseButtonEvent button)
{
    if (is_in_box(game->toolbar.spr_save, button.x, button.y, game->scaling)
        == true) {
        if (print_map_in_file(game->maps.og_map, MAP_Y, MAP_X,
                                game->toolbar.file_name) != SUCCESS)
            sfText_setColor(game->toolbar.input, sfRed);
        if (game->toolbar.file_name[0] != '\0')
            free(game->toolbar.file_name);
        game->toolbar.file_name = "";
        sfText_setString(game->toolbar.input, game->toolbar.file_name);
    }
}
