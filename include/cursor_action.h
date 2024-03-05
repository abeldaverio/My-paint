/*
** EPITECH PROJECT, 2024
** cursor action
** File description:
** CURSOR_ACTION_H
*/

#ifndef CURSOR_ACTION_H
    #define CURSOR_ACTION_H

    #include <SFML/Graphics.h>
    #include "enums/textures.h"
    #include "cursor.h"
    #include "board.h"

typedef struct cursor_action_s {
    textures_t mode;
    void (*action)(cursor_t *, board_t *, sfVector2i *);
}cursor_action_t;

//cursor action functions
void do_nothing(cursor_t *, board_t *, sfVector2i *);
void draw_pencil(cursor_t *, board_t *, sfVector2i *);
void erase(cursor_t *, board_t *, sfVector2i *);
//void get_color(cursor_t *, board_t *, sfVector2i *);

static const cursor_action_t CURSOR_ACT[] = {
    {BASIC, do_nothing},
    {PENCIL, draw_pencil},
    {ERASER, erase},
    {BRUSH, draw_pencil},
    {PIPETTE, draw_pencil},
};

static const size_t NB_OF_ACT = sizeof(CURSOR_ACT) / sizeof(cursor_action_t);

#endif /* !CURSOR_ACTION_H */
