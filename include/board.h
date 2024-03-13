/*
** EPITECH PROJECT, 2024
** board.h
** File description:
** struct for the board
*/

#ifndef BOARD_H
    #define BOARD_H

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Types.h>

typedef struct image_s {
    sfImage *image;
    struct image_s *next;
}image_t;

typedef struct board_s {
    image_t *image;
    sfRectangleShape *background;
    sfTexture *texture;
    sfSprite *sprite;
}board_t;


#endif /* !BOARD_H */
