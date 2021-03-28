/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#ifndef my_h

#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

typedef struct v_variable
{
    int status;
    int arg;
    int lenght;
    int height;
    int victory;
    int m;
    int put_stick;
    int nb_spaces;
    int stick;
    int lines;
    int game;
    int arg2;
    int line;
    int error_line;
    int get;
    int nb_sticks;
    int player;
    int status_error;
    int sticks;
    int ia;

}v_var;

void my_putchar(char c);
int my_getnbr(char const *str);
void ia_game2(v_var *a);
int error_argument(v_var *a, char **av, int ac);
void player_one(v_var *a, char **map);
void stick2(v_var *a, char **map);
void check_line(v_var *a);
void check_sticks2(v_var *a, char **map);
void check_sticks(v_var *a, char **map);
int player_two(v_var *a, char **map);
void error_player_one_line(v_var *a, char **map);
void error_player_sticks(v_var *a, char **map);
int victory(v_var *a, char **map);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int *nb_stick(v_var *a);
int victory_ia(v_var *a, char **map);
void print(char **map, v_var *a);
char **game_map_ia(v_var *a, char **map);
int my_getline(v_var *a);
void main2(v_var *a, char **map);
void init_struct(v_var *a, char **av);
char **stick(v_var *a, char **map, char **av);
char **game_map(v_var *a, char **map);
char **matchstick(v_var *a, char **av);
char **ia_game(v_var *a, char **map);

#endif
