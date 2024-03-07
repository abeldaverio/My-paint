/*
** EPITECH PROJECT, 2024
** flip horizontal
** File description:
** flip
*/

#include "button.h"
#include "cursor.h"
#include "functions.h"

void flip_horizontal(object_t *, cursor_t *, board_t *board)
{
    sfImage_flipHorizontally(board->image);
}
