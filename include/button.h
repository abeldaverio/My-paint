/*
** EPITECH PROJECT, 2024
** button
** File description:
** struct for buttons
*/

#ifndef BUTTON_H
    #define BUTTON_H

    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "enums/buttons_states.h"
    #include "cursor.h"

typedef struct object_s {
    sfRectangleShape *rect;
    sfSprite *icon;
    sfTexture *texture;
    state_t state;
    bool hidden;
    void (*action)(struct object_s *, cursor_t *);
}object_t;

typedef struct button_s {
    object_t main;
    object_t *options;
}button_t;

#endif