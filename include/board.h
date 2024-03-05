/*
** EPITECH PROJECT, 2024
** board.h
** File description:
** struct for the board
*/

#ifndef BOARD_H
    #define BOARD_H

    #include <SFML/Graphics.h>

typedef struct board_s {
    sfImage *image;
    sfTexture *texture;
    sfSprite *sprite;
}board_t;


#endif /* !BOARD_H */
