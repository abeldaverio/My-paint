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

void mini_events(wnd_t *wnd_struct)
{
    while (sfRenderWindow_pollEvent(wnd_struct->wnd, &wnd_struct->Event)) {
        if (wnd_struct->Event.type == sfEvtClosed)
            sfRenderWindow_close(wnd_struct->wnd);
        if (wnd_struct->Event.type == sfEvtResized)
            resize_event(wnd_struct);
    }
}
