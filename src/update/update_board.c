/*
** EPITECH PROJECT, 2024
** update board
** File description:
** draw on the board
*/

#include <SFML/Graphics.h>
#include "settings.h"
#include "cursor.h"
#include "board.h"
#include "cursor_action.h"

void update_board(sfRenderWindow *wnd, cursor_t *cursor, board_t *board)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(wnd);

    for (size_t i = 0; i < NB_OF_ACT; i++) {
        if (cursor->current == CURSOR_ACT[i].mode)
            CURSOR_ACT[i].action(cursor, board, &mouse);
    }
}
