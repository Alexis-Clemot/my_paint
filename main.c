/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-mathys.fillion
** File description:
** main
*/

#include "includes/my_paint.h"

static int help(void)
{
    mini_printf("USAGE\n./my_paint\nFor any help concerning the "
    "software use, refer to the help section in the app menu\n");
    return 0;
}

int main(int argc, char **argv, char **env)
{
    if (argc == 1)
        return my_paint(env);
    if (argc == 2 && my_strcmp(argv[1], "-h") == 1)
        return help();
    return 84;
}
