/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** my_paint
*/

#include "../../includes/my_paint.h"

static void draw_color_button(src_t *src)
{
    sfRenderWindow_drawRectangleShape(src->window, src->side_menu.rect_r,
        NULL);
    sfRenderWindow_drawRectangleShape(src->window, src->side_menu.rect_g,
        NULL);
    sfRenderWindow_drawRectangleShape(src->window, src->side_menu.rect_b,
        NULL);
    sfRenderWindow_drawRectangleShape(src->window, src->side_menu.rect_a,
        NULL);
    sfRenderWindow_drawRectangleShape(src->window, src->side_menu.red.rect,
        NULL);
    sfRenderWindow_drawRectangleShape(src->window, src->side_menu.green.rect,
        NULL);
    sfRenderWindow_drawRectangleShape(src->window, src->side_menu.blue.rect,
        NULL);
    sfRenderWindow_drawRectangleShape(src->window, src->side_menu.alpha.rect,
        NULL);
    sfRectangleShape_setFillColor(src->side_menu.preview,
        src->draw_area.color);
    sfRenderWindow_drawRectangleShape(src->window, src->side_menu.preview,
        NULL);
}

static void draw_menu_tool_box(src_t *src)
{
    sfRenderWindow_drawRectangleShape(src->window,
        src->side_menu.tool_box.rect, NULL);
    sfRenderWindow_drawText(src->window, src->side_menu.tool_box.text, NULL);
    if (src->side_menu.tool_box.state == CLICKED) {
        sfRenderWindow_drawRectangleShape(src->window,
            src->side_menu.minus.rect, NULL);
        sfRenderWindow_drawRectangleShape(src->window,
            src->side_menu.plus.rect, NULL);
        sfRenderWindow_drawSprite(src->window, src->side_menu.plus_sprite,
            NULL);
        sfRenderWindow_drawSprite(src->window, src->side_menu.minus_sprite,
            NULL);
        draw_color_button(src);
    }
}

static void draw_menu_edit_help(src_t *src)
{
    sfRenderWindow_drawRectangleShape(src->window, src->menu.edit.rect, NULL);
    sfRenderWindow_drawText(src->window, src->menu.edit.text, NULL);
    if (src->menu.edit.state == HOVER || src->menu.edit.state == CLICKED) {
        sfRenderWindow_drawRectangleShape(src->window, src->menu.pencil.rect,
            NULL);
        sfRenderWindow_drawRectangleShape(src->window, src->menu.eraser.rect,
            NULL);
        sfRenderWindow_drawText(src->window, src->menu.pencil.text, NULL);
        sfRenderWindow_drawText(src->window, src->menu.eraser.text, NULL);
    }
    sfRenderWindow_drawRectangleShape(src->window, src->menu.help.rect, NULL);
    sfRenderWindow_drawText(src->window, src->menu.help.text, NULL);
    if (src->menu.help.state == HOVER || src->menu.help.state == CLICKED) {
        sfRenderWindow_drawRectangleShape(src->window, src->menu.about.rect,
            NULL);
        sfRenderWindow_drawRectangleShape(src->window, src->menu.help_d.rect,
            NULL);
        sfRenderWindow_drawText(src->window, src->menu.about.text, NULL);
        sfRenderWindow_drawText(src->window, src->menu.help_d.text, NULL);
    }
}

static void draw_menu_file(src_t *src)
{
    sfRenderWindow_drawRectangleShape(src->window, src->menu.file.rect, NULL);
    sfRenderWindow_drawText(src->window, src->menu.file.text, NULL);
    if (src->menu.file.state == HOVER || src->menu.file.state == CLICKED) {
        sfRenderWindow_drawRectangleShape(src->window, src->menu.new_file.rect,
            NULL);
        sfRenderWindow_drawRectangleShape(src->window,
            src->menu.open_file.rect, NULL);
        sfRenderWindow_drawRectangleShape(src->window,
            src->menu.save_file.rect, NULL);
        sfRenderWindow_drawText(src->window, src->menu.new_file.text, NULL);
        sfRenderWindow_drawText(src->window, src->menu.open_file.text, NULL);
        sfRenderWindow_drawText(src->window, src->menu.save_file.text, NULL);
    }
}

void draw_menu(src_t *src)
{
    sfRenderWindow_drawRectangleShape(src->window, src->side_menu.rect, NULL);
    sfRenderWindow_drawRectangleShape(src->window, src->menu.rect, NULL);
    draw_menu_file(src);
    draw_menu_edit_help(src);
    draw_menu_tool_box(src);
}
