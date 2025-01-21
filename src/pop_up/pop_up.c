/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** my_paint_pop_about
*/

#include "../../includes/my_paint.h"

static sfRenderWindow *create_window(unsigned int width, unsigned int height,
    char *name)
{
    sfRenderWindow *win;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    win = sfRenderWindow_create(video_mode, name, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win, 180);
    return win;
}

void pop_help(src_t *src)
{
    src->help.window = create_window(500, 500, "Help");
    while (sfRenderWindow_isOpen(src->help.window)) {
        while (sfRenderWindow_pollEvent(src->help.window, &src->help.event))
            close_window(src->help.window, src->help.event);
        sfRenderWindow_clear(src->help.window, sfBlack);
        sfRenderWindow_drawText(src->help.window, src->help.text, NULL);
        sfRenderWindow_display(src->help.window);
    }
    sfRenderWindow_destroy(src->help.window);
}

void pop_about(src_t *src)
{
    src->about.window = create_window(400, 100, "About");
    while (sfRenderWindow_isOpen(src->about.window)) {
        while (sfRenderWindow_pollEvent(src->about.window, &src->about.event))
            close_window(src->about.window, src->about.event);
        sfRenderWindow_clear(src->about.window, sfBlack);
        sfRenderWindow_drawText(src->about.window, src->about.text, NULL);
        sfRenderWindow_display(src->about.window);
    }
    sfRenderWindow_destroy(src->about.window);
}
