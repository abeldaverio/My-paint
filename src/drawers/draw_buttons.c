/*
** EPITECH PROJECT, 2024
** draw buttons
** File description:
** draw the buttons
*/

#include <SFML/Graphics.h>
#include "button.h"

void draw_buttons(sfRenderWindow *wnd, button_t **buttons)
{
    for (size_t i = 0; buttons[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(wnd, buttons[i]->main.rect, NULL);
        sfRenderWindow_drawSprite(wnd, buttons[i]->main.icon, NULL);
    }
}
