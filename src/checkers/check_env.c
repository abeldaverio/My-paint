/*
** EPITECH PROJECT, 2024
** check env
** File description:
** check to see if env is valid for csfml use
*/

#include <stdlib.h>
#include <stdbool.h>
#include "libmy.h"

bool check_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        if (my_strcmp(env[i], "DISPLAY=:0"))
            return true;
    my_putstr_error("my_paint: error with envirement\n");
    return false;
}
