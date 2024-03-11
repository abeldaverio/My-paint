/*
** EPITECH PROJECT, 2024
** red
** File description:
** set black
*/

#include "cursor.h"
#include "board.h"
#include "button.h"
#include "colors.h"

void set_black(button_t *, cursor_t *cursor, board_t *)
{
    cursor->color = BLACK;
}
