/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** init_toolbar
*/

#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"

static int init_help(game_object_t *game)
{
    game->toolbar.s_help = sfSprite_create();
    game->toolbar.help = sfText_create();
    if (!game->toolbar.s_help || !game->toolbar.help)
        return FAILURE;
    sfSprite_setTexture(game->toolbar.s_help, game->toolbar.t_help, sfTrue);
    sfSprite_setPosition(game->toolbar.s_help, (sfVector2f){10, 25});
    sfText_setFont(game->toolbar.help, game->menu.font);
    sfText_setColor(game->toolbar.help, sfBlack);
    sfText_setCharacterSize(game->toolbar.help, 20);
    sfText_setPosition(game->toolbar.help, (sfVector2f){25, 40});
    return SUCCESS;
}

static int init_tool_textures(game_object_t *game)
{
    game->toolbar.t_toolbar = sfTexture_createFromFile(TOOLBAR, NULL);
    if (!game->toolbar.t_toolbar)
        return FAILURE;
    game->toolbar.t_reinit = sfTexture_createFromFile(BIN, NULL);
    if (!game->toolbar.t_reinit)
        return FAILURE;
    game->toolbar.t_slab = sfTexture_createFromFile(SLAB_F, NULL);
    if (!game->toolbar.t_slab)
        return FAILURE;
    game->toolbar.t_corner = sfTexture_createFromFile(CORNER_F, NULL);
    if (!game->toolbar.t_corner)
        return FAILURE;
    game->toolbar.t_rand = sfTexture_createFromFile(RAND, NULL);
    if (!game->toolbar.t_rand)
        return FAILURE;
    game->toolbar.t_help = sfTexture_createFromFile(HELP, NULL);
    if (!game->toolbar.t_help)
        return FAILURE;
    return SUCCESS;
}

static int init_entities(game_object_t *game)
{
    game->toolbar.toolbar = sfSprite_create();
    game->toolbar.corner = sfSprite_create();
    game->toolbar.slab = sfSprite_create();
    game->toolbar.reinit = sfSprite_create();
    game->toolbar.rand = sfSprite_create();
    if (!game->toolbar.toolbar || !game->toolbar.reinit ||
        !game->toolbar.corner || !game->toolbar.slab || !game->toolbar.rand)
        return FAILURE;
    sfSprite_setTexture(game->toolbar.toolbar, game->toolbar.t_toolbar, sfTrue);
    sfSprite_setTexture(game->toolbar.reinit, game->toolbar.t_reinit, sfTrue);
    sfSprite_setTexture(game->toolbar.corner, game->toolbar.t_corner, sfTrue);
    sfSprite_setTexture(game->toolbar.slab, game->toolbar.t_slab, sfTrue);
    sfSprite_setTexture(game->toolbar.rand, game->toolbar.t_rand, sfTrue);
    game->toolbar.x_offset = 0;
    return SUCCESS;
}

static void put_entities_in_pos(game_object_t *game)
{
    sfVector2f pos = {0};

    pos.y = (sfRenderWindow_getSize(game->window).y / 2) - 350;
    pos.x = -255;
    sfSprite_setPosition(game->toolbar.toolbar, pos);
    sfSprite_setScale(game->toolbar.reinit, (sfVector2f){0.05, 0.05});
    sfSprite_setPosition(game->toolbar.reinit,
                (sfVector2f){pos.x + 60, pos.y + 230});
    sfSprite_setScale(game->toolbar.corner, (sfVector2f){0.6, 0.6});
    sfSprite_setPosition(game->toolbar.corner,
                (sfVector2f){pos.x + 20, pos.y + 160});
    sfSprite_setScale(game->toolbar.slab, (sfVector2f){0.6, 0.6});
    sfSprite_setPosition(game->toolbar.slab,
                (sfVector2f){pos.x + 140, pos.y + 160});
    sfSprite_setScale(game->toolbar.rand, (sfVector2f){0.6, 0.6});
    sfSprite_setPosition(game->toolbar.rand,
                (sfVector2f){pos.x + 80, pos.y + 350});
    return;
}

int init_toolbar(game_object_t *game)
{
    if (init_tool_textures(game) != SUCCESS)
        return FAILURE;
    if (init_entities(game) != SUCCESS)
        return FAILURE;
    put_entities_in_pos(game);
    if (init_help(game) != SUCCESS)
        return FAILURE;
    if (init_save(game) != SUCCESS)
        return FAILURE;
    game->toolbar.is_help = false;
    return SUCCESS;
}
