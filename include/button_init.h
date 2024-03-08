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
void flip_horizontal(struct object_s *, cursor_t *, board_t *);
void flip_vertical(struct object_s *, cursor_t *, board_t *);
void set_red(struct object_s *, cursor_t *, board_t *);
void set_black(struct object_s *, cursor_t *, board_t *);
void set_blue(struct object_s *, cursor_t *, board_t *);
void set_green(struct object_s *, cursor_t *, board_t *);
void set_orange(struct object_s *, cursor_t *, board_t *);
void set_cyan(struct object_s *, cursor_t *, board_t *);
void set_purple(struct object_s *, cursor_t *, board_t *);
void set_yellow(struct object_s *, cursor_t *, board_t *);
void set_brown(struct object_s *, cursor_t *, board_t *);
void set_pink(struct object_s *, cursor_t *, board_t *);
void set_beige(struct object_s *, cursor_t *, board_t *);
void set_white(struct object_s *, cursor_t *, board_t *);
void set_grey(struct object_s *, cursor_t *, board_t *);
void set_fushia(struct object_s *, cursor_t *, board_t *);

static const init_b_t INIT_B_TAB[] = {
    {{40, 40}, {5, 10}, PENCIL, TOOL, pencil_action},
    {{40, 40}, {50, 10}, ERASER, TOOL, eraser_action},
    {{40, 40}, {95, 10}, BRUSH, TOOL, brush_action},
    {{40, 40}, {140, 10}, PIPETTE, TOOL, pipette_action},
    {{40, 40}, {185, 10}, BUCKET, TOOL, bucket_action},
    {{40, 40}, {300, 10}, CLEAR, ONE_PRESS, clear_board},
    {{40, 40}, {345, 10}, FLIP_HORIZONTAL, ONE_PRESS, flip_horizontal},
    {{40, 40}, {390, 10}, FLIP_VERTICAL, ONE_PRESS, flip_vertical},
    {{18, 18}, {505, 10}, BLACK_I, COLOR, set_black},
    {{18, 18}, {529, 10}, RED_I, COLOR, set_red},
    {{18, 18}, {552, 10}, BLUE_I, COLOR, set_blue},
    {{18, 18}, {576, 10}, GREEN_I, COLOR, set_green},
    {{18, 18}, {600, 10}, ORANGE_I, COLOR, set_orange},
    {{18, 18}, {624, 10}, CYAN_I, COLOR, set_cyan},
    {{18, 18}, {648, 10}, PURPLE_I, COLOR, set_purple},
    {{18, 18}, {672, 10}, YELLOW_I, COLOR, set_yellow},
    {{18, 18}, {696, 10}, BROWN_I, COLOR, set_brown},
    {{18, 18}, {505, 32}, PINK_I, COLOR, set_pink},
    {{18, 18}, {529, 32}, BEIGE_I, COLOR, set_beige},
    {{18, 18}, {552, 32}, WHITE_I, COLOR, set_white},
    {{18, 18}, {574, 32}, GREY_I, COLOR, set_grey},
    {{18, 18}, {596, 32}, FUSHIA_I, COLOR, set_fushia},
};

static const size_t INIT_B_TAB_SIZE = sizeof(INIT_B_TAB) / sizeof(init_b_t);

#endif
