/*
** EPITECH PROJECT, 2023
** init window
** File description:
** function to return a csfml window
*/

#include <SFML/Graphics.h>

sfRenderWindow *init_window(char *name, int length, int higth, int frame)
{
    sfVideoMode node = {length, higth, 100};
    sfRenderWindow *wnd = sfRenderWindow_create(node, name, 4 | 2, NULL);

    sfRenderWindow_setFramerateLimit(wnd, frame);
    return wnd;
}
