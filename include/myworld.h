/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** myworld
*/

#ifndef MYWORLD_H_
    #define MYWORLD_H_

    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include "myworld/game.h"
    #include "myworld/perlinnoise.h"

/*
* @brief launch the programm
* @param None
* @return 0 or 84 (in case of errors)
*/
int launch(void);

/*
* @brief show the usage
* @param None
* @return 0 or 84 (in case of errors)
*/
int display_info(void);

/**
* @brief Create a 2d map object
*
* @param map
* @param game
* @return sfVector2f**
*/
sfVector2f **create_2d_map(int * const map[], game_object_t *game);

/**
* @brief calculate each point of the map from 3d to 2d (isometric)
*
* @param x
* @param y
* @param z
* @param game
* @return sfVector2f
*/
sfVector2f project_iso_point(int x, int y, int z, game_object_t *game);

/**
* @brief
*
* @param map
* @return int**
*/
int **fill_with_noise(int **map);

/**
* @brief
*
* @param game
* @return int
*/
int window_init(game_object_t *game);

/**
* @brief initialize game resources for when the window will be open
* - can return FAILURE in case a resource wasn't initialized correctly
*
* @param game
* @return int
*/
int init_game(game_object_t *game);
int init_textures(game_object_t *game);
int add_node(game_object_t *game, char const *filepath, texture_id_t id);
int init_game_entities(game_object_t *game);
int init_menu(game_object_t *game);
int init_toolbar(game_object_t *game);
int init_save(game_object_t *game);

/**
* @brief destroy resources of the game
*
* @param game
* @return None
*/
void destroy_resources(game_object_t *game);
void free_list(game_object_t *game);
void free_2d_map(game_object_t *game);
void destroy_menu(game_object_t *game);
void destroy_toolbar(game_object_t *game);

/**
* @brief analyse events while the window is open
*
* @param game
* @param event
* @return int
*/
int analyse_events(game_object_t *game, sfEvent event);
int analyse_game_events(game_object_t *game, sfEvent event);
int analyse_menu_events(game_object_t *game, sfEvent event);
int analyse_toolbar_events(game_object_t *game, sfEvent event);
int manage_text_entered(game_object_t *game, sfEvent evt);

/**
* @brief handle window resize
*
* @param game
*/
void handle_resize(game_object_t *game);

/**
* @brief Get the user seed object - from analyse_menu_events
*
* @param game
* @param evt
* @return int
*/
int get_user_seed(game_object_t *game, sfEvent evt);
int validity_of_seed(game_object_t *game);
int validity_of_file(game_object_t *game);
int validity(game_object_t *game);

/**
* @brief analyse the events of the game (concerning the map) -
* from analyse_game_events
*
* @param game
* @param event
*/
void rotate_management(game_object_t *game, sfEvent event);
void zoom_management(game_object_t *game, sfEvent event);
void moving_management(game_object_t *game, sfEvent event);
int corner_detection(game_object_t *game, sfEvent event);
int slab_detection(game_object_t *game, sfEvent event);
sfVector2i is_in_map(sfVector2f **map, sfVector2i pos_map);
bool is_in_box(sfSprite *sprite, int x, int y, sfVector2f scaling);
void is_save(game_object_t *game, sfMouseButtonEvent button);
void is_load(game_object_t *game, sfMouseButtonEvent button);

/**
* @brief allocate memory for a int**
*
* @param nb_rows
* @param nb_cols
* @return int**
*/
int **mem_alloc_int(int nb_rows, int nb_cols);

/**
* @brief display the entities for the menu
*
* @param game
* @return int
*/
int draw_menu(game_object_t *game);

/**
* @brief display the entities for the game
* + toolbar if needed
*
* @param game
* @return int
*/
int display_game(game_object_t *game);
int draw_toolbar(game_object_t *game);

/**
* @brief draw the map with VertexArray
*
* @param game
* @return int
*/
int draw_map(game_object_t *game);
sfRenderStates create_renderstates(game_object_t *game, int i, int j);
void is_bin(game_object_t *game, sfMouseButtonEvent button);
void is_randomizer(game_object_t *game, sfMouseButtonEvent button);
void slab_or_corner(game_object_t *game, sfMouseButtonEvent button);
void animated_button(game_object_t *game);
void display_help(game_object_t *game, sfMouseMoveEvent mouse);

/**
* @brief save the og_map by printing it in a ".legend" file
*
* @param map int**
* @param nb_rows int
* @param nb_cols int
* @return int - FAILURE or SUCCESS
*/
int print_map_in_file(int **map, int nb_rows, int nb_cols, char *file);

/**
* @brief chedk if the map given in parameter is valid
*
* @param map
* @return int
*/
int check_map(char *map);
int load_map(game_object_t *game, char const *filepath);

#endif /* !MYWORLD_H_ */
