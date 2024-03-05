/*
** EPITECH PROJECT, 2024
** init cursor
** File description:
** init the base cursor
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "enums/textures.h"
#include "enums/colors.h"
#include "cursor.h"
#include "functions.h"

cursor_t *init_cursor(sfTexture **textures)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));

    if (cursor == NULL || textures == NULL)
        return NULL;
    cursor->icon = sfSprite_create();
    if (cursor->icon == NULL)
        return NULL;
    sfSprite_setTexture(cursor->icon, textures[BASIC], sfFalse);
    sfSprite_setScale(cursor->icon,
        sprite_size(textures[BASIC], (sfVector2f){20, 20}));
    cursor->basic = textures[BASIC];
    cursor->current = BASIC;
    cursor->color = BLACK;
    cursor->pos = (sfVector2f){0, 0};
    return cursor;
}
