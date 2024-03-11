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
    #include "object.h"
    #include "enums/buttons_states.h"
    #include "enums/type.h"
    #include "cursor.h"
    #include "board.h"

typedef struct button_s {
    object_t main;
    object_t **options;
}button_t;

#endif
