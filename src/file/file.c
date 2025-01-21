/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** my_paint
*/

#include "../../includes/my_paint.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>

void save_file(src_t *src)
{
    size_t len = 0;
    ssize_t lineSize = 0;

    mini_printf("Enter a file name : ");
    lineSize = getline(&src->file_name, &len, stdin);
    src->file_name[lineSize - 1] = '\0';
    if (src->file_name == NULL)
        return;
    sfImage_saveToFile(src->draw_area.image, src->file_name);
}

void open_file(src_t *src)
{
    size_t len = 0;
    ssize_t lineSize = 0;

    mini_printf("Enter your file name and path : ");
    lineSize = getline(&src->file_name, &len, stdin);
    src->file_name[lineSize - 1] = '\0';
    if (src->file_name[0] == '\0') {
        mini_printf("The file name is empty\n");
        return;
    }
    if (open(src->file_name, O_RDONLY) == -1 ||
        opendir(src->file_name) != NULL) {
        mini_printf("Unable to open the file\n");
        return;
    }
    src->draw_area.image = sfImage_createFromFile(src->file_name);
}
