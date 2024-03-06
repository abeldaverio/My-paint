/*
** EPITECH PROJECT, 2023
** init window
** File description:
** function to return a csfml window
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "window.h"

wnd_t *init_window_struct(char *name, int length, int higth, int frame)
{
    sfVideoMode node = {length, higth, 100};
    wnd_t *wnd_struct = malloc(sizeof(wnd_t));

    if (wnd_struct == NULL)
        return NULL;
    wnd_struct->wnd = sfRenderWindow_create(node, name, 4 | 2, NULL);
    if (wnd_struct->wnd == NULL)
        return NULL;
    sfRenderWindow_setFramerateLimit(wnd_struct->wnd, frame);
    return wnd_struct;
}
