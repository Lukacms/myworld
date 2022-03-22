##
## EPITECH PROJECT, 2022
## myworld
## File description:
## Makefile
##

SRC	=	src/main.c	\
	src/launch.c	\
	src/h_option/display_info.c	\
	src/game/display/create_renderstats.c	\
	src/game/display/display_game.c	\
	src/game/display/draw_map_in_window.c	\
	src/game/map_transformation/detection/corner_detection.c	\
	src/game/map_transformation/detection/slab_detection.c	\
	src/game/map_transformation/detection/is_in_map.c	\
	src/game/map_transformation/moving.c	\
	src/game/map_transformation/rotation.c	\
	src/game/map_transformation/zoom.c	\
	src/game/toolbar/init_toolbar.c	\
	src/game/toolbar/init_save.c	\
	src/game/toolbar/is_in_box.c	\
	src/game/toolbar/draw_toolbar.c	\
	src/game/toolbar/is_bin.c	\
	src/game/toolbar/is_randomizer.c	\
	src/game/toolbar/is_load.c	\
	src/game/toolbar/is_save.c	\
	src/game/toolbar/slab_or_corner.c	\
	src/game/toolbar/help/display_help.c	\
	src/game/toolbar/manage_text_entered.c	\
	src/init/create_2d_map.c	\
	src/init/project_iso_point.c	\
	src/init/init_game.c	\
	src/init/window_init.c	\
	src/init/textures/free_list.c	\
	src/init/textures/add_node.c	\
	src/init/textures/create_list.c	\
	src/init/mem_alloc_int.c	\
	src/init/init_entities.c	\
	src/menu/perlin_noise/fill_with_noise.c	\
	src/menu/perlin_noise/random_seed.c	\
	src/menu/perlin_noise/two_d_noise.c	\
	src/menu/init_menu.c	\
	src/menu/draw_menu.c	\
	src/menu/get_seed.c	\
	src/menu/validity.c	\
	src/menu/validity_of_seed.c	\
	src/menu/validity_of_file.c	\
	src/destroy/destroy_menu.c	\
	src/destroy/destroy_resources.c	\
	src/destroy/destroy_toolbar.c	\
	src/destroy/free_2d_map.c	\
	src/events/analyse_events.c	\
	src/events/game_events.c	\
	src/events/menu_events.c	\
	src/events/toolbar_events.c	\
	src/menu/animated_button.c	\
	src/save/print_map_in_file.c	\
	src/save/check_map.c	\
	src/save/load_map.c	\
	src/events/handle_resize.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_world

LIBMY	=	lib/libmy.a

CFLAGS	=	-W -Wall -Wextra -Wshadow -Wpedantic

CPPFLAGS	=	-I./include

CC	=	gcc

LDFLAGS	=	-L./lib

LDLIBS	=	-lmy -lm
LDLIBS	+=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:	$(NAME)

$(LIBMY):
	make re -C lib/my

$(NAME):	$(OBJ) $(LIBMY)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

debug:	fclean
debug:	CFLAGS += -g
debug:	$(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -C lib/my

fclean:	clean
	rm -f $(NAME)

re:	fclean	all	clean

.PHONY: clean fclean re all
