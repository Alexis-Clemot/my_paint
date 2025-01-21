/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** Display all the possible values of an int
*/

#include "../includes/my_paint.h"

int my_int_len(int nb)
{
    int len = 0;

    if (nb == 0) {
        return (1);
    }
    while (nb != 0) {
        nb /= 10;
        len += 1;
    }
    return (len);
}

void my_put_nbr(int nb)
{
    int divided = 1;
    int result_nb = 0;

    if (nb < 0) {
        if (nb == -2147483648) {
            my_put_nbr(-214748364);
            my_putchar('8');
            return;
        }
        nb = -nb;
        my_putchar('-');
    }
    for (int i = 0; i < (my_int_len(nb) - 1); i++)
        divided = divided * 10;
    for (int j = 0; j < my_int_len(nb); j++) {
        result_nb = (nb / divided) % 10;
        divided = divided / 10;
        my_putchar(result_nb + 48);
    }
}
