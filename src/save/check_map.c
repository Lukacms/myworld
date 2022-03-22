/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** check_map
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"
#include "my.h"

static int is_valid(char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    else if (c == ' ' || c == '\n')
        return 0;
    return 1;
}

int check_map(char *map)
{
    for (int i = 0; map[i] != '\0'; i += 1) {
        if (is_valid(map[i]) != 0)
            return FAILURE;
    }
    return SUCCESS;
}
