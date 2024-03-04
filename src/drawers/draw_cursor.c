/*
** EPITECH PROJECT, 2024
** draw cursor
** File description:
** cursor draw
*/

#include <SFML/Graphics.h>
#include "cursor.h"

void draw_cursor(sfRenderWindow *wnd, cursor_t *cursor)
{
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(wnd);

    sfRenderWindow_setMouseCursorVisible(wnd, sfFalse);
    sfSprite_setPosition(cursor->icon,
        (sfVector2f){mousepos.x + cursor->pos.x, mousepos.y + cursor->pos.y});
    sfRenderWindow_drawSprite(wnd, cursor->icon, NULL);
}
