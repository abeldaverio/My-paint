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
    board_t *board = init_image(argv);

    if (wnd == NULL || textures == NULL || buttons == NULL ||
        cursor == NULL || board == NULL)
        return false;
    while (sfRenderWindow_isOpen(wnd)) {
        update_buttons(buttons);
        draw_elements(wnd, buttons, cursor, board);
        sfRenderWindow_display(wnd);
        sfRenderWindow_clear(wnd, (sfColor){230, 230, 210, 255});
        handle_events(wnd, buttons, cursor, board);
    }
    free_elements(wnd, buttons, textures, cursor);
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
