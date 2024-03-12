/*
** EPITECH PROJECT, 2024
** enormous
** File description:
** set the thikness to enormous
*/

#include "cursor.h"
#include "board.h"
#include "button.h"
#include "settings.h"

void set_enormous(button_t *, cursor_t *cursor, board_t *)
{
    cursor->thickness = 80;
}
