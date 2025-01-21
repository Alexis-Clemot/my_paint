/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** my_paint
*/

#include "../../includes/my_paint.h"

static int set_pixel(draw_area_t *draw_area, sfMouseMoveEvent *mouse,
    sfColor color, src_t *src)
{
    for (int x = 0; x != src->draw_area.size; x++) {
        for (int y = 0; y != src->draw_area.size; y++) {
            sfImage_setPixel(draw_area->image, mouse->x + x,
                mouse->y - 108 + y, color);
        }
    }
}

static void is_hover_draw(draw_area_t *draw_area, sfMouseMoveEvent *mouse,
    sfColor color, src_t *src)
{
    sfFloatRect bound = sfSprite_getGlobalBounds(
        draw_area->sprite_pixel_array);

    sfBool bool = sfFloatRect_contains(&bound, mouse->x, mouse->y);
    if (bool == 1) {
        set_pixel(draw_area, mouse, color, src);
        sfTexture_destroy(draw_area->pixel_array);
        draw_area->pixel_array = sfTexture_createFromImage(draw_area->image,
            NULL);
        sfSprite_setTexture(draw_area->sprite_pixel_array,
            draw_area->pixel_array, sfTrue);
    }
}

static void is_hover(button_t *button, sfMouseMoveEvent *mouse)
{
    sfFloatRect rect_bound = sfRectangleShape_getGlobalBounds(button->rect);

    sfBool bool = sfFloatRect_contains(&rect_bound, mouse->x, mouse->y);
    if (button->state == CLICKED || button->state == PRESSED)
        return;
    if (bool == 1) {
        sfRectangleShape_setFillColor(button->rect,
            sfColor_fromRGB(120, 120, 120));
        button->state = HOVER;
    } else {
        sfRectangleShape_setFillColor(button->rect,
            sfColor_fromRGB(90, 90, 90));
        button->state = NONE;
    }
}

static void check_draw(src_t *src)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (src->menu.pencil.state == CLICKED)
            is_hover_draw(&src->draw_area, &src->event.mouseMove,
                src->draw_area.color, src);
        if (src->menu.eraser.state == CLICKED)
            is_hover_draw(&src->draw_area, &src->event.mouseMove, sfWhite,
                src);
    }
}

void check_hover(src_t *src)
{
    is_hover(&src->menu.file, &src->event.mouseMove);
    is_hover(&src->menu.edit, &src->event.mouseMove);
    is_hover(&src->menu.help, &src->event.mouseMove);
    is_hover(&src->menu.new_file, &src->event.mouseMove);
    is_hover(&src->menu.open_file, &src->event.mouseMove);
    is_hover(&src->menu.save_file, &src->event.mouseMove);
    is_hover(&src->menu.pencil, &src->event.mouseMove);
    is_hover(&src->menu.eraser, &src->event.mouseMove);
    is_hover(&src->menu.about, &src->event.mouseMove);
    is_hover(&src->menu.help_d, &src->event.mouseMove);
    is_hover(&src->side_menu.tool_box, &src->event.mouseMove);
    is_hover(&src->side_menu.minus, &src->event.mouseMove);
    is_hover(&src->side_menu.plus, &src->event.mouseMove);
    is_hover(&src->side_menu.red, &src->event.mouseMove);
    is_hover(&src->side_menu.green, &src->event.mouseMove);
    is_hover(&src->side_menu.blue, &src->event.mouseMove);
    is_hover(&src->side_menu.alpha, &src->event.mouseMove);
    check_draw(src);
}
