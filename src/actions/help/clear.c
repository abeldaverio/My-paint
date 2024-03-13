/*
** EPITECH PROJECT, 2024
** pencil help
** File description:
** shows help for pencil
*/

#include "button.h"
#include "libmy.h"

void clear_help(button_t *, cursor_t *cursor, board_t *)
{
    (void)cursor;
    my_putstr("Clear: When pressed, removes the entire image and puts ");
    my_putstr("a white background.\n");
}
