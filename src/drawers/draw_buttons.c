/*
** EPITECH PROJECT, 2024
** draw buttons
** File description:
** draw the buttons
*/

#include <SFML/Graphics.h>
#include "button.h"

static void draw_options(sfRenderWindow *wnd, object_t **options)
{
    for (size_t i = 0; options[i] != NULL; i++) {
        if (options[i]->hidden == false) {
        sfRenderWindow_drawRectangleShape(wnd, options[i]->rect, NULL);
        sfRenderWindow_drawSprite(wnd, options[i]->icon, NULL);
        }
    }
}

void draw_buttons(sfRenderWindow *wnd, button_t **buttons)
{
    for (size_t i = 0; buttons[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(wnd, buttons[i]->main.rect, NULL);
        sfRenderWindow_drawSprite(wnd, buttons[i]->main.icon, NULL);
    }
    for (size_t i = 0; buttons[i] != NULL; i++) {
        if (buttons[i]->options != NULL)
            draw_options(wnd, buttons[i]->options);
    }
}
