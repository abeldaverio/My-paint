/*
** EPITECH PROJECT, 2024
** free elements
** File description:
** free all
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "button.h"
#include "cursor.h"
#include "board.h"
#include "window.h"

static void destroy_menu(button_t *button)
{
    for (size_t i = 0; button->options[i] != NULL; i++) {
        sfSprite_destroy(button->options[i]->icon);
        sfRectangleShape_destroy(button->options[i]->rect);
        free(button->options[i]);
    }
    free(button->options);
}

static void destroy_buttons(button_t **buttons)
{
    for (size_t i = 0; buttons[i] != NULL; i++) {
        sfRectangleShape_destroy(buttons[i]->main.rect);
        sfSprite_destroy(buttons[i]->main.icon);
        if (buttons[i]->options != NULL) {
            destroy_menu(buttons[i]);
        }
        free(buttons[i]);
    }
    free(buttons);
}

static void destroy_textures(sfTexture **textures)
{
    for (size_t i = 0; textures[i] != NULL; i++) {
        sfTexture_destroy(textures[i]);
    }
    free(textures);
}

static void destroy_cursor(cursor_t *cursor)
{
    sfSprite_destroy(cursor->icon);
    free(cursor);
}

static void destroy_board(board_t *board)
{
    sfImage_destroy(board->image);
    sfRectangleShape_destroy(board->background);
    sfSprite_destroy(board->sprite);
    sfTexture_destroy(board->texture);
    free(board);
}

void free_elements(wnd_t *wnd_struct, button_t **buttons,
    sfTexture **textures, cursor_t *cursor)
{
    sfRenderWindow_destroy(wnd_struct->wnd);
    free(wnd_struct);
    destroy_buttons(buttons);
    destroy_textures(textures);
    destroy_cursor(cursor);
}

void free_more_elements(board_t *board)
{
    destroy_board(board);
}
