/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** my_paint
*/

#include "../../includes/my_paint.h"

static void is_clicked(button_t *button)
{
    if (button->state == PRESSED) {
        sfRectangleShape_setFillColor(button->rect,
            sfColor_fromRGB(30, 30, 30));
        button->state = CLICKED;
    }
}

static void check_color_clicked(src_t *src, float x_mouse)
{
    sfVector2f red = sfRectangleShape_getPosition(src->side_menu.red.rect);
    sfVector2f green = sfRectangleShape_getPosition(src->side_menu.green.rect);
    sfVector2f blue = sfRectangleShape_getPosition(src->side_menu.blue.rect);
    sfVector2f alpha = sfRectangleShape_getPosition(src->side_menu.alpha.rect);

    if (src->side_menu.red.state == PRESSED)
        sfRectangleShape_setPosition(src->side_menu.red.rect,
            (sfVector2f){x_mouse, 580});
    if (src->side_menu.green.state == PRESSED)
        sfRectangleShape_setPosition(src->side_menu.green.rect,
            (sfVector2f){x_mouse, 680});
    if (src->side_menu.blue.state == PRESSED)
        sfRectangleShape_setPosition(src->side_menu.blue.rect,
            (sfVector2f){x_mouse, 780});
    if (src->side_menu.alpha.state == PRESSED)
        sfRectangleShape_setPosition(src->side_menu.alpha.rect,
            (sfVector2f){x_mouse, 880});
    src->draw_area.color = sfColor_fromRGBA(red.x - 1542, green.x - 1542,
        blue.x - 1542, alpha.x - 1542);
}

static void check_tool_box_clicked(src_t *src)
{
    float x_mouse = src->event.mouseMove.x;

    if (src->side_menu.plus.state == CLICKED) {
        if (src->draw_area.size < 100)
            src->draw_area.size = src->draw_area.size + 1;
        src->side_menu.plus.state = NONE;
    }
    if (src->side_menu.minus.state == CLICKED) {
        if (src->draw_area.size > 1)
            src->draw_area.size = src->draw_area.size - 1;
        src->side_menu.minus.state = NONE;
    }
    if (x_mouse < 1542)
        x_mouse = 1542;
    if (x_mouse > 1797)
        x_mouse = 1797;
    check_color_clicked(src, x_mouse);
}

static void check_help_clicked(src_t *src)
{
    if (src->menu.about.state == CLICKED) {
        pop_about(src);
        src->menu.about.state = NONE;
        src->menu.help.state = NONE;
    }
    if (src->menu.help_d.state == CLICKED) {
        pop_help(src);
        src->menu.help_d.state = NONE;
        src->menu.help.state = NONE;
    }
    if (src->event.type == sfEvtMouseButtonReleased) {
        src->side_menu.red.state = NONE;
        src->side_menu.green.state = NONE;
        src->side_menu.blue.state = NONE;
        src->side_menu.alpha.state = NONE;
    }
}

static void check_file_clicked(src_t *src)
{
    if (src->menu.new_file.state == CLICKED) {
        src->draw_area.pixel_array = set_pixel_array(src);
        src->menu.new_file.state = NONE;
        src->menu.file.state = NONE;
    }
    if (src->menu.open_file.state == CLICKED) {
        open_file(src);
        src->menu.open_file.state = NONE;
        src->menu.file.state = NONE;
    }
    if (src->menu.save_file.state == CLICKED) {
        save_file(src);
        src->menu.save_file.state = NONE;
        src->menu.file.state = NONE;
    }
}

void check_clicked(src_t *src)
{
    is_clicked(&src->menu.file);
    is_clicked(&src->menu.edit);
    is_clicked(&src->menu.help);
    is_clicked(&src->menu.new_file);
    is_clicked(&src->menu.open_file);
    is_clicked(&src->menu.save_file);
    is_clicked(&src->menu.pencil);
    is_clicked(&src->menu.eraser);
    is_clicked(&src->menu.about);
    is_clicked(&src->menu.help_d);
    is_clicked(&src->side_menu.tool_box);
    is_clicked(&src->side_menu.minus);
    is_clicked(&src->side_menu.plus);
    check_file_clicked(src);
    check_help_clicked(src);
    check_tool_box_clicked(src);
}
