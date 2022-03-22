/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** init_save
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"

static void entities_parameters(game_object_t *game)
{
    sfVector2f pos = {0};

    pos.y = (sfRenderWindow_getSize(game->window).y / 2) - 350;
    pos.x = -255;
    sfSprite_setScale(game->toolbar.spr_load, (sfVector2f){0.45, 0.45});
    sfSprite_setScale(game->toolbar.spr_save, (sfVector2f){0.25, 0.25});
    sfSprite_setPosition(game->toolbar.spr_load,
                (sfVector2f){pos.x - 20, pos.y + 450});
    sfSprite_setPosition(game->toolbar.spr_save,
                (sfVector2f){pos.x + 120, pos.y + 460});
    sfText_setPosition(game->toolbar.input,
            (sfVector2f){pos.x + 10, pos.y + 500});
}

int init_save(game_object_t *game)
{
    game->toolbar.tex_save = sfTexture_createFromFile(FILE_SAVE, NULL);
    game->toolbar.spr_save = sfSprite_create();
    game->toolbar.spr_load = sfSprite_create();
    game->toolbar.input = sfText_create();
    game->toolbar.file_name = "";
    if (!game->toolbar.tex_save || !game->toolbar.spr_save ||
        !game->toolbar.spr_load || !game->toolbar.input)
        return FAILURE;
    sfText_setFont(game->toolbar.input, game->menu.font);
    sfText_setColor(game->toolbar.input, sfBlack);
    sfSprite_setTexture(game->toolbar.spr_load, game->menu.text_file, sfTrue);
    sfSprite_setTexture(game->toolbar.spr_save, game->toolbar.tex_save, sfTrue);
    entities_parameters(game);
    return SUCCESS;
}
