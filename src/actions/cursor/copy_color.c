/*
** EPITECH PROJECT, 2024
** do nothing
** File description:
** do nothing
*/

#include "cursor.h"
#include "settings.h"
#include "board.h"
#include "colors.h"
#include "functions.h"

void copy_color(cursor_t *cursor, board_t *board, sfVector2i *mouse, sfEvent *)
{
    sfColor tmp = sfImage_getPixel(board->image,
        mouse->x, mouse->y - BOARD_ESPACEMENT);

    for (size_t i = 0; i <= TRANSPARENT; i++) {
        if (is_same_color(tmp, COLORS[i])) {
            cursor->color = i;
            return;
        }
    }
}
