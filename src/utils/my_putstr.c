/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** Print string into the passed file descriptor
*/

#include "../../include/ai.h"

void my_putstr(char const *str, int fd)
{
    write(fd, str, my_strlen(str));
}
