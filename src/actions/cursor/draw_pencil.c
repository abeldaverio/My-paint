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

void draw_pencil(cursor_t *cursor, board_t *board, sfVector2i *mouse)
{
    sfImage_setPixel(board->image, mouse->x, mouse->y - BOARD_ESPACEMENT,
        COLORS[cursor->color]);
}
