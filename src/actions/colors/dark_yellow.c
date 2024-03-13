/*
** EPITECH PROJECT, 2024
** dark_yellow
** File description:
** set dark_yellow
*/

#include "cursor.h"
#include "board.h"
#include "button.h"
#include "colors.h"

void set_dark_yellow(button_t *, cursor_t *cursor, board_t *)
{
    cursor->color = DARK_YELLOW;
}
