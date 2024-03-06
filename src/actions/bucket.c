/*
** EPITECH PROJECT, 2024
** bucket action
** File description:
** fill
*/

#include "button.h"
#include "cursor.h"
#include "functions.h"

void bucket_action(object_t *button, cursor_t *cursor, board_t *)
{
    if (cursor->current == BUCKET) {
        sfSprite_setTexture(cursor->icon, cursor->basic, true);
        sfSprite_setScale(cursor->icon,
            sprite_size(cursor->basic, (sfVector2f){20, 20}));
        cursor->pos = (sfVector2f){0, 0};
        cursor->current = BASIC;
    } else {
        sfSprite_setTexture(cursor->icon, button->texture, true);
        cursor->pos = (sfVector2f){0, -8};
        sfSprite_setScale(cursor->icon,
            sprite_size(button->texture, (sfVector2f){20, 20}));
        cursor->current = BUCKET;
    }
}
