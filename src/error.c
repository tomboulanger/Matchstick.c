/*
** EPITECH PROJECT, 2021
** error.c
** File description:
** error
*/

#include "../my.h"

void error_player_one_line(v_var *a, char **map)
{
    while (1) {
        if (a->status_error == 0)
            check_line(a);
        if (a->line == 1488)
            break;
        if (a->status_error == 1)
            check_sticks(a, map);
        if (a->nb_sticks == 1488)
            break;
        if (a->status_error == 3) {
            a->status_error = 0;
            break;
        }
    }
}

void check_sticks2(v_var *a, char **map)
{
    int lenght = (a->arg * 2) - 1;
    int sticks = 0;

    while (lenght > 0) {
        if (map[a->line][lenght] == '|')
            sticks++;
        lenght--;
    }
    if (a->nb_sticks > sticks && a->nb_sticks < a->arg2) {
        my_putstr("Error: not enough matches on this line\n");
        a->status_error = 0;
    }
    if (a->nb_sticks > a->arg2) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(a->arg2);
        my_putstr(" matches per turn\n");
        a->status_error = 0;
    }
    if (a->nb_sticks > 0 && a->nb_sticks <= sticks && a->nb_sticks <= a->arg2)
        a->status_error = 3;
}

int check_sticks(v_var *a, char **map)
{
    int lenght = (a->arg * 2) - 1;
    int sticks = 0;

    for (lenght; lenght > 0; lenght--)
        if (map[a->line][lenght] == '|')
            sticks++;
    my_putstr("Matches: ");
    a->nb_sticks = my_getline(a);
    if (a->nb_sticks == 1488)
        return (44);
    if (a->nb_sticks <= 0 && a->error_line == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        a->status_error = 0;
    }
    if (a->error_line == 1) {
        my_putstr("Error: invalid input (positive number expected)\n");
        a->status_error = 0;
    }
    check_sticks2(a, map);
    return (0);
}

void check_line(v_var *a)
{
    while (1) {
        my_putstr("Line: ");
        a->line = my_getline(a);
        if (a->line == 1488)
            break;
        if (a->error_line == 1)
            my_putstr("Error: invalid input (positive number expected)\n");
        if ((a->line < 1 || a->line > a->arg) && a->error_line == 0)
            my_putstr("Error: this line is out of range\n");
        else if (a->line >= 1 && a->line <= a->arg && a->error_line == 0) {
            a->status_error = 1;
            break;
        }
    }
}
