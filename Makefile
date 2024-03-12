##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile for my paint
##

SRC	=	src/main_program/main.c	\
		src/main_program/my_paint.c	\
		src/checkers/check_env.c	\
		src/init/init_window.c	\
		src/init/init_buttons.c	\
		src/init/init_texture.c	\
		src/init/init_cursor.c	\
		src/init/init_board.c	\
		src/drawers/draw_elements.c	\
		src/drawers/draw_buttons.c	\
		src/drawers/draw_cursor.c	\
		src/drawers/draw_board.c	\
		src/actions/pencil.c	\
		src/actions/eraser.c	\
		src/actions/brush.c	\
		src/actions/pipette.c	\
		src/actions/bucket.c	\
		src/actions/clear.c	\
		src/actions/open_menu.c	\
		src/actions/file/save.c	\
		src/actions/flip_horizontal.c	\
		src/actions/flip_vertical.c	\
		src/actions/colors/red.c	\
		src/actions/colors/black.c	\
		src/actions/colors/blue.c	\
		src/actions/colors/green.c	\
		src/actions/colors/orange.c	\
		src/actions/colors/cyan.c	\
		src/actions/colors/purple.c	\
		src/actions/colors/yellow.c	\
		src/actions/colors/brown.c	\
		src/actions/colors/pink.c	\
		src/actions/colors/beige.c	\
		src/actions/colors/white.c	\
		src/actions/colors/grey.c	\
		src/actions/colors/fushia.c	\
		src/actions/cursor/do_nothing.c	\
		src/actions/cursor/copy_color.c	\
		src/actions/cursor/draw_pencil.c	\
		src/actions/cursor/erase.c	\
		src/actions/cursor/fill_bucket.c	\
		src/update/update_buttons.c	\
		src/update/update_board.c	\
		src/event_handlers/handle_event.c	\
		src/event_handlers/button_events.c	\
		src/event_handlers/resize_window.c	\
		src/calculations/sprite_size.c	\
		src/calculations/check_cursor_position.c	\
		src/calculations/is_same_color.c	\
		src/free/free_elements.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_paint

LIB	=	./lib/libmy.a

CPPFLAGS	=	-iquote./include/

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-window

LDFLAGS	=	-L./lib/

LDLIBS	=	 $(CSFML) -lmy -lm

CFLAGS	=	-Wall -Wextra

all:	$(NAME)

$(LIB):
	make -C ./lib/my/

$(NAME):	$(LIB) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ)
	make clean -C ./lib/my

fclean:	clean
	$(RM) $(NAME)
	make fclean -C ./lib/my

debug: CFLAGS += -ggdb3
debug: re

asan:	CC	=	clang -fsanitize=address
asan:	re

re:	fclean	all

.PHONY: all clean fclean debug re
