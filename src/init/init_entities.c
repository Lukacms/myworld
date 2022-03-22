/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** init_music
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "myworld.h"
#include "myworld/game.h"

int init_game_entities(game_object_t *game)
{
    game->music = sfMusic_createFromFile(MUSIC);
    if (!game->music)
        return FAILURE;
    sfMusic_setLoop(game->music, sfTrue);
    game->game_clock = sfClock_create();
    if (!game->game_clock)
        return FAILURE;
    return SUCCESS;
}
