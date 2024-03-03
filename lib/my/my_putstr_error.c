/*
** EPITECH PROJECT, 2024
** putstr error
** File description:
** put error
*/

#include <unistd.h>

static int my_strlen(const char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return i;
}

void my_putstr_error(const char *str)
{
    write(2, str, my_strlen(str));
}
