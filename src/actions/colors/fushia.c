/*
** EPITECH PROJECT, 2024
** fushia
** File description:
** set fushia
*/

#include "cursor.h"
#include "board.h"
#include "button.h"
#include "colors.h"

void set_fushia(button_t *, cursor_t *cursor, board_t *)
{
    cursor->color = FUSHIA;
}
