/*
** EPITECH PROJECT, 2024
** button events
** File description:
** button events
*/

#include <SFML/Graphics.h>
#include "window.h"
#include "button.h"
#include "board.h"

static bool is_hover(sfRenderWindow *wnd, button_t *button)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(wnd);
    sfVector2f pos = sfRectangleShape_getPosition(button->main.rect);
    sfVector2f size = sfRectangleShape_getSize(button->main.rect);

    return (pos.x <= mouse.x && mouse.x <= pos.x + size.x &&
        pos.y <= mouse.y && mouse.y <= pos.y + size.y);
}

void reset_other_buttons(button_t **buttons, size_t i, type_t type)
{
    for (size_t j = 0; buttons[j] != NULL; j++) {
        if (j == i || buttons[j]->main.type != type)
            continue;
        buttons[j]->main.state = NONE;
    }
}

static bool check_the_button(sfRenderWindow *wnd, button_t *button,
    cursor_t *cursor, sfEvent *event, board_t *board)
{
    if (button->main.type == COLOR && button->main.state == PRESSED)
        return false;
    if (is_hover(wnd, button)) {
        if (event->type == sfEvtMouseButtonPressed) {
            button->main.state = (button->main.state == PRESSED) ?
                HOVER : PRESSED;
            button->main.action(&button->main, cursor, board);
            return true;
        } else {
            button->main.state = (button->main.state == PRESSED) ?
                PRESSED : HOVER;
        }
    } else {
        button->main.state = (button->main.state == PRESSED) ?
                PRESSED : NONE;
    }
    return false;
}

void check_button_click(wnd_t *wnd_struct,
    button_t **buttons, cursor_t *cursor, board_t *board)
{
    for (size_t i = 0; buttons[i] != NULL; i++) {
        if (buttons[i]->main.type == ONE_PRESS)
            buttons[i]->main.state = NONE;
    }
    for (size_t i = 0; buttons[i] != NULL; i++) {
        if (check_the_button(wnd_struct->wnd, buttons[i], cursor,
            &wnd_struct->Event, board))
            reset_other_buttons(buttons, i, buttons[i]->main.type);
    }
}
