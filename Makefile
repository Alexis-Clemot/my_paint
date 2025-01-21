##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for program compilation
##

.PHONY: all clean fclean re unit_tests tests_run

NAME =	my_paint

SRC	=	src/loop.c					\
		src/src/src.c				\
		src/src/src_menu.c			\
		src/src/destroy.c			\
		src/event/event.c			\
		src/event/hover.c			\
		src/event/pressed.c			\
		src/event/clicked.c			\
		src/pop_up/pop_up.c			\
		src/file/file.c				\
		src/draw/draw.c				\
		src/draw/draw_menu.c		\
		lib/mini_printf.c			\
		lib/my_putchar.c			\
		lib/my_putstr.c				\
		lib/my_put_nbr.c			\
		lib/my_strcmp.c				\

TEST_FILES	=	tests/test_my_paint.c

CFLAGS	=	-Werror -Wall -Wextra

all: 	$(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC) -l csfml-system -l csfml-graphics \
		-l csfml-audio -l csfml-window main.c

clean:
	rm -f $(NAME)

fclean: clean
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit_tests

re: fclean all

unit_tests: fclean
	gcc -o unit_tests $(SRC) $(TEST_FILES) -l csfml-system \
	-l csfml-graphics -l csfml-audio -l csfml-window --coverage -lcriterion

tests_run: unit_tests
	./unit_tests
	gcovr --exclude tests/
