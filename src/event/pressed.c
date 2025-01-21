/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** my_paint
*/

#include "../../includes/my_paint.h"

static void is_pressed(button_t *button, sfMouseButtonEvent *mouse)
{
    sfFloatRect rect_bound = sfRectangleShape_getGlobalBounds(button->rect);

    sfBool bool = sfFloatRect_contains(&rect_bound, mouse->x, mouse->y);
    if (bool == 0)
        return;
    if (button->state == CLICKED) {
        sfRectangleShape_setFillColor(button->rect,
            sfColor_fromRGB(90, 90, 90));
        button->state = NONE;
    } else {
        sfRectangleShape_setFillColor(button->rect,
            sfColor_fromRGB(60, 60, 60));
        button->state = PRESSED;
    }
}

static void check_tool_box_pressed(src_t *src)
{
    is_pressed(&src->side_menu.tool_box, &src->event.mouseButton);
    if (src->side_menu.tool_box.state == CLICKED) {
        is_pressed(&src->side_menu.minus, &src->event.mouseButton);
        is_pressed(&src->side_menu.plus, &src->event.mouseButton);
        is_pressed(&src->side_menu.red, &src->event.mouseButton);
        is_pressed(&src->side_menu.blue, &src->event.mouseButton);
        is_pressed(&src->side_menu.green, &src->event.mouseButton);
        is_pressed(&src->side_menu.alpha, &src->event.mouseButton);
    }
}

static void check_drop_menu_pressed(src_t *src)
{
    if (src->menu.file.state == CLICKED) {
        is_pressed(&src->menu.new_file, &src->event.mouseButton);
        is_pressed(&src->menu.open_file, &src->event.mouseButton);
        is_pressed(&src->menu.save_file, &src->event.mouseButton);
    }
    if (src->menu.edit.state == CLICKED) {
        is_pressed(&src->menu.pencil, &src->event.mouseButton);
        if (src->menu.pencil.state == PRESSED &&
            src->menu.eraser.state == CLICKED)
            src->menu.eraser.state = NONE;
        is_pressed(&src->menu.eraser, &src->event.mouseButton);
        if (src->menu.eraser.state == PRESSED &&
            src->menu.pencil.state == CLICKED)
            src->menu.pencil.state = NONE;
    }
    if (src->menu.help.state == CLICKED) {
        is_pressed(&src->menu.about, &src->event.mouseButton);
        is_pressed(&src->menu.help_d, &src->event.mouseButton);
    }
}

static void check_menu_pressed(src_t *src)
{
    is_pressed(&src->menu.file, &src->event.mouseButton);
    if (src->menu.file.state == PRESSED && src->menu.edit.state == CLICKED)
        src->menu.edit.state = NONE;
    if (src->menu.file.state == PRESSED && src->menu.help.state == CLICKED)
        src->menu.help.state = NONE;
    is_pressed(&src->menu.edit, &src->event.mouseButton);
    if (src->menu.edit.state == PRESSED && src->menu.file.state == CLICKED)
        src->menu.file.state = NONE;
    if (src->menu.edit.state == PRESSED && src->menu.help.state == CLICKED)
        src->menu.help.state = NONE;
    is_pressed(&src->menu.help, &src->event.mouseButton);
    if (src->menu.help.state == PRESSED && src->menu.file.state == CLICKED)
        src->menu.file.state = NONE;
    if (src->menu.help.state == PRESSED && src->menu.edit.state == CLICKED)
        src->menu.edit.state = NONE;
}

void check_pressed(src_t *src)
{
    check_menu_pressed(src);
    check_drop_menu_pressed(src);
    check_tool_box_pressed(src);
}
