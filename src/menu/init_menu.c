/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** init_menu
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include "myworld/game.h"

static int init_logo(game_object_t *game)
{
    game->menu.t_logo = sfTexture_createFromFile(LOGO, NULL);
    game->menu.logo = sfSprite_create();
    if (!game->menu.t_logo || !game->menu.logo)
        return FAILURE;
    sfSprite_setTexture(game->menu.logo, game->menu.t_logo, sfTrue);
    sfSprite_setScale(game->menu.logo, (sfVector2f){0.5, 0.5});
    game->menu.text_file = sfTexture_createFromFile(FILE_TEX, NULL);
    game->menu.text_seed = sfTexture_createFromFile(FILE_SEED, NULL);
    game->menu.file = sfSprite_create();
    game->menu.seed = sfSprite_create();
    if (!game->menu.text_file || !game->menu.text_seed || !game->menu.file ||
        !game->menu.seed)
        return FAILURE;
    sfSprite_setTexture(game->menu.file, game->menu.text_file, sfTrue);
    sfSprite_setTexture(game->menu.seed, game->menu.text_seed, sfTrue);
    return SUCCESS;
}

static int init_menu_texture(game_object_t *game)
{
    game->menu.t_background = sfTexture_createFromFile(EARTH, NULL);
    if (!game->menu.t_background)
        return FAILURE;
    game->menu.background = sfSprite_create();
    sfSprite_setTexture(game->menu.background, game->menu.t_background, sfTrue);
    if (!game->menu.t_background)
        return FAILURE;
    game->menu.t_start = sfTexture_createFromFile(START, NULL);
    if (!game->menu.t_start)
        return FAILURE;
    game->menu.start = sfSprite_create();
    sfSprite_setTexture(game->menu.start, game->menu.t_start, sfTrue);
    if (!game->menu.t_start)
        return FAILURE;
    sfSprite_setScale(game->menu.start, (sfVector2f){0.5, 0.5});
    return init_logo(game);
}

static void set_position_menu(game_object_t *game)
{
    sfVector2u w_size = sfRenderWindow_getSize(game->window);

    sfSprite_setPosition(game->menu.start,
                        (sfVector2f){w_size.x * 0.70, w_size.y * 0.70});
    sfText_setPosition(game->menu.input,
                        (sfVector2f){w_size.x * 0.03, w_size.y * 0.54});
    sfSprite_setPosition(game->menu.logo,
                        (sfVector2f){w_size.x * 0.37, w_size.y * 0.05});
    sfSprite_setPosition(game->menu.file,
                            (sfVector2f){w_size.x * 0.025, w_size.y * 0.4});
    sfSprite_setPosition(game->menu.seed,
                (sfVector2f){w_size.x * 0.2, w_size.y * 0.4});
    return;
}

int init_menu(game_object_t *game)
{
    game->menu.load = SEED;
    game->menu.font = sfFont_createFromFile(FONT);
    if (!game->menu.font)
        return FAILURE;
    game->menu.input = sfText_create();
    game->menu.user_input = "";
    if (!game->menu.input)
        return FAILURE;
    sfText_setFont(game->menu.input, game->menu.font);
    if (init_menu_texture(game) == FAILURE)
        return FAILURE;
    set_position_menu(game);
    return SUCCESS;
}
