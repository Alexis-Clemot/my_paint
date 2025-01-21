/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** my_paint
*/

#include "../../includes/my_paint.h"

static void destroy_side_menu(src_t *src)
{
    sfRectangleShape_destroy(src->side_menu.rect);
    sfRectangleShape_destroy(src->side_menu.rect_r);
    sfRectangleShape_destroy(src->side_menu.rect_g);
    sfRectangleShape_destroy(src->side_menu.rect_b);
    sfRectangleShape_destroy(src->side_menu.rect_a);
    sfRectangleShape_destroy(src->side_menu.preview);
    sfRectangleShape_destroy(src->side_menu.tool_box.rect);
    sfRectangleShape_destroy(src->side_menu.plus.rect);
    sfRectangleShape_destroy(src->side_menu.minus.rect);
    sfRectangleShape_destroy(src->side_menu.red.rect);
    sfRectangleShape_destroy(src->side_menu.green.rect);
    sfRectangleShape_destroy(src->side_menu.blue.rect);
    sfRectangleShape_destroy(src->side_menu.alpha.rect);
    sfText_destroy(src->side_menu.tool_box.text);
    sfText_destroy(src->side_menu.plus.text);
    sfText_destroy(src->side_menu.minus.text);
    sfText_destroy(src->side_menu.red.text);
    sfText_destroy(src->side_menu.green.text);
    sfText_destroy(src->side_menu.blue.text);
    sfText_destroy(src->side_menu.alpha.text);
}

static void destroy_menu(src_t *src)
{
    sfRectangleShape_destroy(src->menu.file.rect);
    sfRectangleShape_destroy(src->menu.edit.rect);
    sfRectangleShape_destroy(src->menu.help.rect);
    sfRectangleShape_destroy(src->menu.new_file.rect);
    sfRectangleShape_destroy(src->menu.open_file.rect);
    sfRectangleShape_destroy(src->menu.save_file.rect);
    sfRectangleShape_destroy(src->menu.pencil.rect);
    sfRectangleShape_destroy(src->menu.eraser.rect);
    sfRectangleShape_destroy(src->menu.about.rect);
    sfRectangleShape_destroy(src->menu.help_d.rect);
    sfText_destroy(src->menu.file.text);
    sfText_destroy(src->menu.edit.text);
    sfText_destroy(src->menu.help.text);
    sfText_destroy(src->menu.new_file.text);
    sfText_destroy(src->menu.open_file.text);
    sfText_destroy(src->menu.save_file.text);
    sfText_destroy(src->menu.pencil.text);
    sfText_destroy(src->menu.eraser.text);
    sfText_destroy(src->menu.about.text);
    sfText_destroy(src->menu.help_d.text);
}

void destroy_src(src_t *src)
{
    sfRenderWindow_destroy(src->window);
    sfFont_destroy(src->font);
    sfRectangleShape_destroy(src->menu.rect);
    destroy_menu(src);
    destroy_side_menu(src);
    sfTexture_destroy(src->side_menu.plus_texture);
    sfTexture_destroy(src->side_menu.minus_texture);
    sfSprite_destroy(src->side_menu.plus_sprite);
    sfSprite_destroy(src->side_menu.minus_sprite);
    sfImage_destroy(src->draw_area.image);
    sfTexture_destroy(src->draw_area.pixel_array);
    sfSprite_destroy(src->draw_area.sprite_pixel_array);
    sfText_destroy(src->about.text);
    sfText_destroy(src->help.text);
}
