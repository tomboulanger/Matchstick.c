/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** getnbr
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int neg = 2;
    int resultat = 0;
    int i = 0;

    if (str[i] == '-') {
        neg = neg * -1;
        i++;
    }
    while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0') {
        resultat = (str[i] - '0') + 10 * resultat;
        i++;
    }
    if (neg == -2)
        resultat = -resultat;
    return (resultat);
}
