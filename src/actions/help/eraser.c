/*
** EPITECH PROJECT, 2024
** pencil help
** File description:
** shows help for pencil
*/

#include "button.h"
#include "libmy.h"

void eraser_help(button_t *, cursor_t *cursor, board_t *)
{
    (void)cursor;
    my_putstr("Eraser: Changes the cursor to an eraser and deletes the ");
    my_putstr("pixel in a cubic form right under the eraser.\n");
}
