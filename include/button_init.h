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
    #include "enums/type.h"
    #include "cursor.h"
    #include "button.h"

typedef struct init_b_s {
    sfVector2f size;
    sfVector2f pos;
    textures_t icon_nb;
    type_t type;
    void (*action)(struct object_s *, cursor_t *, board_t *);
}init_b_t;

//action functions
void pencil_action(struct object_s *, cursor_t *, board_t *);
void eraser_action(struct object_s *, cursor_t *, board_t *);
void brush_action(struct object_s *, cursor_t *, board_t *);
void pipette_action(struct object_s *, cursor_t *, board_t *);
void bucket_action(struct object_s *, cursor_t *, board_t *);
void clear_board(struct object_s *, cursor_t *, board_t *);

static const init_b_t INIT_B_TAB[] = {
    {{40, 40}, {5, 10}, PENCIL, TOOL, pencil_action},
    {{40, 40}, {50, 10}, ERASER, TOOL, eraser_action},
    {{40, 40}, {95, 10}, BRUSH, TOOL, brush_action},
    {{40, 40}, {140, 10}, PIPETTE, TOOL, pipette_action},
    {{40, 40}, {185, 10}, BUCKET, TOOL, bucket_action},
    {{40, 40}, {300, 10}, CLEAR, ONE_PRESS, clear_board}
};

static const size_t INIT_B_TAB_SIZE = sizeof(INIT_B_TAB) / sizeof(init_b_t);

#endif
