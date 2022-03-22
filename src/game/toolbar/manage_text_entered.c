/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** manage_text_entered
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"
#include "my.h"

int manage_text_entered(game_object_t *game, sfEvent evt)
{
    char tmp[] = {evt.text.unicode};

    if (!game)
        return FAILURE;
    game->toolbar.file_name = my_strcat(game->toolbar.file_name, tmp);
    sfText_setString(game->toolbar.input, game->toolbar.file_name);
    sfText_setColor(game->toolbar.input, sfBlack);
    return SUCCESS;
}
