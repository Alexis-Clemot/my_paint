/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** my_paint
*/

#include "../../includes/my_paint.h"

void draw_sprite(src_t *src)
{
    sfRenderWindow_clear(src->window, sfBlack);
    sfRenderWindow_drawSprite(src->window,
        src->draw_area.sprite_pixel_array, NULL);
    draw_menu(src);
}
