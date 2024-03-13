/*
** EPITECH PROJECT, 2024
** handle event
** File description:
** handle events
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>
#include "button.h"
#include "functions.h"

void handle_events(wnd_t *wnd_struct,
    button_t **buttons, cursor_t *cursor, board_t *board)
{
    while (sfRenderWindow_pollEvent(wnd_struct->wnd, &wnd_struct->Event)) {
        if (wnd_struct->Event.type == sfEvtClosed)
            sfRenderWindow_close(wnd_struct->wnd);
        if (check_button_click(wnd_struct, buttons, cursor, board))
            return;
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
            cursor_on_board(wnd_struct->wnd))
            update_board(wnd_struct, cursor, board);
        if (wnd_struct->Event.type == sfEvtResized)
            resize_event(wnd_struct);
        if (wnd_struct->Event.type == sfEvtMouseButtonReleased &&
            cursor_on_board(wnd_struct->wnd) == true)
            add_node(&board->image, board->image->image);
    }
}
