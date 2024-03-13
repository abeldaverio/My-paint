/*
** EPITECH PROJECT, 2024
** light_beige
** File description:
** set light_beige
*/

#include "cursor.h"
#include "board.h"
#include "button.h"
#include "colors.h"

void set_light_beige(button_t *, cursor_t *cursor, board_t *)
{
    cursor->color = LIGHT_BEIGE;
}
