/*
** EPITECH PROJECT, 2024
** button events
** File description:
** button events
*/

#include <SFML/Graphics.h>
#include "button.h"

static bool is_hover(sfMouseButtonEvent *mouse, button_t *button)
{
    sfVector2f pos = sfRectangleShape_getPosition(button->main.rect);
    sfVector2f size = sfRectangleShape_getSize(button->main.rect);

    return (pos.x <= mouse->x && mouse->x <= pos.x + size.x &&
        pos.y <= mouse->y && mouse->y <= pos.y + size.y);
}

void reset_other_buttons(button_t **buttons, size_t i)
{
    for (size_t j = 0; buttons[j] != NULL; j++) {
        if (j == i)
            continue;
        buttons[j]->main.state = NONE;
    }
}

void check_button_click(sfEvent *event, button_t **buttons, cursor_t *cursor)
{
    for (size_t i = 0; buttons[i] != NULL; i++) {
        if (is_hover(&event->mouseButton, buttons[i])) {
            buttons[i]->main.state = (buttons[i]->main.state == PRESSED) ?
                NONE : PRESSED;
            reset_other_buttons(buttons, i);
            buttons[i]->main.action(&buttons[i]->main, cursor);
            return;
        }
    }
}
