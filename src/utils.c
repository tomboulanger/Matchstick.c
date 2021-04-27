/*
** EPITECH PROJECT, 2021
** utils.c
** File description:
** utils
*/

#include "../my.h"

void init_struct(v_var *a, char **av)
{
    a->arg = my_getnbr(av[1]);
    a->arg2 = my_getnbr(av[2]);
    a->height = a->arg + 2;
    a->game = 0;
    a->lenght = (a->arg * 2);
    a->status = 0;
    a->lines = my_getnbr(av[1]);
    a->player = 0;
    a->ia = 0;
    a->status_error = 0;
    a->victory = 0;
    a->put_stick = 1;
    a->nb_spaces = (a->lenght - 2) / 2;
    a->sticks = 0;
    a->m = 1;
    a->error_line = 0;
}

void print(char **map, v_var *a)
{
    for (int i = 0; i < a->arg + 2; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
}

int my_getline(v_var *a)
{
    char *str = NULL;
    size_t len = 255;
    int value;
    int read;
    int i = 0;

    read = getline(&str, &len, stdin);
    if (read == -1)
        return (1488);
    if (str[i] < '0' || str[i] > '9')
        a->error_line = 1;
    else
        a->error_line = 0;
    value = my_getnbr(str);
    return (value);
}

int main2(v_var *a, char **map)
{
    while (a->game == 0) {
        if (player_one(a, map) == 44)
            return (44);
        map = game_map(a, map);
        print(map, a);
        victory(a, map);
        if (a->victory == 2)
            break;
        map = game_map_ia(a, map);
        print(map, a);
        victory_ia(a, map);
        if (a->victory == 1)
            break;
    }
    return (0);
}

int error_argument(v_var *a, char **av, int ac)
{
    int c;
    int b;

    if (ac != 3) {
        my_putstr("Invalid number of arguments.\n");
        return (84);
    }
    c = my_getnbr(av[1]);
    b = my_getnbr(av[2]);
    if (c < 1 || c > 99 || b < 1) {
        my_putstr("Invalid lines or matches number.\n");
        return (84);
    }
}
