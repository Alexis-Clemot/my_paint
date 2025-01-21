/*
** EPITECH PROJECT, 2024
** test_asm
** File description:
** Test file for asm
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/my_paint.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(mini_printf, simple_string1, .init = redirect_all_std)
{
    mini_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(mini_printf, simple_string2, .init = redirect_all_std)
{
    mini_printf("%s", "hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(mini_printf, simple_number1, .init = redirect_all_std)
{
    mini_printf("%i", 42);
    cr_assert_stdout_eq_str("42");
}

Test(mini_printf, simple_number2, .init = redirect_all_std)
{
    mini_printf("%d", 0);
    cr_assert_stdout_eq_str("0");
}

Test(mini_printf, max_number, .init = redirect_all_std)
{
    mini_printf("%d", -2147483648);
    cr_assert_stdout_eq_str("-2147483648");
}

Test(mini_printf, simple_character, .init = redirect_all_std)
{
    mini_printf("%c", '@');
    cr_assert_stdout_eq_str("@");
}

Test(mini_printf, simple_percentage, .init = redirect_all_std)
{
    mini_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_strcmp, same_str, .init = redirect_all_std)
{
    mini_printf("%i", my_strcmp("test", "test"));
    cr_assert_stdout_eq_str("1");
}

Test(my_strcmp, almost_same_str, .init = redirect_all_std)
{
    mini_printf("%i", my_strcmp("test", "tset"));
    cr_assert_stdout_eq_str("0");
}

Test(my_strcmp, not_same_str, .init = redirect_all_std)
{
    mini_printf("%i", my_strcmp("hi", "world"));
    cr_assert_stdout_eq_str("0");
}

Test(my_strcmp, empty_str, .init = redirect_all_std)
{
    mini_printf("%i", my_strcmp(NULL, NULL));
    cr_assert_stdout_eq_str("1");
}