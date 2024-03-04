/*
** EPITECH PROJECT, 2024
** button states
** File description:
** tab for color associated with states
*/

#ifndef BUTTON_STATES_H
    #define BUTTON_STATES_H

    #include <SFML/Graphics.h>
    #include "enums/buttons_states.h"

typedef struct check_state_s {
    state_t state;
    sfColor bg_color;
}check_state_t;

static const check_state_t STATES_TAB[] = {
    {NONE, {255, 255, 255, 255}},
    {HOVER, {211, 211, 211, 255}},
    {PRESSED, {180, 180, 180, 255}},
    {OPEN, {0, 255, 255, 255}},
};

static const size_t STATES_TAB_S = sizeof(STATES_TAB) / sizeof(check_state_t);

#endif /* !BUTTON_STATES_H */
