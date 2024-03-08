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
    void (*action)(cursor_t *, board_t *, sfVector2i *, sfEvent *);
}cursor_action_t;

//cursor action functions
void do_nothing(cursor_t *, board_t *, sfVector2i *, sfEvent *);
void draw_pencil(cursor_t *, board_t *, sfVector2i *, sfEvent *);
void erase(cursor_t *, board_t *, sfVector2i *, sfEvent *);
void copy_color(cursor_t *, board_t *, sfVector2i *, sfEvent *);
void fill_bucket(cursor_t *, board_t *, sfVector2i *, sfEvent *);

static const cursor_action_t CURSOR_ACT[] = {
    {BASIC, do_nothing},
    {PENCIL, draw_pencil},
    {ERASER, erase},
    {BRUSH, draw_pencil},
    {PIPETTE, copy_color},
    {BUCKET, fill_bucket},
};

static const size_t NB_OF_ACT = sizeof(CURSOR_ACT) / sizeof(cursor_action_t);

#endif /* !CURSOR_ACTION_H */
