/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** my_paint
*/

#include "../../includes/my_paint.h"

void close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed ||
        (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyEscape))
        sfRenderWindow_close(window);
}

void manage_event(src_t *src)
{
    check_hover(src);
    check_clicked(src);
    if (src->event.type == sfEvtMouseButtonPressed)
        check_pressed(src);
    close_window(src->window, src->event);
}
