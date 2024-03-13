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
void save_image(button_t *, cursor_t *, board_t *);
void import_image(button_t *, cursor_t *, board_t *);
void pencil_help(button_t *, cursor_t *, board_t *);
void eraser_help(button_t *, cursor_t *, board_t *);
void brush_help(button_t *, cursor_t *, board_t *);
void pipette_help(button_t *, cursor_t *, board_t *);
void bucket_help(button_t *, cursor_t *, board_t *);
void clear_help(button_t *, cursor_t *, board_t *);
void flip_horizontal_help(button_t *, cursor_t *, board_t *);
void flip_vertical_help(button_t *, cursor_t *, board_t *);


//colors
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

//sizes
void set_litle(button_t *, cursor_t *, board_t *);
void set_litle_big(button_t *, cursor_t *, board_t *);
void set_medium(button_t *, cursor_t *, board_t *);
void set_big_litle(button_t *, cursor_t *, board_t *);
void set_big(button_t *, cursor_t *, board_t *);
void set_enormous(button_t *, cursor_t *, board_t *);

static const init_b_t INIT_FILE_MENU[] = {
    {{60, 30}, {0, 30}, SAVE, DROP, save_image, NULL, 0},
    {{60, 30}, {0, 60}, IMPORT, DROP, import_image, NULL, 0},
    {{60, 30}, {0, 90}, IMPORT, DROP, clear_board, NULL, 0},
};

static const init_b_t INIT_EDIT_MENU[] = {
    {{60, 40}, {60, 30}, PENCIL, DROP, pencil_action, NULL, 0},
    {{60, 40}, {60, 70}, ERASER, DROP, eraser_action, NULL, 0},
};

static const init_b_t INIT_HELP_MENU[] = {
    {{60, 40}, {120, 30}, ABOUT, DROP, pencil_help, NULL, 0},
    {{60, 40}, {120, 70}, PENCIL, DROP, pencil_help, NULL, 0},
    {{60, 40}, {120, 110}, ERASER, DROP, eraser_help, NULL, 0},
    {{60, 40}, {120, 150}, BRUSH, DROP, brush_help, NULL, 0},
    {{60, 40}, {120, 190}, PIPETTE, DROP, pipette_help, NULL, 0},
    {{60, 40}, {120, 230}, BUCKET, DROP, bucket_help, NULL, 0},
    {{60, 40}, {120, 270}, CLEAR, DROP, clear_help, NULL, 0},
    {{60, 40}, {120, 310}, FLIP_HORIZONTAL, DROP,
        flip_horizontal_help, NULL, 0},
    {{60, 40}, {120, 350}, FLIP_VERTICAL, DROP, flip_vertical_help, NULL, 0},
};

static const init_b_t INIT_SIZE_MENU[] = {
    {{40, 20}, {242, 90}, LITLE, DROP, set_litle, NULL, 0},
    {{40, 20}, {242, 110}, LITLE_BIG, DROP, set_litle_big, NULL, 0},
    {{40, 20}, {242, 130}, MEDIUM, DROP, set_medium, NULL, 0},
    {{40, 20}, {242, 150}, BIG_LITLE, DROP, set_big_litle, NULL, 0},
    {{40, 20}, {242, 170}, BIG, DROP, set_big, NULL, 0},
    {{40, 20}, {242, 190}, ENORMOUS, DROP, set_enormous, NULL, 0},
};

static const init_b_t INIT_B_TAB[] = {
    {{60, 30}, {0, 0}, FILE_I, DROP, open_menu, INIT_FILE_MENU,
        sizeof(INIT_FILE_MENU) / sizeof(init_b_t)},
    {{60, 30}, {60, 0}, FILE_I, DROP, open_menu, INIT_EDIT_MENU,
        sizeof(INIT_EDIT_MENU) / sizeof(init_b_t)},
    {{60, 30}, {120, 0}, HELP_I, DROP, open_menu, INIT_HELP_MENU,
        sizeof(INIT_HELP_MENU) / sizeof(init_b_t)},
    {{40, 40}, {5, 40}, PENCIL, TOOL, pencil_action, NULL, 0},
    {{40, 40}, {50, 40}, ERASER, TOOL, eraser_action, NULL, 0},
    {{40, 40}, {95, 40}, BRUSH, TOOL, brush_action, NULL, 0},
    {{40, 40}, {140, 40}, PIPETTE, TOOL, pipette_action, NULL, 0},
    {{40, 40}, {185, 40}, BUCKET, TOOL, bucket_action, NULL, 0},
    {{40, 50}, {242, 40}, SIZE, DROP, open_menu, INIT_SIZE_MENU,
        sizeof(INIT_SIZE_MENU) / sizeof(init_b_t)},
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
