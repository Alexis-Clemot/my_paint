/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** Display the characters of a string
*/

#include "../includes/my_paint.h"

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
