/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** Enter point
*/

#include "../include/ai.h"

int main(int argc, char **argv)
{
    exec_command("START_SIMULATION\n", FALSE);
    ai();
    sleep(1);
    exec_command("STOP_SIMULATION\n", FALSE);
    return (EXIT_FAILURE);
}
