/*
** EPITECH PROJECT, 4024
** button intit
** File description:
** header for init the buttons
*/

#ifndef B_INIT_H
    #define B_INIT_H

    #include <SFML/Graphics.h>
    #include "enums/textures.h"
    #include "enums/buttons_states.h"
    #include "cursor.h"
    #include "button.h"

typedef struct init_b_s {
    sfVector2f size;
    sfVector2f pos;
    textures_t icon_nb;
    void (*action)(struct object_s *, cursor_t *);
}init_b_t;

//action functions
void pencil_action(struct object_s *, cursor_t *);
void eraser_action(struct object_s *, cursor_t *);
void brush_action(struct object_s *, cursor_t *);
void pipette_action(struct object_s *, cursor_t *);

static const init_b_t INIT_B_TAB[] = {
    {{40, 40}, {5, 10}, PENCIL, pencil_action},
    {{40, 40}, {50, 10}, ERASER, eraser_action},
    {{40, 40}, {95, 10}, BRUSH, brush_action},
    {{40, 40}, {140, 10}, PIPETTE, pipette_action},
};

static const size_t INIT_B_TAB_SIZE = sizeof(INIT_B_TAB) / sizeof(init_b_t);

#endif
