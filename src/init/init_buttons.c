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

static void set_icon(int i, button_t *button, sfTexture **textures)
{
    sfRectangleShape_setSize(button->main.rect, INIT_B_TAB[i].size);
    sfRectangleShape_setPosition(button->main.rect, INIT_B_TAB[i].pos);
    sfSprite_setTexture(button->main.icon,
        textures[INIT_B_TAB[i].icon_nb], false);
    button->main.texture = textures[INIT_B_TAB[i].icon_nb];
    sfSprite_setScale(button->main.icon,
        sprite_size(textures[INIT_B_TAB[i].icon_nb], INIT_B_TAB[i].size));
    sfSprite_setPosition(button->main.icon, INIT_B_TAB[i].pos);
}

static bool init_menu_icon(object_t **menu, int i,
    sfTexture **textures, const init_b_t *init_tab)
{
    menu[i]->rect = sfRectangleShape_create();
    menu[i]->icon = sfSprite_create();
    if (menu[i]->rect == NULL || menu[i]->icon == NULL)
        return false;
    sfRectangleShape_setSize(menu[i]->rect, init_tab[i].size);
    sfRectangleShape_setPosition(menu[i]->rect, init_tab[i].pos);
    sfSprite_setTexture(menu[i]->icon,
        textures[init_tab[i].icon_nb], false);
    menu[i]->texture = textures[init_tab[i].icon_nb];
    sfSprite_setScale(menu[i]->icon,
        sprite_size(textures[init_tab[i].icon_nb], init_tab[i].size));
    sfSprite_setPosition(menu[i]->icon, init_tab[i].pos);
    return true;
}

static object_t **init_menu(const init_b_t *init_tab,
    size_t size, sfTexture **textures)
{
    object_t **menu = malloc(sizeof(button_t *) * (size + 1));

    if (menu == NULL)
        return NULL;
    for (size_t i = 0; i < (size); i++) {
        menu[i] = malloc(sizeof(object_t));
        if (menu[i] == NULL)
            return NULL;
        if (!init_menu_icon(menu, i, textures, init_tab))
            return NULL;
        menu[i]->action = init_tab[i].action;
        menu[i]->state = (init_tab[i].icon_nb == BLACK_I) ? PRESSED : NONE;
        menu[i]->type = init_tab[i].type;
        menu[i]->hidden = true;
    }
    menu[size] = NULL;
    return menu;
}

static button_t *init_button(int i, sfTexture **textures)
{
    button_t *button = malloc(sizeof(button_t));

    button->main.rect = sfRectangleShape_create();
    button->main.icon = sfSprite_create();
    if (button->main.rect == NULL || button->main.icon == NULL)
        return NULL;
    set_icon(i, button, textures);
    if (INIT_B_TAB[i].menu == NULL) {
        button->options = NULL;
    } else {
        button->options = init_menu(INIT_B_TAB[i].menu,
            INIT_B_TAB[i].option_size, textures);
    }
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
