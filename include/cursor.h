/*
** EPITECH PROJECT, 2024
** cursor
** File description:
** header for cursor struct
*/

#ifndef CURSOR_H
    #define CURSOR_H

    #include <SFML/Graphics.h>
    #include "enums/colors.h"
    #include "enums/textures.h"

typedef struct cursor_s {
    sfSprite *icon;
    sfTexture *basic;
    enum textures_e current;
    enum color_e color;
    size_t thickness;
    sfVector2f pos;
}cursor_t;

#endif
