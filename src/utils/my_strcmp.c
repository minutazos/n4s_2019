/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strcmp.c
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1 , char const *s2)
{
    int i;

    for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++) {
    }
    if (i == my_strlen(s1) && i == my_strlen(s2)) {
        return (0);
    } else {
        return (s1[i] - s2[i]);
    }
}