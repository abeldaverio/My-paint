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
		src/drawers/draw_elements.c	\
		src/drawers/draw_buttons.c	\
		src/drawers/draw_cursor.c	\
		src/actions/pencil.c	\
		src/actions/eraser.c	\
		src/actions/brush.c	\
		src/actions/pipette.c	\
		src/event_handlers/handle_event.c	\
		src/event_handlers/button_events.c	\
		src/calculations/sprite_size.c	\
		src/free/free_elements.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_paint

LIB	=	./lib/libmini.a

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

re:	fclean	all

.PHONY: all clean fclean debug re
