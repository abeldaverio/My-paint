/*
** EPITECH PROJECT, 2024
** big help
** File description:
** complete walkthrough of the app
*/

#include "button.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "object.h"
#include "window.h"
#include "settings.h"
#include "functions.h"

void big_help(button_t *, cursor_t *, board_t *)
{
    wnd_t *wnd_struct = init_window_struct(
        "my paint", LENGTH / 4, HIGHT / 4, FRAME);
    sfTexture **textures = init_textures();
    button_t **buttons = init_buttons(textures);

    if (wnd_struct->wnd == NULL)
        return;
    while (sfRenderWindow_isOpen(wnd_struct->wnd)) {
        sfRenderWindow_display(wnd_struct->wnd);
        sfRenderWindow_clear(wnd_struct->wnd, (sfColor){230, 230, 210, 255});
        mini_events(wnd_struct);
    }
    free_mini(wnd_struct, buttons, textures);
    return;
}
