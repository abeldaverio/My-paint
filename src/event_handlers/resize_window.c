/*
** EPITECH PROJECT, 2024
** resize window
** File description:
** resize window with new size
*/

#include "window.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>

void resize_event(wnd_t *wnd_struct)
{
    sfFloatRect size = {0, 0, wnd_struct->Event.size.width,
        wnd_struct->Event.size.height};
    sfView const *visible = sfView_createFromRect(size);

    sfRenderWindow_setView(wnd_struct->wnd, visible);
}
