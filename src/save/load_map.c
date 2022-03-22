/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** load_map
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "myworld/game.h"
#include "myworld.h"
#include "my.h"

static int get_offset(char *file)
{
    int i = 0;

    for (; file[i] >= '0' && file[i] <= '9' && file[i] != '\0'; i++);
    for (; (file[i] < '0' || file[i] > '9') && file[i] != '\0'; i++);
    return i;
}

static int infos_in_map(game_object_t *game, char *file)
{
    int status = 0;

    for (int i = 0; i < MAP_Y; i++) {
        for (int j = 0; j < MAP_X; j++) {
            game->maps.og_map[i][j] = my_getnbr(file + status);
            status += get_offset(file + status);
        }
    }
    return SUCCESS;
}

int load_map(game_object_t *game, char const *filepath)
{
    char *file = load_file_in_mem(filepath);

    if (!file || check_map(file) != SUCCESS)
        return FAILURE;
    game->maps.og_map = mem_alloc_int(MAP_Y, MAP_X);
    if (infos_in_map(game, file) != SUCCESS)
        return FAILURE;
    free(file);
    return SUCCESS;
}
