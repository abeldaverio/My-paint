/*
** EPITECH PROJECT, 2024
** pencil help
** File description:
** shows help for pencil
*/

#include "button.h"
#include "libmy.h"

void bucket_help(button_t *, cursor_t *, board_t *)
{
    my_putstr("Bucket: Changes the cursor to a bucket and fills ");
    my_putstr("the surroundings pixel of the same color has it started ");
    my_putstr("to the selected color.\n");
}
