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
    "assets/icons/basic.png",
    "assets/icons/pencil.png",
    "assets/icons/eraser.png",
    "assets/icons/brush.png",
    "assets/icons/pipette.png",
    "assets/icons/bucket.png",
    "assets/icons/clear.png"
};

static const size_t TEXTURE_TAB_S = sizeof(INIT_TEXTURE_TAB) / sizeof(char *);

#endif
