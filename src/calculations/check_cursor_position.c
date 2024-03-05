/*
** EPITECH PROJECT, 2024
** check cursor pos
** File description:
** check cursor
*/

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "settings.h"

bool cursor_on_board(sfRenderWindow *wnd)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(wnd);

    return ((0 <= mouse.x && mouse.x <= LENGTH) &&
        (BOARD_ESPACEMENT <= mouse.y && mouse.y <= HIGHT));
}
