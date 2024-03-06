/*
** EPITECH PROJECT, 2024
** draw pencil
** File description:
** action when pencil is selected
*/

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
        sfWhite);
}

void erase(cursor_t *cursor, board_t *board, sfVector2i *mouse)
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