/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** Compare two string and return a int indicating the result
*/

#include "../includes/my_paint.h"
#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

int my_strcmp(char const *s1, char const *s2)
{
    int s1_len = my_strlen(s1);
    int s2_len = my_strlen(s2);

    if (s1_len != s2_len)
        return 0;
    for (int i = 0; i < s1_len; i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}
