/*
** EPITECH PROJECT, 2024
** draw elements
** File description:
** draw on the window
*/

#include <SFML/Graphics.h>
#include "button.h"
#include "functions.h"
#include "cursor.h"

void draw_elements(sfRenderWindow *wnd, button_t **buttons,
    cursor_t *cursor, board_t *board)
{
    draw_board(wnd, board);
    draw_buttons(wnd, buttons);
    draw_cursor(wnd, cursor);
}
