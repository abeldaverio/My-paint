/*
** EPITECH PROJECT, 2024
** clear
** File description:
** clear board
*/

#include "button.h"
#include "cursor.h"
#include "functions.h"
#include "settings.h"

void clear_board(object_t *, cursor_t *, board_t *board)
{
    sfImage_destroy(board->image);
    board->image = sfImage_createFromColor(LENGTH, HIGHT - BOARD_ESPACEMENT,
        sfWhite);
}