/*
** EPITECH PROJECT, 2024
** red
** File description:
** set red
*/

#include "cursor.h"
#include "board.h"
#include "colors.h"

void set_red(struct object_s *, cursor_t *cursor, board_t *)
{
    cursor->color = RED;
}
