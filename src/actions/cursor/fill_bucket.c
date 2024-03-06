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
    sfVector2i *cur)
{
    sfImage_setPixel(board, cur->x,
        cur->y, colors[1]);
    if (cur->x + 1 < LENGTH &&
        is_same_color(sfImage_getPixel(board, cur->x + 1, cur->y), colors[0]))
        fill_the_board(colors, board, &((sfVector2i){cur->x + 1, cur->y}));
    if (cur->x > 0 &&
        is_same_color(sfImage_getPixel(board, cur->x - 1, cur->y), colors[0]))
        fill_the_board(colors, board, &((sfVector2i){cur->x - 1, cur->y}));
    if (cur->y + 1 < HIGHT - BOARD_ESPACEMENT &&
        is_same_color(sfImage_getPixel(board, cur->x, cur->y + 1), colors[0]))
        fill_the_board(colors, board, &((sfVector2i){cur->x, cur->y + 1}));
    if (cur->y > 0 &&
        is_same_color(sfImage_getPixel(board, cur->x, cur->y - 1), colors[0]))
        fill_the_board(colors, board, &((sfVector2i){cur->x, cur->y - 1}));
}

void fill_bucket(cursor_t *cursor, board_t *board, sfVector2i *mouse)
{
    sfColor colors[2] = {sfImage_getPixel(board->image, mouse->x,
        mouse->y - BOARD_ESPACEMENT), COLORS[cursor->color]};

    if (is_same_color(colors[0], colors[1]))
        return;
    fill_the_board(colors, board->image,
        &(sfVector2i){mouse->x, mouse->y - BOARD_ESPACEMENT});
}
