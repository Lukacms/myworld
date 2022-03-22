/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** draw_map_in_window
*/

#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics.h>
#include "myworld.h"

static sfVertexArray *create_lines(sfVector2f *point1, sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfBlack};
    sfVertex vertex2 = {.position = *point2, .color = sfBlack};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLines);
    return vertex_array;
}

static sfVertexArray *create_quad(sfVector2f *point1 , sfVector2f *point2,
                                    sfVector2f *point3, sfVector2f *point4)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfWhite};
    sfVertex vertex2 = {.position = *point2, .color = sfWhite};
    sfVertex vertex3 = {.position = *point3, .color = sfWhite};
    sfVertex vertex4 = {.position = *point4, .color = sfWhite};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return vertex_array;
}

static void vertex_drawing(int i, int j, game_object_t *game)
{
    sfVertexArray *vertex = NULL;
    sfVector2f **m = game->maps.map_2d;
    sfRenderStates states = {0};

    if (j < MAP_X - 1 && i < MAP_Y - 1) {
        states = create_renderstates(game, i, j);
        vertex = create_quad(&m[i][j], &m[i][j + 1], &m[i + 1][j + 1],
                            &m[i + 1][j]);
        sfRenderWindow_drawVertexArray(game->window, vertex, &states);
        sfVertexArray_destroy(vertex);
        vertex = create_lines(&m[i][j], &m[i][j + 1]);
        sfRenderWindow_drawVertexArray(game->window, vertex, NULL);
        sfVertexArray_destroy(vertex);
        vertex = create_lines(&m[i][j], &m[i + 1][j]);
        sfRenderWindow_drawVertexArray(game->window, vertex, NULL);
        sfVertexArray_destroy(vertex);
    }
}

int draw_map(game_object_t *game)
{
    for (int i = 0; i < MAP_Y; i++) {
        for (int j = 0; j < MAP_X; j++)
            vertex_drawing(i, j, game);
    }
    return 0;
}
