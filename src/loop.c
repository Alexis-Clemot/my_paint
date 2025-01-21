/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** my_paint
*/

#include "../includes/my_paint.h"

int my_paint(char **env)
{
    src_t src;

    src.env = env;
    init_src(&src);
    while (sfRenderWindow_isOpen(src.window)) {
        while (sfRenderWindow_pollEvent(src.window, &src.event)) {
            manage_event(&src);
        }
        draw_sprite(&src);
        sfRenderWindow_display(src.window);
    }
    destroy_src(&src);
    return 0;
}
