/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** Header for my_paint programm
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdarg.h>

#ifndef MY_PAINT_H_
    #define MY_PAINT_H_
    #define NONE 0
    #define HOVER 1
    #define PRESSED 2
    #define CLICKED 3

typedef struct about_s {
    sfRenderWindow *window;
    sfEvent event;
    sfText *text;
} about_t;

typedef struct help_s {
    sfRenderWindow *window;
    sfEvent event;
    sfText *text;
} help_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfText *text;
    int state;
} button_t;

typedef struct menu_s {
    sfRectangleShape *rect;
    button_t file;
    button_t edit;
    button_t help;
    button_t new_file;
    button_t open_file;
    button_t save_file;
    button_t pencil;
    button_t eraser;
    button_t about;
    button_t help_d;
} menu_t;

typedef struct side_menu_s {
    sfRectangleShape *rect;
    sfRectangleShape *rect_r;
    sfRectangleShape *rect_g;
    sfRectangleShape *rect_b;
    sfRectangleShape *rect_a;
    sfRectangleShape *preview;
    button_t tool_box;
    button_t plus;
    button_t minus;
    button_t red;
    button_t green;
    button_t blue;
    button_t alpha;
    sfTexture *plus_texture;
    sfSprite *plus_sprite;
    sfTexture *minus_texture;
    sfSprite *minus_sprite;
} side_menu_t;

typedef struct draw_area_s {
    sfImage *image;
    sfTexture *pixel_array;
    sfSprite *sprite_pixel_array;
    sfColor color;
    int size;
} draw_area_t;

typedef struct src_s {
    sfRenderWindow *window;
    sfEvent event;
    sfFont *font;
    menu_t menu;
    side_menu_t side_menu;
    draw_area_t draw_area;
    about_t about;
    help_t help;
    char **env;
    char *file_name;
} src_t;

void find_flag(const char *format, int i, va_list list);
void mini_printf(const char *format, ...);
void my_putchar(char c);
void my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);

int my_paint(char **env);
void init_src(src_t *src);
void init_menu(src_t *src);
sfTexture *set_pixel_array(src_t *src);
void manage_event(src_t *src);
void check_hover(src_t *src);
void check_pressed(src_t *src);
void check_clicked(src_t *src);
void close_window(sfRenderWindow *window, sfEvent event);
void pop_about(src_t *src);
void pop_help(src_t *src);
void open_file(src_t *src);
void save_file(src_t *src);
void draw_sprite(src_t *src);
void draw_menu(src_t *src);
void destroy_src(src_t *src);

#endif /* MY_PAINT_H_ */
