/*
** EPITECH PROJECT, 2024
** fill bucket
** File description:
** fill a zone
*/

#include "settings.h"
#include "colors.h"
#include "cursor.h"
#include "board.h"
#include "functions.h"

void fill_the_board(sfColor *colors, sfImage *board,
    sfVector2i *current, sfUint8 count)
{
    if (!((current->x) >= 0 && current->x < LENGTH &&
        current->y >= 0 &&
        current->y < HIGHT - BOARD_ESPACEMENT &&
        is_same_color(sfImage_getPixel(board, current->x,
        current->y), colors[0]))) {
        return;
    }
    sfImage_setPixel(board, current->x,
        current->y, colors[1]);
    fill_the_board(colors, board,
        &((sfVector2i){current->x + 1, current->y}), count - 1);
    fill_the_board(colors, board,
        &((sfVector2i){current->x - 1, current->y}), count - 1);
    fill_the_board(colors, board,
        &((sfVector2i){current->x, current->y + 1}), count - 1);
    fill_the_board(colors, board,
        &((sfVector2i){current->x, current->y - 1}), count - 1);
}

void fill_bucket(cursor_t *cursor, board_t *board, sfVector2i *mouse)
{
    sfColor colors[2] = {sfImage_getPixel(board->image, mouse->x,
        mouse->y - BOARD_ESPACEMENT), COLORS[cursor->color]};

    if (is_same_color(colors[0], colors[1]))
        return;
    fill_the_board(colors, board->image, 
        &(sfVector2i){mouse->x, mouse->y - BOARD_ESPACEMENT}, 255);
}