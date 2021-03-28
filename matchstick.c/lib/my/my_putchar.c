/*
** EPITECH PROJECT, 2020
** my_putchar.C
** File description:
** my_putchar.c
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
