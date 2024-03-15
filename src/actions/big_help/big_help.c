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

static void menu_free(button_t *button)
{
    for (size_t i = 0; button->options[i] != NULL; i++) {
        sfSprite_destroy(button->options[i]->icon);
        sfRectangleShape_destroy(button->options[i]->rect);
        free(button->options[i]);
    }
    free(button->options);
}

static void button_free(button_t **buttons)
{
    for (size_t i = 0; buttons[i] != NULL; ++i) {
        sfRectangleShape_destroy(buttons[i]->main.rect);
        sfSprite_destroy(buttons[i]->main.icon);
        if (buttons[i]->options != NULL)
            menu_free(buttons[i]);
        free(buttons[i]);
    }
    free(buttons);
}

static void free_textures(sfTexture **textures)
{
    for (size_t i = 0; textures[i] != NULL; i++) {
        sfTexture_destroy(textures[i]);
    }
    free(textures);
}

static void free_mini(wnd_t *wnd_struct, button_t **buttons,
    sfTexture **textures)
{
    sfRenderWindow_destroy(wnd_struct->wnd);
    free(wnd_struct);
    button_free(buttons);
    free_textures(textures);
}

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
