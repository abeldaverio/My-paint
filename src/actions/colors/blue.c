/*
** EPITECH PROJECT, 2024
** blue
** File description:
** set blue
*/

#include "cursor.h"
#include "board.h"
#include "button.h"
#include "colors.h"

void set_blue(object_t *, cursor_t *cursor, board_t *)
{
    cursor->color = BLUE;
}
