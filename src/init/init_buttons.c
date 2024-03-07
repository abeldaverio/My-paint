/*
** EPITECH PROJECT, 2024
** init buttons
** File description:
** function to initialise the buttons
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include "button.h"
#include "button_init.h"
#include "functions.h"

static button_t *init_button(int i, sfTexture **textures)
{
    button_t *button = malloc(sizeof(button_t));

    button->main.rect = sfRectangleShape_create();
    button->main.icon = sfSprite_create();
    if (button->main.rect == NULL || button->main.icon == NULL)
        return NULL;
    sfRectangleShape_setSize(button->main.rect, INIT_B_TAB[i].size);
    sfRectangleShape_setPosition(button->main.rect, INIT_B_TAB[i].pos);
    sfSprite_setTexture(button->main.icon,
        textures[INIT_B_TAB[i].icon_nb], false);
    button->main.texture = textures[INIT_B_TAB[i].icon_nb];
    sfSprite_setScale(button->main.icon,
        sprite_size(textures[INIT_B_TAB[i].icon_nb], INIT_B_TAB[i].size));
    sfSprite_setPosition(button->main.icon, INIT_B_TAB[i].pos);
    button->main.action = INIT_B_TAB[i].action;
    button->main.state = (INIT_B_TAB[i].icon_nb == BLACK_I) ? PRESSED : NONE;
    button->main.type = INIT_B_TAB[i].type;
    button->main.hidden = false;
    return button;
}

button_t **init_buttons(sfTexture **textures)
{
    button_t **array = malloc(sizeof(button_t *) * (INIT_B_TAB_SIZE + 1));

    if (array == NULL || textures == NULL)
        return NULL;
    for (size_t i = 0; i < INIT_B_TAB_SIZE; i++) {
        array[i] = init_button(i, textures);
        if (array[i] == NULL)
            return NULL;
    }
    array[INIT_B_TAB_SIZE] = NULL;
    return array;
}
