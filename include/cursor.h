/*
** EPITECH PROJECT, 2024
** cursor
** File description:
** header for cursor struct
*/

#ifndef CURSOR_T
    #define CURSOR_T

    #include <SFML/Graphics.h>
    #include "enums/colors.h"
    #include "enums/textures.h"

typedef struct cursor_s {
    sfSprite *icon;
    sfTexture *basic;
    enum textures_e current;
    enum color_e color;
    sfVector2f pos;
}cursor_t;

#endif 
