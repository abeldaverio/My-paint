/*
** EPITECH PROJECT, 2024
** init image
** File description:
** init the white board or load the image
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <stdbool.h>
#include <stdlib.h>
#include "settings.h"
#include "board.h"
#include "functions.h"

void add_node(image_t **image, sfImage *board)
{
    image_t *tmp = malloc(sizeof(image_t));

    tmp->image = sfImage_copy(board);
    tmp->next = *image;
    *image = tmp;
}

static sfImage *create_board(sfImage *board, char *path)
{
    sfImage *image = sfImage_createFromFile(path);

    if (image == NULL)
        return NULL;
    sfImage_copyImage(board, image, 0, 0, (sfIntRect){}, true);
    sfImage_destroy(image);
    return (board);
}

static image_t *load_image(char *path)
{
    image_t *image = NULL;
    sfImage *board = sfImage_createFromColor(LENGTH,
        HIGHT - BOARD_ESPACEMENT, sfTransparent);
    sfImage *tmp = NULL;

    if (path == NULL) {
        add_node(&image, board);
        sfImage_destroy(board);
        return image;
    }
    tmp = create_board(board, path);
    add_node(&image, tmp);
    sfImage_destroy(tmp);
    return image;
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
