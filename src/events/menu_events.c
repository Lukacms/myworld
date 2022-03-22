/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** menu_events
*/

#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"

static void reset_buttons(game_object_t *game)
{
    if (game->menu.load == SEED) {
        sfSprite_setScale(game->menu.seed, (sfVector2f){1.2, 1.2});
        sfSprite_setScale(game->menu.file, (sfVector2f){1, 1});
    } else {
        sfSprite_setScale(game->menu.file, (sfVector2f){1.2, 1.2});
        sfSprite_setScale(game->menu.seed, (sfVector2f){1, 1});
    }
    sfSprite_setScale(game->menu.start, (sfVector2f){0.5, 0.5});
}

static int is_clicked(game_object_t *game, sfEvent event)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(game->menu.start);

    rect.left *= game->scaling.x;
    rect.width *= game->scaling.x;
    rect.top *= game->scaling.y;
    rect.height *= game->scaling.y;
    if (event.type == sfEvtMouseButtonPressed)
        if (sfFloatRect_contains(&rect, event.mouseButton.x,
                                event.mouseButton.y) == sfTrue)
            return 1;
    return 0;
}

static void which_type(game_object_t *game, sfMouseButtonEvent button)
{
    if (is_in_box(game->menu.seed, button.x, button.y, game->scaling))
        game->menu.load = SEED;
    else if (is_in_box(game->menu.file, button.x, button.y, game->scaling))
        game->menu.load = FILEPATH;
}

int analyse_menu_events(game_object_t *game, sfEvent event)
{
    reset_buttons(game);
    if (event.key.code == sfKeyEnter || is_clicked(game, event) == 1)
        validity(game);
    else if (event.type == sfEvtTextEntered)
        get_user_seed(game, event);
    if (event.type == sfEvtMouseButtonPressed)
        which_type(game, event.mouseButton);
    return SUCCESS;
}
