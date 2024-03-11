/*
** EPITECH PROJECT, 2024
** open menu
** File description:
** when a drop menu button is clicked
*/

#include "button.h"

void open_menu(button_t *button, cursor_t *, board_t *)
{
    for (size_t i = 0; button->options[i] != NULL; i++) {
        button->options[i]->hidden = false;
    }
}
