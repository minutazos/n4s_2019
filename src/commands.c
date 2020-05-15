/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** Coppelia commands related funcs
*/

#include "../include/ai.h"

void send_speed(car_t *car)
{
    if (car->speed >= 1)
        exec_command("CAR_FORWARD:1\n", FALSE);
    else if (car->speed >= 0.6)
        exec_command("CAR_FORWARD:0.6\n", FALSE);
    else if (car->speed >= 0.3)
        exec_command("CAR_FORWARD:0.3\n", FALSE);
    else if (car->speed >= 0.2)
        exec_command("CAR_FORWARD:0.2\n", FALSE);
    else if (car->speed >= 0.1)
        exec_command("CAR_FORWARD:0.1\n", FALSE);
    else
        exec_command("CAR_FORWARD:0\n", FALSE);
}

void send_negative_direction(double dir)
{
    if (dir == -0.02)
        exec_command("WHEELS_DIR:-0.02\n", FALSE);
    else if (dir == -0.05)
        exec_command("WHEELS_DIR:-0.05\n", FALSE);
    else if (dir == -0.1)
        exec_command("WHEELS_DIR:-0.1\n", FALSE);
    else if (dir == -0.25)
        exec_command("WHEELS_DIR:-0.25\n", FALSE);
    else if (dir == -0.5)
        exec_command("WHEELS_DIR:-0.5\n", FALSE);
}

void send_positive_direction(double dir)
{
    if (dir == 0.02)
        exec_command("WHEELS_DIR:0.02\n", FALSE);
    else if (dir == 0.05)
        exec_command("WHEELS_DIR:0.05\n", FALSE);
    else if (dir == 0.1)
        exec_command("WHEELS_DIR:0.1\n", FALSE);
    else if (dir == 0.25)
        exec_command("WHEELS_DIR:0.25\n", FALSE);
    else if (dir == 0.5)
        exec_command("WHEELS_DIR:0.5\n", FALSE);
}

void send_direction(car_t *car)
{
    if (car->wheels < 0) {
        send_negative_direction(car->wheels);
    }
    else if (car->wheels == 0)
        exec_command("WHEELS_DIR:0\n", FALSE);
    else {
        send_positive_direction(car->wheels);
    }
}

char **exec_command(char *command, int need4return)
{
    char *res;

    my_putstr(command, STDOUT_FILENO);
    res = get_next_line(STDIN_FILENO);
    if (res == NULL)
        return (NULL);
    if (need4return == TRUE)
        return (tokenize_string(res, ':'));
    free(res);
    return (NULL);
}
