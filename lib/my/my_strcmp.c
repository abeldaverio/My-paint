/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** compare 2 strings
*/

int my_strcmp(char *str_1, char *str_2)
{
    for (int i = 0; str_1[i] != '\0' || str_2[i] != '\0'; i++)
        if (str_1[i] != str_2[i])
            return 0;
    return 1;
}
