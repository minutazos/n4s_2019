/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** The AI core
*/

#include "../include/ai.h"

void update_status(char **info, car_t *car)
{
    car->status = check_for_errors(info);
    if (car->status == OK_STATUS) {
        charge_info(info, car);
        update_lidar_info(car);
        check_speed(car);
        if (check_end_simulation(car->last_res, car->lidar) == TRUE)
            end_simulation(car);
        check_direction(car);
    }
}

void send_new_status(car_t *car)
{
    if (car->changes == TRUE) {
        send_direction(car);
        send_speed(car);
        car->changes = FALSE;
    }
}

void ai(void)
{
    char **res;
    car_t *car = init_car();

    while (car->track_cleared == FALSE) {
        res = exec_command("GET_INFO_LIDAR\n", TRUE);
        update_status(res, car);
        send_new_status(car);
        sleep(0.001);
    }
}
