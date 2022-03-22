/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** destroy_menu
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld.h"
#include "myworld/game.h"

void destroy_menu(game_object_t *game)
{
    sfText_destroy(game->menu.input);
    sfFont_destroy(game->menu.font);
    if (game->menu.user_input[0] != '\0')
        free(game->menu.user_input);
    sfSprite_destroy(game->menu.seed);
    sfSprite_destroy(game->menu.file);
    sfSprite_destroy(game->menu.background);
    sfSprite_destroy(game->menu.start);
    sfSprite_destroy(game->menu.logo);
    sfTexture_destroy(game->menu.t_background);
    sfTexture_destroy(game->menu.t_logo);
    sfTexture_destroy(game->menu.t_start);
    sfTexture_destroy(game->menu.text_file);
    sfTexture_destroy(game->menu.text_seed);
}
