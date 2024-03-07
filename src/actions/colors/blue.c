/*
** EPITECH PROJECT, 2024
** blue
** File description:
** set blue
*/

#include "cursor.h"
#include "board.h"
#include "colors.h"

void set_blue(struct object_s *, cursor_t *cursor, board_t *)
{
    cursor->color = BLUE;
}
