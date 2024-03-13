/*
** EPITECH PROJECT, 2024
** dark_cyan
** File description:
** set dark_cyan
*/

#include "cursor.h"
#include "board.h"
#include "button.h"
#include "colors.h"

void set_dark_cyan(button_t *, cursor_t *cursor, board_t *)
{
    cursor->color = DARK_CYAN;
}
