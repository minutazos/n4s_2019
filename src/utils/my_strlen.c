/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** Returns the passed string length
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        ++i;
    return (i);
}
