/*
** EPITECH PROJECT, 2021
** victory.c
** File description:
** victory
*/

#include "../my.h"

int victory(v_var *a, char **map)
{
    int i = 0;
    int y = 0;
    int lenght = (a->arg * 2) - 1;
    int sticks = 0;
    while (i <= a->arg) {
        while (y < lenght) {
            if (map[i][y] == '|')
                sticks++;
        y++;
        }
    i++;
    y = 0;
    }
    if (sticks == 0) {
        a->victory = 2;
        my_putstr("You lost, too bad...\n");
        a->game = 1;
    }
    return (0);
}

int victory_ia(v_var *a, char **map)
{
    int i = 0;
    int y = 0;
    int lenght = (a->arg * 2) - 1;
    int sticks = 0;
    while (i <= a->arg) {
        while (y < lenght) {
            if (map[i][y] == '|')
                sticks++;
        y++;
        }
    i++;
    y = 0;
    }
    if (sticks == 0) {
        a->victory = 1;
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        a->game = 1;
    }
    return (0);
}

