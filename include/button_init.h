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
    void (*action)(button_t *, cursor_t *, board_t *);
    const struct init_b_s *menu;
    size_t option_size;
}init_b_t;

//action functions
void pencil_action(button_t *, cursor_t *, board_t *);
void eraser_action(button_t *, cursor_t *, board_t *);
void brush_action(button_t *, cursor_t *, board_t *);
void pipette_action(button_t *, cursor_t *, board_t *);
void bucket_action(button_t *, cursor_t *, board_t *);
void clear_board(button_t *, cursor_t *, board_t *);
void flip_horizontal(button_t *, cursor_t *, board_t *);
void flip_vertical(button_t *, cursor_t *, board_t *);
void open_menu(button_t *, cursor_t *, board_t *);
void set_red(button_t *, cursor_t *, board_t *);
void set_black(button_t *, cursor_t *, board_t *);
void set_blue(button_t *, cursor_t *, board_t *);
void set_green(button_t *, cursor_t *, board_t *);
void set_orange(button_t *, cursor_t *, board_t *);
void set_cyan(button_t *, cursor_t *, board_t *);
void set_purple(button_t *, cursor_t *, board_t *);
void set_yellow(button_t *, cursor_t *, board_t *);
void set_brown(button_t *, cursor_t *, board_t *);
void set_pink(button_t *, cursor_t *, board_t *);
void set_beige(button_t *, cursor_t *, board_t *);
void set_white(button_t *, cursor_t *, board_t *);
void set_grey(button_t *, cursor_t *, board_t *);
void set_fushia(button_t *, cursor_t *, board_t *);

static const init_b_t INIT_FILE_MENU[] = {
    {{60, 30}, {0, 30}, SAVE, DROP, pencil_action, NULL, 0},
};

static const init_b_t INIT_B_TAB[] = {
    {{60, 30}, {0, 0}, FILE, DROP, open_menu, INIT_FILE_MENU,
        sizeof(INIT_FILE_MENU) / sizeof(init_b_t)},
    {{40, 40}, {5, 40}, PENCIL, TOOL, pencil_action, NULL, 0},
    {{40, 40}, {50, 40}, ERASER, TOOL, eraser_action, NULL, 0},
    {{40, 40}, {95, 40}, BRUSH, TOOL, brush_action, NULL, 0},
    {{40, 40}, {140, 40}, PIPETTE, TOOL, pipette_action, NULL, 0},
    {{40, 40}, {185, 40}, BUCKET, TOOL, bucket_action, NULL, 0},
    {{40, 40}, {300, 40}, CLEAR, ONE_PRESS, clear_board, NULL, 0},
    {{40, 40}, {345, 40}, FLIP_HORIZONTAL, ONE_PRESS,
        flip_horizontal, NULL, 0},
    {{40, 40}, {390, 40}, FLIP_VERTICAL, ONE_PRESS,
        flip_vertical, NULL, 0},
    {{18, 18}, {505, 40}, BLACK_I, COLOR, set_black, NULL, 0},
    {{18, 18}, {529, 40}, RED_I, COLOR, set_red, NULL, 0},
    {{18, 18}, {552, 40}, BLUE_I, COLOR, set_blue, NULL, 0},
    {{18, 18}, {576, 40}, GREEN_I, COLOR, set_green, NULL, 0},
    {{18, 18}, {600, 40}, ORANGE_I, COLOR, set_orange, NULL, 0},
    {{18, 18}, {624, 40}, CYAN_I, COLOR, set_cyan, NULL, 0},
    {{18, 18}, {648, 40}, PURPLE_I, COLOR, set_purple, NULL, 0},
    {{18, 18}, {672, 40}, YELLOW_I, COLOR, set_yellow, NULL, 0},
    {{18, 18}, {696, 40}, BROWN_I, COLOR, set_brown, NULL, 0},
    {{18, 18}, {505, 62}, PINK_I, COLOR, set_pink, NULL, 0},
    {{18, 18}, {529, 62}, BEIGE_I, COLOR, set_beige, NULL, 0},
    {{18, 18}, {552, 62}, WHITE_I, COLOR, set_white, NULL, 0},
    {{18, 18}, {576, 62}, GREY_I, COLOR, set_grey, NULL, 0},
    {{18, 18}, {600, 62}, FUSHIA_I, COLOR, set_fushia, NULL, 0},
};

static const size_t INIT_B_TAB_SIZE = sizeof(INIT_B_TAB) / sizeof(init_b_t);

#endif
