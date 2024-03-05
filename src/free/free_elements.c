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

static void destroy_buttons(button_t **buttons)
{
    for (size_t i = 0; buttons[i] != NULL; i++) {
        sfRectangleShape_destroy(buttons[i]->main.rect);
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
    sfSprite_destroy(board->sprite);
    sfTexture_destroy(board->texture);
    free(board);
}

void free_elements(sfRenderWindow *wnd, button_t **buttons,
    sfTexture **textures, cursor_t *cursor)
{
    sfRenderWindow_destroy(wnd);
    destroy_buttons(buttons);
    destroy_textures(textures);
    destroy_cursor(cursor);
}

void free_more_elements(board_t *board)
{
    destroy_board(board);
}
