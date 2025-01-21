/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** my_paint
*/

#include "../../includes/my_paint.h"

static button_t create_button(src_t *src, sfVector2f position, sfVector2f size,
    char *str)
{
    button_t button;

    button.rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button.rect, position);
    sfRectangleShape_setSize(button.rect, size);
    sfRectangleShape_setFillColor(button.rect, sfColor_fromRGB(90, 90, 90));
    sfRectangleShape_setOutlineThickness(button.rect, 1);
    sfRectangleShape_setOutlineColor(button.rect, sfBlack);
    button.text = sfText_create();
    sfText_setFont(button.text, src->font);
    sfText_setCharacterSize(button.text, 30);
    sfText_setPosition(button.text,
        (sfVector2f){position.x + 25, position.y + 10});
    sfText_setString(button.text, str);
    sfText_setColor(button.text, sfWhite);
    button.state = NONE;
    return button;
}

static void init_side_menu_button(src_t *src)
{
    src->side_menu.tool_box = create_button(src, (sfVector2f){1440, 108},
        (sfVector2f){480, 90}, "Tool Box");
    src->side_menu.plus = create_button(src, (sfVector2f){1520, 256},
        (sfVector2f){120, 120}, NULL);
    src->side_menu.minus = create_button(src, (sfVector2f){1720, 256},
        (sfVector2f){120, 120}, NULL);
    sfText_setCharacterSize(src->side_menu.tool_box.text, 60);
    sfText_setPosition(src->side_menu.tool_box.text, (sfVector2f){1560, 115});
    src->side_menu.plus_texture = sfTexture_createFromFile("data/plus.png",
        NULL);
    src->side_menu.plus_sprite = sfSprite_create();
    sfSprite_setTexture(src->side_menu.plus_sprite,
        src->side_menu.plus_texture, sfTrue);
    sfSprite_setPosition(src->side_menu.plus_sprite, (sfVector2f){1530, 266});
    src->side_menu.minus_texture = sfTexture_createFromFile("data/minus.png",
        NULL);
    src->side_menu.minus_sprite = sfSprite_create();
    sfSprite_setTexture(src->side_menu.minus_sprite,
        src->side_menu.minus_texture, sfTrue);
    sfSprite_setPosition(src->side_menu.minus_sprite, (sfVector2f){1730, 266});
}

static void init_menu_button(src_t *src)
{
    src->menu.file = create_button(src, (sfVector2f){64, 27},
        (sfVector2f){128, 54}, "File");
    src->menu.edit = create_button(src, (sfVector2f){256, 27},
        (sfVector2f){128, 54}, "Edit");
    src->menu.help = create_button(src, (sfVector2f){448, 27},
        (sfVector2f){128, 54}, "Help");
    src->menu.new_file = create_button(src, (sfVector2f){64, 81},
        (sfVector2f){128, 54}, "New file");
    src->menu.open_file = create_button(src, (sfVector2f){64, 135},
        (sfVector2f){128, 54}, "Open file");
    src->menu.save_file = create_button(src, (sfVector2f){64, 189},
        (sfVector2f){128, 54}, "Save file");
    src->menu.pencil = create_button(src, (sfVector2f){256, 81},
        (sfVector2f){128, 54}, "Pencil");
    src->menu.eraser = create_button(src, (sfVector2f){256, 135},
        (sfVector2f){128, 54}, "Eraser");
    src->menu.about = create_button(src, (sfVector2f){448, 81},
        (sfVector2f){128, 54}, "About");
    src->menu.help_d = create_button(src, (sfVector2f){448, 135},
        (sfVector2f){128, 54}, "Help");
}

static void init_color_rect(src_t *src)
{
    src->side_menu.rect_b = sfRectangleShape_create();
    sfRectangleShape_setPosition(src->side_menu.rect_b,
        (sfVector2f){1552, 800});
    sfRectangleShape_setSize(src->side_menu.rect_b, (sfVector2f){255, 10});
    sfRectangleShape_setFillColor(src->side_menu.rect_b, sfBlue);
    src->side_menu.rect_a = sfRectangleShape_create();
    sfRectangleShape_setPosition(src->side_menu.rect_a,
        (sfVector2f){1552, 900});
    sfRectangleShape_setSize(src->side_menu.rect_a, (sfVector2f){255, 10});
    sfRectangleShape_setFillColor(src->side_menu.rect_a,
        sfColor_fromRGB(100, 100, 100));
    src->side_menu.preview = sfRectangleShape_create();
    sfRectangleShape_setPosition(src->side_menu.preview,
        (sfVector2f){1630, 435});
    sfRectangleShape_setSize(src->side_menu.preview, (sfVector2f){100, 100});
}

static void init_color(src_t *src)
{
    src->side_menu.red = create_button(src, (sfVector2f){1542, 580},
        (sfVector2f){20, 50}, NULL);
    src->side_menu.green = create_button(src, (sfVector2f){1542, 680},
        (sfVector2f){20, 50}, NULL);
    src->side_menu.blue = create_button(src, (sfVector2f){1542, 780},
        (sfVector2f){20, 50}, NULL);
    src->side_menu.alpha = create_button(src, (sfVector2f){1797, 880},
        (sfVector2f){20, 50}, NULL);
    src->side_menu.rect_r = sfRectangleShape_create();
    sfRectangleShape_setPosition(src->side_menu.rect_r,
        (sfVector2f){1552, 600});
    sfRectangleShape_setSize(src->side_menu.rect_r, (sfVector2f){255, 10});
    sfRectangleShape_setFillColor(src->side_menu.rect_r, sfRed);
    src->side_menu.rect_g = sfRectangleShape_create();
    sfRectangleShape_setPosition(src->side_menu.rect_g,
        (sfVector2f){1552, 700});
    sfRectangleShape_setSize(src->side_menu.rect_g, (sfVector2f){255, 10});
    sfRectangleShape_setFillColor(src->side_menu.rect_g, sfGreen);
    init_color_rect(src);
}

void init_menu(src_t *src)
{
    src->menu.rect = sfRectangleShape_create();
    sfRectangleShape_setSize(src->menu.rect, (sfVector2f){1920, 108});
    sfRectangleShape_setFillColor(src->menu.rect,
        sfColor_fromRGB(140, 140, 140));
    src->side_menu.rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(src->side_menu.rect, (sfVector2f){1440, 0});
    sfRectangleShape_setSize(src->side_menu.rect, (sfVector2f){480, 1080});
    sfRectangleShape_setFillColor(src->side_menu.rect,
        sfColor_fromRGB(210, 210, 210));
    init_menu_button(src);
    init_side_menu_button(src);
    sfText_setPosition(src->menu.new_file.text, (sfVector2f){74, 91});
    sfText_setPosition(src->menu.open_file.text, (sfVector2f){74, 145});
    sfText_setPosition(src->menu.save_file.text, (sfVector2f){74, 199});
    init_color(src);
}
