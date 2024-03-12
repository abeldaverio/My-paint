/*
** EPITECH PROJECT, 2024
** save
** File description:
** save image in file
*/

#include "board.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Types.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libmy.h"
#include "button.h"
#include "settings.h"

static _Bool my_endcmp(char *str1, char *str2)
{
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);

    if (size2 > size1)
        return false;
    for (int i = size1 - 1; size2 > 0; --i) {
        if (str2[size2 - 1] != str1[i]) {
            return false;
        }
        size2--;
    }
    return true;
}

static char *my_strndup(char *src, int n)
{
    int size = n > my_strlen(src) ? my_strlen(src) : n;
    char *dest = malloc(sizeof(char) * size + 1);

    for (int i = 0; i < size; ++i)
        dest[i] = src[i];
    dest[size] = '\0';
    return (dest);
}

static char *user_input(void)
{
    size_t n = 0;
    int input_size = 0;
    char *input = NULL;
    char *dest = NULL;

    write(1, "Enter  name: ", 12);
    while (input_size <= 1) {
        input_size = getline(&input, &n, stdin);
    }
    dest = my_strndup(input, input_size - 1);
    free(input);
    return (dest);
}

void save_image(button_t *, cursor_t *, board_t *board)
{
    char *input = user_input();
    sfImage *copy = sfImage_createFromColor(LENGTH,
        HIGHT - BOARD_ESPACEMENT, sfWhite);
    char *new_string = NULL;

    if (my_endcmp(input, ".jpg") == false && my_endcmp(input, ".png") == false
        && my_endcmp(input, ".bmp") == false)
        new_string = my_strconcat(input, ".jpg");
    sfImage_copyImage(copy, board->image, 0, 0, (sfIntRect){}, true);
    sfImage_saveToFile(copy, new_string);
    sfImage_destroy(copy);
    free(new_string);
    free(input);
}
