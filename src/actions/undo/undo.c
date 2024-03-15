/*
** EPITECH PROJECT, 2024
** undo action
** File description:
** remove last node from function
*/

#include "board.h"
#include "button.h"
#include "functions.h"
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Types.h>
#include <stddef.h>
#include <stdlib.h>
#include "settings.h"

static void destroy(board_t *board)
{
    image_t *image = (board)->image;

    (board)->image = (board)->image->next;
    sfImage_destroy(image->image);
    free(image);
}

void undo(button_t *, cursor_t *, board_t *board)
{
    image_t *tmp = board->image;
    sfImage *image = board->image->image;
    sfImage *imgtmp = NULL;

    if (board->image->next == NULL) {
        board->image = board->image->next;
        imgtmp = sfImage_createFromColor(LENGTH,
            HIGHT - BOARD_ESPACEMENT, sfTransparent);
        add_node(&board->image, imgtmp);
        sfImage_destroy(imgtmp);
        sfImage_destroy(image);
        free(tmp);
        return;
    }
    destroy(board);
}
