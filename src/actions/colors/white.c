/*
** EPITECH PROJECT, 2024
** white
** File description:
** set white
*/

#include "cursor.h"
#include "board.h"
#include "button.h"
#include "colors.h"

void set_white(button_t *, cursor_t *cursor, board_t *)
{
    cursor->color = WHITE;
}
