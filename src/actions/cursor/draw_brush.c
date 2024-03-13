/*
** EPITECH PROJECT, 2024
** draw brush
** File description:
** action when brush is selected
*/

#include <SFML/Graphics.h>
#include <stdbool.h>
#include <math.h>
#include "abs.h"
#include "colors.h"
#include "settings.h"
#include "cursor.h"
#include "board.h"

static bool is_in_circle(sfVector2i *mouse,
    sfVector2i *coordinates, cursor_t *cursor)
{
    sfVector2i current = {mouse->x - (cursor->thickness / 2) + coordinates->x,
        mouse->y - (cursor->thickness / 2) + coordinates->y};

    if ((sqrt(pow(mouse->x - current.x, 2) +
        pow(mouse->y - current.y, 2))) <= (cursor->thickness / 2))
        return true;
    return false;
}

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
        (coordinates->y - (cursor->thickness / 2)) >= HIGHT ||
        !is_in_circle(mouse, coordinates, cursor)) {
        return;
    }
    sfImage_setPixel(board->image->image,
        mouse->x + (coordinates->x - (cursor->thickness / 2)),
        mouse->y - BOARD_ESPACEMENT +
        (coordinates->y - (cursor->thickness / 2)),
        (cursor->color == CUSTOM) ? cursor->custom : COLORS[cursor->color]);
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
    int delta_x = ABS(mouse->x - last_pixel->x);
    int delta_y = -1 * ABS(mouse->y - last_pixel->y);
    int direction_x = last_pixel->x < mouse->x ? 1 : -1;
    int direction_y = last_pixel->y < mouse->y ? 1 : -1;
    int difference = delta_x + delta_y;
    int diff2 = 0;

    while (last_pixel->x != mouse->x || last_pixel->y != mouse->y) {
        draw_normal(cursor, board, last_pixel);
        diff2 = 2 * difference;
        if (diff2 >= delta_y) {
            difference += delta_y;
            last_pixel->x += direction_x;
        }
        if (diff2 <= delta_x) {
            difference += delta_x;
            last_pixel->y += direction_y;
        }
    }
}

void draw_brush(cursor_t *cursor, board_t *board,
    sfVector2i *mouse, sfEvent *event)
{
    static sfVector2i last_pixel = {0, 0};

    if (event->type == sfEvtMouseButtonPressed &&
        !sfKeyboard_isKeyPressed(sfKeyLShift)) {
        draw_normal(cursor, board, mouse);
    } else {
        draw_fluid(cursor, board, mouse, &last_pixel);
    }
    last_pixel = *mouse;
}
