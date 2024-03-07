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
    sfVector2i *cur, sfVector2i *dir)
{
    if (cur->y > HIGHT)
        return;
    for (int i = 0; cur->x + (dir->x * i) >= 0 &&
        cur->x + (dir->x * i) < LENGTH &&
        is_same_color(colors[0],
        sfImage_getPixel(board, cur->x + (dir->x * i), cur->y)); i++) {
        if (cur->y + dir->y < (HIGHT - BOARD_ESPACEMENT) &&
            cur->y + dir->y >= 0 &&
            is_same_color(colors[0],
            sfImage_getPixel(board, cur->x + (dir->x * i), cur->y + dir->y)))
            fill_the_board(colors, board,
                &(sfVector2i){cur->x + (dir->x * i), cur->y + dir->y}, dir);
        sfImage_setPixel(board, cur->x + (dir->x * i), cur->y, colors[1]);
    }
}

void fill_bucket(cursor_t *cursor, board_t *board, sfVector2i *mouse)
{
    sfColor colors[2] = {sfImage_getPixel(board->image, mouse->x,
        mouse->y - BOARD_ESPACEMENT), COLORS[cursor->color]};

    if (mouse->x < HIGHT - 1 && !is_same_color(colors[0], colors[1]))
        fill_the_board(colors, board->image,
            &(sfVector2i){mouse->x + 1, mouse->y - BOARD_ESPACEMENT},
            &(sfVector2i){-1, 1});
    if (mouse->y > BOARD_ESPACEMENT && !is_same_color(colors[0], colors[1]))
        fill_the_board(colors, board->image,
            &(sfVector2i){mouse->x, mouse->y - BOARD_ESPACEMENT - 1},
            &(sfVector2i){1, -1});
    if (mouse->x < HIGHT - 2 && !is_same_color(colors[0], colors[1]))
        fill_the_board(colors, board->image,
            &(sfVector2i){mouse->x + 2, mouse->y - BOARD_ESPACEMENT},
            &(sfVector2i){1, 1});
    if (mouse->y < HIGHT - BOARD_ESPACEMENT - 1 && mouse->x < HIGHT - 1 &&
        !is_same_color(colors[0], colors[1]))
        fill_the_board(colors, board->image,
            &(sfVector2i){mouse->x - 1, mouse->y - BOARD_ESPACEMENT - 1},
            &(sfVector2i){-1, -1});
}
