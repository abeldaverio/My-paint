/*
** EPITECH PROJECT, 2024
** handle event
** File description:
** handle events
*/

#include <SFML/Graphics.h>
#include "button.h"
#include "functions.h"

void handle_events(sfRenderWindow *wnd,
    button_t **buttons, sfEvent *event, cursor_t *cursor)
{
    while (sfRenderWindow_pollEvent(wnd, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(wnd);
        check_button_click(wnd, event, buttons, cursor);
    }
}
