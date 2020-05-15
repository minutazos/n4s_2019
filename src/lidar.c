/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** LIDAR related funcs
*/

#include "../include/ai.h"

void update_lidar_info(car_t *car)
{
    int i = 0;

    if (car->lidar == NULL)
        return;
    if (my_strcmp(car->last_res[0], "1") == 0) {
        for (i = 0; i < 32; ++i)
            car->lidar[i] = my_getnbr(car->last_res[i + 3]);
        car->lidar[i] = NULL;
    } else {
        car->lidar = NULL;
        car->status = FAILURE_STATUS;
    }
}

void charge_info(char **info, car_t *car)
{
    for (int i = 0; car->last_res[i]; ++i)
        free(car->last_res[i]);
    free(car->last_res);
    car->last_res = info;
}
