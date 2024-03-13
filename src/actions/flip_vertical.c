/*
** EPITECH PROJECT, 2024
** flip vertical
** File description:
** flip
*/

#include "button.h"
#include "cursor.h"
#include "functions.h"

void flip_vertical(button_t *, cursor_t *, board_t *board)
{
    sfImage_flipVertically(board->image->image);
}
