/*
** EPITECH PROJECT, 2021
** map.c
** File description:
** map
*/

#include "../my.h"

char **game_map(v_var *a, char **map)
{
    int lenght = (a->arg * 2) - 1;
    int x_max = (a->arg * 2) - 1;
    int nb_spaces = 0;
    int matches;

    while (a->status == 0) {
        if (map[a->line][lenght] == ' ') {
            nb_spaces++;
            lenght--;
        }
        else if (map[a->line][lenght] != ' ')
            a->status = 1;
    }
    for (matches = 0; matches < a->nb_sticks; matches++) {
        map[a->line][x_max - nb_spaces] = ' ';
        x_max--;
    }
    a->status = 0;
    return (map);
}

char **game_map_ia(v_var *a, char **map)
{
    int lenght = (a->arg * 2) - 1;
    int x_max = (a->arg * 2) - 1;
    int nb_spaces = 0;
    int matches = 0;

    player_two(a, map);
    while (a->status == 0) {
        if (map[a->line][lenght] == ' ') {
            nb_spaces++;
            lenght--;
        }
        else if (map[a->line][lenght] != ' ')
            a->status = 1;
    }
    for (matches = 0; matches < a->nb_sticks; matches++) {
        map[a->line][x_max - nb_spaces] = ' ';
        x_max--;
    }
    a->status = 0;
    return (map);
}

char **matchstick(v_var *a, char **av)
{
    int i = 0;
    int p;
    char **map;
    map = malloc(sizeof(char *) *a->height);

    for (i = 0; i != a->height; i++)
        map[i] = malloc(sizeof(char *) *a->lenght);
    for (i = 0; i < a->height; i++)
        for (p = 0; p <= a->lenght; p++)
            map[i][p] = ' ';
    for (i = 0; i < a->height; i++) {
        map[i][0] = '*';
        map[i][a->lenght] = '*';
    }
    for (i = 0; i < a->lenght; i++) {
        map[0][i] = '*';
        map[a->height - 1][i] = '*';
    }
    stick(a, map, av);
    return (map);
}

char **stick(v_var *a, char **map, char **av)
{
    int nb_sticks = (a->arg * 2) - 1;
    int f;
    int e;
    a->lines = 1;

    for (f = 1; f <= nb_sticks; f++)
        map[a->arg][f] = '|';
    for (e = 0; e < a->arg - 1; e++) {
        for (f = 0; f < a->nb_spaces; f++) {
            map[a->lines][a->m] = ' ';
            a->m++;
        }
        for (f = 0; f < a->put_stick; f++) {
            map[a->lines][a->m] = '|';
            a->m++;
        }
        stick2(a, map);
    }
}

void stick2(v_var *a, char **map)
{
    int f;

    for (f = 0; f < a->nb_spaces; f++) {
        map[a->lines][a->m] = ' ';
        a->m++;
    }
    a->nb_spaces--;
    a->lines++;
    a->put_stick += 2;
    a->m = 1;
}