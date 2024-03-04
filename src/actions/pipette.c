/*
** EPITECH PROJECT, 2024
** pipette
** File description:
** pipette action
*/

#include "button.h"
#include "cursor.h"
#include "functions.h"

void pipette_action(object_t *button, cursor_t *cursor)
{
    if (cursor->current == PIPETTE) {
        sfSprite_setTexture(cursor->icon, cursor->basic, false);
        sfSprite_setScale(cursor->icon,
            sprite_size(cursor->basic, (sfVector2f){20, 20}));
        cursor->pos = (sfVector2f){0, 0};
        cursor->current = BASIC;
    } else {
        sfSprite_setTexture(cursor->icon, button->texture, false);
        cursor->pos = (sfVector2f){0, -20};
        sfSprite_setScale(cursor->icon,
            sprite_size(button->texture, (sfVector2f){20, 20}));
        cursor->current = PIPETTE;
    }
}
