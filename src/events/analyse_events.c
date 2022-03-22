/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** analyse_game_events
*/

#include <SFML/Graphics.h>
#include "myworld.h"

static const game_status_t event_handler[] = {
    {.status = MENU, .event_handler = &analyse_menu_events},
    {.status = GAME, .event_handler = &analyse_game_events},
    {.status = TOOL, .event_handler = &analyse_toolbar_events},
    {0}
};

int analyse_events(game_object_t *game, sfEvent event)
{
    if (event.type == sfEvtResized)
        handle_resize(game);
    for (int i = 0; event_handler[i].event_handler; i += 1) {
        if (game->status == event_handler[i].status)
            return event_handler[i].event_handler(game, event);
    }
    return 0;
}
