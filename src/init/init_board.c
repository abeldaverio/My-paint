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

static sfImage *load_image(char *path)
{
    sfTexture *tmp;
    sfImage *board = sfImage_createFromColor(LENGTH,
        HIGHT - BOARD_ESPACEMENT, sfTransparent);

    if (path == NULL)
        return board;
    return sfImage_createFromFile(path);
}

static board_t *generate_board(char *path)
{
    board_t *board = malloc(sizeof(board_t));

    if (board == NULL)
        return NULL;
    board->image = load_image(path);
    board->texture = sfTexture_create(LENGTH, HIGHT - BOARD_ESPACEMENT);
    board->sprite = sfSprite_create();
    board->background = sfRectangleShape_create();
    if (board->image == NULL || board->texture == NULL ||
        board->sprite == NULL || board->background == NULL)
        return NULL;
    sfSprite_setPosition(board->sprite, (sfVector2f){0, BOARD_ESPACEMENT});
    sfRectangleShape_setSize(board->background,
        (sfVector2f){LENGTH, HIGHT - BOARD_ESPACEMENT});
    sfRectangleShape_setFillColor(board->background, sfWhite);
    sfRectangleShape_setPosition(board->background,
        (sfVector2f){0, BOARD_ESPACEMENT});
    return board;
}

board_t *init_image(char *path)
{
    return generate_board(path);
}
