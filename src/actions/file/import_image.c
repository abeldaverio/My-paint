/*
** EPITECH PROJECT, 2024
** import image
** File description:
** import an image on the board
*/

#include <stdio.h>
#include <stdlib.h>
#include "button.h"
#include "cursor.h"
#include "functions.h"
#include "libmy.h"

static char *get_input(void)
{
    char *input = NULL;
    char *file_name = NULL;
    int size = 0;
    size_t n = 0;

    my_putstr("enter an image to import (CANCEL for cancel):\n");
    size = getline(&input, &n, stdin);
    while (size == 1)
        size = getline(&input, &n, stdin);
    if (size == -1)
        return NULL;
    if (my_strcmp(input, "CANCEL\n")) {
        free(input);
        return NULL;
    }
    file_name = my_strndup(input, my_strlen(input) - 1);
    free(input);
    return file_name;
}

void import_image(button_t *, cursor_t *, board_t *board)
{
    char *input = get_input();
    sfImage *tmp = NULL;

    if (input == NULL)
        return;
    tmp = sfImage_createFromFile(input);
    free(input);
    if (tmp == NULL) {
        return;
    }
    sfImage_copyImage(board->image, tmp, 0, 0, (sfIntRect){}, true);
    sfImage_destroy(tmp);
    return;
}
