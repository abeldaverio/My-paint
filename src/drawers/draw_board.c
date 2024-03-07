/*
** EPITECH PROJECT, 2024
** draw board
** File description:
** draw the board
*/

#include <SFML/Graphics.h>
#include "board.h"

void draw_board(sfRenderWindow *wnd, board_t *board)
{
    sfTexture_updateFromImage(board->texture, board->image, 0, 0);
    sfSprite_setTexture(board->sprite, board->texture, sfFalse);
    sfRenderWindow_drawRectangleShape(wnd, board->background, NULL);
    sfRenderWindow_drawSprite(wnd, board->sprite, NULL);
}
