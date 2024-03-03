/*
** EPITECH PROJECT, 2024
** str to int
** File description:
** convert a number string into a int
*/

#include <stdbool.h>

static int my_strlen(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return i;
}

int str_to_int(char *str)
{
    bool negative = false;
    int len;
    int nb = 0;

    if (str[0] == '-') {
        negative = true;
        str++;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        nb *= 10;
        nb += str[i] - '0';
    }
    return (negative) ? -nb : nb;
}
