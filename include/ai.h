/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** Header file
*/

#ifndef _AI_H_
#define _AI_H_

#include <unistd.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define READ_SIZE 512
#define FAILURE_STATUS 84
#define OK_STATUS 0

#define ABS(nbr) ((nbr) < 0 ? -(nbr) : (nbr))

typedef struct car_s {
    int *lidar;
    char **last_res;
    int track_cleared;
    double speed;
    double wheels;
    int *initial_pos;
    int status;
    int changes;
} car_t;

int my_strlen(char const *str);
void my_putstr(char const *str, int fd);
int my_getnbr(char *str);
int my_strcmp(char const *s1, char const *s2);
int *get_lidar_info(char *info);
char **exec_command(char *command, int need4return);
void ai(void);
char *my_strcpy(char *dest, char const *src);
char *get_next_line(int fd);
char get_next_char(int fd);
char *re_alloc(char *str, int actual_size);
char *alloc_str(int size);
char **tokenize_string(char *str, char token);
void update_lidar_info(car_t *car);
void charge_info(char **info, car_t *car);
int check_for_errors(char **info);
int check_end_simulation(char **info, int *lidar);
void end_simulation(car_t *car);
car_t *alloc_car_values(void);
car_t *init_car(void);
void check_direction(car_t *car);
void check_speed(car_t *car);

#endif
