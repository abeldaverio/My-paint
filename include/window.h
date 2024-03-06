/*
** EPITECH PROJECT, 2024
** window
** File description:
** windiw
*/

#ifndef WINDOW_H
    #define WINDOW_H

    #include <SFML/Graphics.h>

typedef struct wnd_s {
    sfRenderWindow *wnd;
    sfEvent Event;
}wnd_t;

#endif
