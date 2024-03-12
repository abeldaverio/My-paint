/*
** EPITECH PROJECT, 2024
** pencil help
** File description:
** shows help for pencil
*/

#include "button.h"
#include "libmy.h"

void brush_help(button_t *, cursor_t *, board_t *)
{
    my_putstr("Brush: Changes the cursor to a brush and draws in a ");
    my_putstr("circular shape right under the pencil.\n");
}
