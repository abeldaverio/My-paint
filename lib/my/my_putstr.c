/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include <unistd.h>

static size_t my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
