/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** Simulation end related funcs
*/

#include "../include/ai.h"

double get_new_dir(int dist)
{
    double new_dir = 0;

    if (dist > 1200)
        new_dir = 0.02;
    else if (dist > 800)
        new_dir = 0.05;
    else if (dist > 500)
        new_dir = 0.1;
    else if (dist > 250)
        new_dir = 0.25;
    else if (dist > 0)
        new_dir = 0.5;
    return (new_dir);
}

void check_direction(car_t *car)
{
    double new_dir = 0;
    double relation = car->lidar[0] - car->lidar[31];

    if (relation < 0) {
        new_dir = get_new_dir(car->lidar[14]);
        new_dir *= -1;
    }
    else if (relation > 0) {
        new_dir = get_new_dir(car->lidar[16]);
    }
    if (new_dir != car->wheels) {
        car->wheels = new_dir;
        car->changes = TRUE;
    }
}

void check_speed(car_t *car)
{
    float new_speed = 0.1;

    if (car->lidar[15] >= 2000)
        new_speed = 1;
    else if(car->lidar[15] >= 1200)
        new_speed = 0.8;
    else if (car->lidar[15] >= 675)
        new_speed = 0.4;
    else if (car->lidar[15] >= 400)
        new_speed = 0.28;
    else if (car->lidar[15] >= 200)
        new_speed = 0.2;
    else
        new_speed = 0.1;
    if (new_speed != car->speed) {
        car->speed = new_speed;
        car->changes = TRUE;
    }
}

car_t *alloc_car_values(void)
{
    car_t *car = malloc(sizeof(car_t));

    if (car == NULL)
        return (NULL);
    car->lidar = malloc(sizeof(int) * 32);
    if (car->lidar == NULL) {
        free(car);
        return (NULL);
    }
    car->last_res = malloc(sizeof(char *));
    if (car->last_res == NULL) {
        free (car->lidar);
        free(car);
        return (NULL);
    }
    return (car);
}

car_t *init_car(void)
{
    car_t *car = alloc_car_values();

    car->track_cleared = FALSE;
    car->speed = 0;
    car->wheels = 0;
    car->status = TRUE;
    car->changes = FALSE;
    exec_command("WHEELS_DIR:0\n", FALSE);
    exec_command("CAR_FORWARD:1\n", FALSE);
    return (car);
}
