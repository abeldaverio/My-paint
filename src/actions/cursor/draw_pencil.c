/*
** EPITECH PROJECT, 2024
** draw pencil
** File description:
** action when pencil is selected
*/

#include <SFML/Graphics.h>
#include "colors.h"
#include "settings.h"
#include "cursor.h"
#include "board.h"

static void draw_pixel(cursor_t *cursor, board_t *board,
    sfVector2i *mouse, sfVector2i *coordinates)
{
    if ((int)(mouse->x +
        (coordinates->x - (cursor->thickness / 2))) < 0 ||
        mouse->x +
        (coordinates->x - (cursor->thickness / 2)) >= LENGTH ||
        mouse->y +
        (coordinates->y - (cursor->thickness / 2)) < BOARD_ESPACEMENT ||
        mouse->y +
        (coordinates->y - (cursor->thickness / 2)) >= HIGHT) {
        return;
    }
    sfImage_setPixel(board->image,
        mouse->x + (coordinates->x - (cursor->thickness / 2)),
        mouse->y - BOARD_ESPACEMENT +
        (coordinates->y - (cursor->thickness / 2)),
        COLORS[cursor->color]);
}

static void draw_normal(cursor_t *cursor, board_t *board, sfVector2i *mouse)
{
    sfVector2i coordinates = {0, 0};

    while (coordinates.y < (int)cursor->thickness) {
        coordinates.x = 0;
        while (coordinates.x < (int)cursor->thickness) {
            draw_pixel(cursor, board, mouse, &coordinates);
            coordinates.x += 1;
        }
        coordinates.y += 1;
    }
}

static void draw_fluid(cursor_t *cursor, board_t *board,
    sfVector2i *mouse, sfVector2i *last_pixel)
{
    int i = 0;
    int j = 0;

    while (last_pixel->x + i != mouse->x ||
        last_pixel->y + j != mouse->y) {
        draw_normal(cursor, board,
            &(sfVector2i){last_pixel->x + i, last_pixel->y + j});
        if (last_pixel->x + i != mouse->x)
            i += (mouse->x > last_pixel->x) ? 1 : -1;
        if (last_pixel->y + j != mouse->y)
            j += (mouse->y > last_pixel->y) ? 1 : -1;
    }
}

void draw_pencil(cursor_t *cursor, board_t *board,
    sfVector2i *mouse, sfEvent *event)
{
    static sfVector2i last_pixel = {0, 0};

    if (event->type == sfEvtMouseButtonPressed) {
        draw_normal(cursor, board, mouse);
    } else {
        draw_fluid(cursor, board, mouse, &last_pixel);
    }
    last_pixel = *mouse;
}
