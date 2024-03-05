/*
** EPITECH PROJECT, 2024
** init image
** File description:
** init the white board or load the image
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "settings.h"
#include "board.h"
#include "functions.h"

board_t *empty_board(void)
{
    board_t *board = malloc(sizeof(board_t));

    if (board == NULL)
        return NULL;
    board->image = sfImage_createFromColor(LENGTH, HIGHT - BOARD_ESPACEMENT,
        sfWhite);
    board->texture = sfTexture_create(LENGTH, HIGHT - BOARD_ESPACEMENT);
    board->sprite = sfSprite_create();
    if (board->image == NULL || board->texture == NULL ||
        board->sprite == NULL)
        return NULL;
    sfSprite_setPosition(board->sprite, (sfVector2f){0, BOARD_ESPACEMENT});
    return board;
}

board_t *load_image(char *path)
{
    board_t *board = malloc(sizeof(board_t));

    if (board == NULL)
        return NULL;
    board->image = sfImage_createFromFile(path);
    board->texture = sfTexture_create(LENGTH, HIGHT - BOARD_ESPACEMENT);
    board->sprite = sfSprite_create();
    if (board->image == NULL || board->texture == NULL ||
        board->sprite == NULL)
        return NULL;
    sfSprite_setPosition(board->sprite, (sfVector2f){0, BOARD_ESPACEMENT});
    return board;
}

board_t *init_image(char *path)
{
    if (path == NULL) {
        return empty_board();
    }
    return load_image(path);
}
