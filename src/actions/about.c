/*
** EPITECH PROJECT, 2024
** about
** File description:
** shows the informations of the creators
*/

#include "button.h"
#include "libmy.h"

void about(button_t *, cursor_t *cursor, board_t *)
{
    (void)cursor;
    my_putstr("My_Paint made with love, by abel.daverio@epitech.eu & "
        "remi.nouveau@epitech.eu.\n");
}
