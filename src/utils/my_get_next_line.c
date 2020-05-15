/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** get_next_line
*/

#include "../../include/ai.h"

char *alloc_str(int size)
{
    char *new_str = malloc(sizeof(char) * size);

    if (new_str == NULL)
        return (NULL);
    for (int i = 0; i < size; ++i)
        new_str[i] = '\0';
    return (new_str);
}

char *re_alloc(char *str, int actual_size)
{
    char *new_str = malloc(sizeof(char)*(actual_size + READ_SIZE));

    if (new_str == NULL)
        return (NULL);
    my_strcpy(new_str, str);
    free(str);
    return (new_str);
}

char get_next_char(int fd)
{
    static char buffer[READ_SIZE];
    static int index = -1;
    static int read_size = 0;

    ++index;
    read_size = read(fd, &buffer, 1);
    if (read_size == 0 && index == READ_SIZE) {
        read_size = read(fd, &buffer, 1);
        index = -1;
    } else if (read_size < 0) {
        return (-1);
    }
    return (buffer[0]);
}

char *get_next_line(int fd)
{
    char *str = alloc_str(READ_SIZE);
    int actual_size = READ_SIZE;
    char actual_char = 2;
    int i = 0;

    while (actual_char != -1 && actual_char != '\0' && actual_char != '\n') {
        if (i >= actual_size && my_strlen(str) == actual_size)
            str = re_alloc(str, ++actual_size);
        actual_char = get_next_char(fd);
        str[i] = actual_char;
        ++i;
    }
    return (str);
}
