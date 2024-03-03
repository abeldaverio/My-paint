/*
** EPITECH PROJECT, 2024
** init textures
** File description:
** init the textures
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "texture_init.h"

sfTexture **init_textures(void)
{
    sfTexture **array = malloc(sizeof(sfTexture *) * (TEXTURE_TAB_SIZE + 1));

    if (array == NULL)
        return NULL;
    for (size_t i = 0; i < TEXTURE_TAB_SIZE; i++) {
        array[i] = sfTexture_createFromFile(INIT_TEXTURE_TAB[i], NULL);
        if (array[i] == NULL)
            return NULL;
    }
    array[TEXTURE_TAB_SIZE] = NULL;
    return array;
}