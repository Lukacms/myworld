/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    #define MAP_X 50
    #define MAP_Y 50
    #define SUCCESS 0
    #define FAILURE 84
    #define INFO_PROGRAM "assets/text/program_infos.txt"
    #define HERB_F "assets/textures/herb.png"
    #define SNOW_F "assets/textures/snow.png"
    #define STONE_F "assets/textures/stone.png"
    #define MUSIC "assets/music/twiligth_town.ogg"
    #define FONT "assets/text/font.ttf"
    #define TOOLBAR "assets/textures/toolbar.png"
    #define BIN "assets/textures/bin.png"
    #define SLAB_F "assets/textures/slab.png"
    #define CORNER_F "assets/textures/corner.png"
    #define RAND "assets/textures/arrow.png"
    #define EARTH "assets/textures/earth.png"
    #define START "assets/textures/start.png"
    #define LOGO "assets/textures/logo.png"
    #define HELP "assets/textures/help_box.png"
    #define FILE_SEED "assets/textures/seed.png"
    #define FILE_TEX "assets/textures/file.png"
    #define FILE_SAVE "assets/textures/save.png"

/**
* @brief enum allowing the program to know which scene to display,
* which events to analyse
*
* @param MENU
* @param GAME
* @param TOOL
*
*/
typedef enum {
    MENU,
    GAME,
    TOOL
} scene_handler_t;

/**
* @brief enum to load the file from a seed or a file
*
*/
typedef enum {
    SEED,
    FILEPATH
} loading_t;

/**
* @brief enum defining which texture is which
*
* @param HERB
* @param SNOW
* @param STONE
*
*/
typedef enum {
    HERB,
    SNOW,
    STONE
} texture_id_t;

/**
* @brief enum defining if a slab or a corner can be changed of height
*
* @param SLAB
* @param CORNER
*
*/
typedef enum {
    SLAB,
    CORNER
} detection_id_t;

/**
* @brief node of the linked list for the textures
*
* @param texture sfTexture
* @param texture_id which texture is it
* @param prev previous node
* @param next next node
*
*/
typedef struct texture_node_s {
    sfTexture *texture;
    texture_id_t texture_id;
    struct texture_node_s *prev;
    struct texture_node_s *next;
} texture_node_t;

/**
* @brief structure for the menu and its elements
*
* @param user_input char* - what the user writes in the window
* (to be displayed)
* @param input sfText - text to draw the user input
* @param text sfText - display the text asking the user to write a seed
* @param font sfFont - the font used for to write the texts
*
*/
typedef struct menu_scene_s {
    char *user_input;
    sfTexture *t_background;
    sfSprite *background;
    sfTexture *t_start;
    sfSprite *start;
    sfTexture *t_logo;
    sfSprite *logo;
    sfText *input;
    sfFont *font;
    loading_t load;
    sfTexture *text_seed;
    sfTexture *text_file;
    sfSprite *seed;
    sfSprite *file;
} menu_scene_t;

/**
* @brief structure for the toolbar and its elements
*
*/
typedef struct toolbar_s {
    sfSprite *toolbar;
    sfSprite *slab;
    sfSprite *corner;
    sfSprite *reinit;
    sfSprite *rand;
    sfSprite *s_help;
    sfSprite *spr_save;
    sfSprite *spr_load;
    sfTexture *t_toolbar;
    sfTexture *t_slab;
    sfTexture *t_corner;
    sfTexture *t_reinit;
    sfTexture *t_rand;
    sfTexture *tex_save;
    sfTexture *t_help;
    sfText *help;
    sfText *input;
    char *file_name;
    int x_offset;
    bool is_help;
} toolbar_t;

/**
* @brief structure for the maps used in the game and their infos
*
* @param og_map int**
* @param og_map_size sfVector2i
* @param map_2d sfVector2f**
* @param angles sfVector2i - angle at wich the map will be displayed
* @param pos sfVector2i - position of the map on the window
* @param sampling int - the zoom level of the map
*
*/
typedef struct maps_s {
    int **og_map;
    sfVector2i og_map_size;
    sfVector2f **map_2d;
    sfVector2i angles;
    sfVector2i pos;
    int sampling;
    detection_id_t status;
} maps_t;

/**
* @brief game structure with infos about all the elements that
* will be used while the window is open
*
* @param window sfRenderWindow
* @param game_clock sfClock
* @param game status
* @param menu struct
* @param toolbar struct
* @param maps struct
* @param textures linked list
* @param music sfMusic
*
*/
typedef struct game_object_s {
    sfRenderWindow *window;
    sfVector2f scaling;
    sfClock *game_clock;
    scene_handler_t status;
    menu_scene_t menu;
    toolbar_t toolbar;
    maps_t maps;
    struct {
        texture_node_t *head;
        unsigned int size;
    } textures;
    sfMusic *music;
} game_object_t;

typedef int (*command_handler_t)(game_object_t *game);
typedef int (*event_handler_t)(game_object_t *game, sfEvent event);

/**
* @brief function pointer - goes for the appropriate function
* depending on the game status
*
* @param status
* @param scene_handler
* @param event_handler
*
*/
typedef struct game_status_s {
    scene_handler_t status;
    command_handler_t scene_handler;
    event_handler_t event_handler;
} game_status_t;

#endif /* !GAME_H_ */
