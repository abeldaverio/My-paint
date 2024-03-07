/*
** EPITECH PROJECT, 2024
** update buttons
** File description:
** update the graphic part of the buttons
*/

#include <SFML/Graphics.h>
#include "button_states.h"
#include "button.h"

static void update_color_style(object_t *button)
{
    for (size_t i = 0; i < COL_S_TAB_S; i++) {
        if (COL_S_TAB[i].state == button->state) {
            sfRectangleShape_setOutlineThickness(button->rect, 2);
            sfRectangleShape_setOutlineColor(button->rect,
                COL_S_TAB[i].bg_color);
        }
    }
}

static void update_option_style(object_t *button)
{
    for (size_t i = 0; i < STATES_TAB_S; i++) {
        if (STATES_TAB[i].state == button->state) {
            sfRectangleShape_setFillColor(button->rect,
                STATES_TAB[i].bg_color);
        }
    }
}

void update_buttons(button_t **buttons)
{
    for (size_t i = 0; buttons[i] != NULL; i++) {
        if (buttons[i]->main.type == COLOR)
            update_color_style(&buttons[i]->main);
        else
            update_option_style(&buttons[i]->main);
    }
}
