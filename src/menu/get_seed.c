/*
** EPITECH PROJECT, 2022
** MyWorld [WSL: Manjaro]
** File description:
** get_seed
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"
#include "my.h"

int get_user_seed(game_object_t *game, sfEvent evt)
{
    char tmp[] = {evt.text.unicode};

    if (!game)
        return FAILURE;
    game->menu.user_input = my_strcat(game->menu.user_input, tmp);
    sfText_setString(game->menu.input, game->menu.user_input);
    return SUCCESS;
}
