/*
** EPITECH PROJECT, 2024
** pencil help
** File description:
** shows help for pencil
*/

#include "button.h"
#include "libmy.h"

void flip_horizontal_help(button_t *, cursor_t *cursor, board_t *)
{
    (void)cursor;
    my_putstr("Flip Horizontal: When pressed, flips the image horizontally.");
    my_putstr("\n");
}
