/*
** EPITECH PROJECT, 2024
** my paint
** File description:
** replica of paint
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "settings.h"
#include "functions.h"
#include "cursor.h"
#include "button.h"

static bool start_window(char *argv)
{
    sfRenderWindow *wnd = init_window("my paint", LENGTH, HIGHT, FRAME);
    sfTexture **textures = init_textures();
    button_t **buttons = init_buttons(textures);
    cursor_t *cursor = init_cursor(textures);
    sfEvent event;
    
    if (wnd == NULL)
        return false;
    while (sfRenderWindow_isOpen(wnd)) {
        draw_elements(wnd, buttons, cursor);
        sfRenderWindow_display(wnd);
        sfRenderWindow_clear(wnd, (sfColor){200, 200, 200, 255});
        handle_events(wnd, buttons, &event, cursor);
    }
    free_elements(wnd, buttons, textures, cursor);
    return true;
}

int my_paint(int argc, char **argv, char **env)
{
    if (argc > 2 || !check_env(env))
        return 84;
    if (!start_window(argv[1]))
        return 84;
    return 0;
}