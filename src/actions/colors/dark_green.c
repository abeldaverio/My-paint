/*
** EPITECH PROJECT, 2024
** dark_green
** File description:
** set dark_green
*/

#include "cursor.h"
#include "board.h"
#include "button.h"
#include "colors.h"

void set_dark_green(button_t *, cursor_t *cursor, board_t *)
{
    cursor->color = DARK_GREEN;
}
