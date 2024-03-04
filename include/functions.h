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

//mains
int my_paint(int argc, char **argv, char **env);

//inits
sfRenderWindow *init_window(char *name, int length, int higth, int frame);
button_t **init_buttons(sfTexture **);
sfTexture **init_textures(void);
cursor_t *init_cursor(sfTexture **textures);

//checkers
bool check_env(char **env);

//drawers
void draw_elements(sfRenderWindow *wnd, button_t **buttons, cursor_t *cursor);
void draw_buttons(sfRenderWindow *wnd, button_t **buttons);
void draw_cursor(sfRenderWindow *wnd, cursor_t *cursor);

//event handlers
void handle_events(sfRenderWindow *wnd, button_t **buttons,
    sfEvent *event, cursor_t *cursor);
void check_button_click(sfEvent *event, button_t **buttons, cursor_t *cursor);

//update functions
void update_buttons(button_t **buttons);

//calculation functions
sfVector2f sprite_size(sfTexture *text, sfVector2f size);

//free functions
void free_elements(sfRenderWindow *wnd,
    button_t **buttons, sfTexture **textures, cursor_t *cursor);

#endif
