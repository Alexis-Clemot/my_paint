/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** my_paint
*/

#include "../../includes/my_paint.h"
#include <stdlib.h>

static sfRenderWindow *create_window(unsigned int width, unsigned int height,
    char *name)
{
    sfRenderWindow *win;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    win = sfRenderWindow_create(video_mode, name, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(win, 180);
    return win;
}

sfTexture *set_pixel_array(src_t *src)
{
    sfTexture *texture;
    sfUint8 pixels[5598720];

    src->draw_area.image = sfImage_createFromPixels(1440, 972, pixels);
    for (unsigned int i = 0; i < 1440; i++) {
        for (unsigned int j = 0; j < 972; j++) {
            sfImage_setPixel(src->draw_area.image, i, j, sfWhite);
        }
    }
    texture = sfTexture_createFromImage(src->draw_area.image, NULL);
    src->draw_area.sprite_pixel_array = sfSprite_create();
    sfSprite_setTexture(src->draw_area.sprite_pixel_array, texture, sfTrue);
    sfSprite_setPosition(src->draw_area.sprite_pixel_array,
        (sfVector2f){0, 108});
    return texture;
}

static void set_help(src_t *src)
{
    src->help.text = sfText_create();
    sfText_setFont(src->help.text, src->font);
    sfText_setCharacterSize(src->help.text, 30);
    sfText_setString(src->help.text, "FILE\nNew file : start a new drawing\nOp"
    "en file : open an existing drawing\nSave file : save the actual drawing\n"
    "\nEDIT\nPencil : select this option to draw\nEraser : select this option "
    "to erase\n\nHELP\nHelp : show this window\nAbout : show the username\n");
    sfText_setColor(src->help.text, sfWhite);
}

static void set_about(src_t *src)
{
    char *username = NULL;
    int i = 0;
    int k = 0;

    for (i; src->env[i] != NULL; i++) {
        if (src->env[i][0] == 'U' && src->env[i][1] == 'S' &&
            src->env[i][2] == 'E' && src->env[i][3] == 'R')
            break;
    }
    if (i != 0) {
        username = malloc((my_strlen(src->env[i]) - 8) * sizeof(char));
        for (int j = 9; src->env[i][j] != '\0'; j++) {
            username[k] = src->env[i][j];
            k++;
        }
        username[k] = '\0';
    }
    sfText_setCharacterSize(src->about.text, 30);
    sfText_setString(src->about.text, username);
    sfText_setColor(src->about.text, sfWhite);
}

void init_src(src_t *src)
{
    src->window = create_window(1920, 1080, "my_paint");
    src->font = sfFont_createFromFile("data/font.otf");
    src->draw_area.pixel_array = set_pixel_array(src);
    src->about.text = sfText_create();
    src->draw_area.size = 1;
    sfText_setFont(src->about.text, src->font);
    set_about(src);
    set_help(src);
    init_menu(src);
}
