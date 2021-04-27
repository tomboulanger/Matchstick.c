/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "../my.h"

int main(int ac, char **av)
{
    v_var *a = malloc(sizeof(v_var));
    char **map;

    if (error_argument(a, av, ac) == 84)
        return (84);
    init_struct(a, av);
    map = matchstick(a, av);
    print(map, a);
    if (main2(a, map) == 44)
        return (0);
    if (a->victory == 1)
        return (1);
    if (a->victory == 2)
        return (2);
    free(map);
    free(a);
}

int player_one(v_var *a, char **map)
{
    my_putchar('\n');
    my_putstr("Your turn:\n");
    error_player_one_line(a, map);
    if (a->line == 1488)
        return (44);
    if (a->nb_sticks == 1488)
        return (44);
    my_putstr("Player removed ");
    my_put_nbr(a->nb_sticks);
    my_putstr(" match(es) from line ");
    my_put_nbr(a->line);
    my_putchar('\n');
    return (0);
}

int player_two(v_var *a, char **map)
{
    ia_game(a, map);
    my_putchar('\n');
    my_putstr("AI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr(a->nb_sticks);
    my_putstr(" match(es) from line ");
    my_put_nbr(a->line);
    my_putchar('\n');
}

char **ia_game(v_var *a, char **map)
{
    int lenght = (a->arg * 2) - 1;
    a->sticks = 0;
    a->line = rand() % a->arg + 1;
    while (a->ia == 0) {
        for (lenght; lenght > 0; lenght--) {
            if (map[a->line][lenght] == '|') {
                a->sticks++;
            }
        }
        if (a->sticks == 0) {
            lenght = (a->arg * 2) - 1;
            a->line = rand() % a->arg + 1;
        }
        if (a->sticks != 0)
            a->ia = 1;
    }
    ia_game2(a);
}

void ia_game2(v_var *a)
{
    a->ia = 0;
    while (1) {
        a->nb_sticks = rand() % a->sticks + 1;
        if (a->nb_sticks <= a->arg2)
            break;
    }
}