/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** Mini version of printf
*/

#include "../includes/my_paint.h"

void find_flag(const char *format, int i, va_list list)
{
    if (format[i] == 'c') {
        my_putchar(va_arg(list, int));
    }
    if (format[i] == 's') {
        my_putstr(va_arg(list, char *));
    }
    if (format[i] == 'i' ||
        format[i] == 'd') {
        my_put_nbr(va_arg(list, int));
    }
    if (format[i] == '%') {
        my_putchar('%');
    }
}

void mini_printf(const char *format, ...)
{
    va_list list;
    int i = 0;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            find_flag(format, (i + 1), list);
            i += 2;
        } else {
            my_putchar(format[i]);
            i++;
        }
    }
    va_end(list);
}
