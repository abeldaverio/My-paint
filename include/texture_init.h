/*
** EPITECH PROJECT, 2024
** texture 
** File description:
** init
*/

#ifndef TEXTURE_INIT_H
    #define TEXTURE_INIT_H

    #include <stddef.h>

static const char *INIT_TEXTURE_TAB[] = {
    "assests/icons/basic.png",
    "assests/icons/pencil.png",
    "assests/icons/eraser.png",
    "assests/icons/brush.png",
    "assests/icons/pipette.png"
};

static const size_t TEXTURE_TAB_SIZE =
    sizeof(INIT_TEXTURE_TAB) / sizeof(char *);

#endif /* !TEXTURE_INIT */
