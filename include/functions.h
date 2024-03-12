/*
** EPITECH PROJECT, 2024
** functions
** File description:
** functions for my paint
*/

#ifndef FUNCTIONS_H
    #define FUNCTIONS_H

    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "button.h"
    #include "cursor.h"
    #include "board.h"
    #include "window.h"

//mains
int my_paint(int argc, char **argv, char **env);

//inits
wnd_t *init_window_struct(char *name, int length, int higth, int frame);
button_t **init_buttons(sfTexture **);
sfTexture **init_textures(void);
cursor_t *init_cursor(sfTexture **textures);
board_t *init_image(char *path);

//checkers
bool check_env(char **env);

//drawers
void draw_elements(sfRenderWindow *wnd, button_t **buttons,
    cursor_t *cursor, board_t *board);
void draw_buttons(sfRenderWindow *wnd, button_t **buttons);
void draw_cursor(sfRenderWindow *wnd, cursor_t *cursor);
void draw_board(sfRenderWindow *wnd, board_t *board);

//event handlers
void handle_events(wnd_t *wnd_struct, button_t **buttons,
    cursor_t *cursor, board_t *board);
bool check_button_click(wnd_t *wnd_struct,
    button_t **buttons, cursor_t *cursor, board_t *board);
void resize_event(wnd_t *wnd_struct);

//update functions
void update_buttons(button_t **buttons);
void update_board(wnd_t *wnd_struct, cursor_t *cursor, board_t *board);

//calculation functions
sfVector2f sprite_size(sfTexture *text, sfVector2f size);
bool cursor_on_board(sfRenderWindow *wnd);
sfBool is_same_color(sfColor first, sfColor second);

//free functions
void free_elements(wnd_t *wnd_strcut,
    button_t **buttons, sfTexture **textures, cursor_t *cursor);
void free_more_elements(board_t *board);

#endif
