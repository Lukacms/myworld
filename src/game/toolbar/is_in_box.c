/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** is_in_box
*/

#include <stdbool.h>
#include <string.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"

bool is_in_box(sfSprite *sprite, int x, int y, sfVector2f scaling)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);

    rect.left *= scaling.x;
    rect.width *= scaling.x;
    rect.top *= scaling.y;
    rect.height *= scaling.y;
    if (sfFloatRect_contains(&rect, x, y) == sfTrue)
        return true;
    return false;
}
