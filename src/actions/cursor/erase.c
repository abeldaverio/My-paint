/*
** EPITECH PROJECT, 2024
** draw pencil
** File description:
** action when pencil is selected
*/

#include "settings.h"
#include "cursor.h"
#include "board.h"

void erase(cursor_t *, board_t *board, sfVector2i *mouse)
{
    sfImage_setPixel(board->image, mouse->x, mouse->y - BOARD_ESPACEMENT,
        sfWhite);
}
