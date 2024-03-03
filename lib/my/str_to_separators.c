/*
** EPITECH PROJECT, 2024
** str to separator
** File description:
** take a string and separate the segment between the separators
*/

#include <stdlib.h>
#include <stdbool.h>

static bool is_not_a_separator(char character, const char *separators)
{
    for (int i = 0; separators[i] != '\0'; i++)
        if (character == separators[i])
            return false;
    return true;
}

static int get_nb_of_words(char *str, const char *separators)
{
    int counter = 0;

    while (!is_not_a_separator(str[counter], separators) &&
        str[counter] != '\0')
        counter++;
    if (str[counter] == '\0')
        return 0;
    while (is_not_a_separator(str[counter], separators) &&
        str[counter] != '\0')
        counter++;
    return 1 + get_nb_of_words(str + counter, separators);
}

static bool fill_the_array(char **array, char *str, const char *separators)
{
    int nb_of_letters;

    while (!is_not_a_separator(*str, separators) &&
        *str != '\0')
        str++;
    if (*str == '\0') {
        *array = NULL;
        return true;
    }
    for (nb_of_letters = 0; is_not_a_separator(str[nb_of_letters], separators)
        && str[nb_of_letters] != '\0'; nb_of_letters++);
    *array = malloc(sizeof(char) * (nb_of_letters + 1));
    if (*array == NULL)
        return false;
    for (int i = 0; i < nb_of_letters; i++) {
        (*array)[i] = *str;
        str++;
    }
    (*array)[nb_of_letters] = '\0';
    return fill_the_array(array + 1, str, separators);
}

char **str_to_separators(char *str, const char *separators)
{
    int nb_of_words = get_nb_of_words(str, separators);
    char **array;

    array = malloc(sizeof(char *) * (nb_of_words + 1));
    if (array == NULL)
        return NULL;
    if (nb_of_words == 0) {
        array[0] = NULL;
        return array;
    }
    if (!fill_the_array(array, str, separators))
        return NULL;
    return array;
}
