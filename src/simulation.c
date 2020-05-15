/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** Simulation end related funcs
*/

#include "../include/ai.h"

int check_for_errors(char **info)
{
    char *id;

    if (info == NULL)
        return (FAILURE_STATUS);
    id = info[0];
    if (my_strcmp(id, "1") != 0 && my_strcmp(id, "2") != 0 &&
        my_strcmp(id, "20") != 0)
        return (FAILURE_STATUS);
    return (OK_STATUS);
}

int check_end_simulation(char **info, int *lidar)
{
    if (info[35] && my_strcmp(info[35], "Track Cleared") == 0)
        return (TRUE);
    else {
        for (int i = 0; i < 32; ++i) {
            if (lidar[i] < 20)
                return (TRUE);
        }
    }
    return (FALSE);
}

void end_simulation(car_t *car)
{
    car->track_cleared = TRUE;
    exec_command("CAR_FORWARD:0\n", FALSE);
    car->speed = 0;
    car->changes = TRUE;
}
