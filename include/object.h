/*
** EPITECH PROJECT, 2024
** OBJECT
** File description:
** struct for OBJECTs
*/

#ifndef OBJECT_H
    #define OBJECT_H

    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "button.h"
    #include "enums/buttons_states.h"
    #include "enums/type.h"
    #include "cursor.h"
    #include "board.h"

typedef struct button_s button_t;

typedef struct object_s {
    sfRectangleShape *rect;
    sfSprite *icon;
    sfTexture *texture;
    state_t state;
    type_t type;
    bool hidden;
    void (*action)(button_t *, cursor_t *, board_t *);
}object_t;

#endif
