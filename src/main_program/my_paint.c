/*
** EPITECH PROJECT, 2024
** my paint
** File description:
** replica of paint
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "window.h"
#include "settings.h"
#include "functions.h"
#include "cursor.h"
#include "button.h"

static bool start_window(char *argv)
{
    wnd_t *wnd_struct = init_window_struct("my paint", LENGTH, HIGHT, FRAME);
    sfTexture **textures = init_textures();
    button_t **buttons = init_buttons(textures);
    cursor_t *cursor = init_cursor(textures);
    board_t *board = init_image(argv);

    if (wnd_struct->wnd == NULL || textures == NULL || buttons == NULL ||
        cursor == NULL || board == NULL)
        return false;
    while (sfRenderWindow_isOpen(wnd_struct->wnd)) {
        update_buttons(buttons);
        draw_elements(wnd_struct->wnd, buttons, cursor, board);
        sfRenderWindow_display(wnd_struct->wnd);
        sfRenderWindow_clear(wnd_struct->wnd, (sfColor){230, 230, 210, 255});
        handle_events(wnd_struct, buttons, cursor, board);
    }
    free_elements(wnd_struct, buttons, textures, cursor);
    free_more_elements(board);
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
