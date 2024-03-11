/*
** EPITECH PROJECT, 2024
** grey
** File description:
** set grey
*/

#include "cursor.h"
#include "board.h"
#include "button.h"
#include "colors.h"

void set_grey(button_t *, cursor_t *cursor, board_t *)
{
    cursor->color = GREY;
}
