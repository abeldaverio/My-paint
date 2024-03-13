/*
** EPITECH PROJECT, 2024
** pencil help
** File description:
** shows help for pencil
*/

#include "button.h"
#include "libmy.h"

void pipette_help(button_t *, cursor_t *cursor, board_t *)
{
    (void)cursor;
    my_putstr("Pipette: Changes the cursor to a pipette and replaces the ");
    my_putstr("drawing color to the color of the selected pixel.\n");
}
