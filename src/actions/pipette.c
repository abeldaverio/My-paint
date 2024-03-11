/*
** EPITECH PROJECT, 2024
** pipette
** File description:
** pipette action
*/

#include "button.h"
#include "cursor.h"
#include "functions.h"

void pipette_action(button_t *button, cursor_t *cursor, board_t *)
{
    if (cursor->current == PIPETTE) {
        sfSprite_setTexture(cursor->icon, cursor->basic, true);
        sfSprite_setScale(cursor->icon,
            sprite_size(cursor->basic, (sfVector2f){20, 20}));
        cursor->pos = (sfVector2f){0, 0};
        cursor->current = BASIC;
    } else {
        sfSprite_setTexture(cursor->icon, button->main.texture, true);
        cursor->pos = (sfVector2f){0, -20};
        sfSprite_setScale(cursor->icon,
            sprite_size(button->main.texture, (sfVector2f){20, 20}));
        cursor->current = PIPETTE;
    }
}
