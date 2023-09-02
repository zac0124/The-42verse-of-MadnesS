/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhjargal <zmunkhjargal@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:53:39 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/09/02 17:13:08 by zmunkhjarga      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>


typedef struct s_philo
{
    struct s_general *data;
    pthread_t thread_1;
    int id;
    int eat_count;
    int status;
    int eating;
    uint64_t time_to_die;
    pthread_mutex_t lock;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
} t_philo;



typedef struct s_general
{
    pthread_t *thread_id;
    int     number_of_philo;
    int     number_of_meals;
    int     philo_dead;
    int     finished;
    t_philo *philos;
    u_int64_t     time_to_die;
    u_int64_t     time_to_eat;
    u_int64_t     time_to_sleep;
    u_int64_t     start_time;
    pthread_mutex_t     *forks;
    pthread_mutex_t     lock;
    pthread_mutex_t     write;

} t_general;

u_int64_t   get_time(void);
void    messages(char *str, t_philo *philo);
void    eat(t_philo *philo);
void    *routine(void *pointer);
void destroy_mutex(t_general *data);
long    ft_atoi(const char *str);
int input_checker(char  **argv);
int ft_usleep(useconds_t time);
int ft_strcmp(char *s1, char *s2);
int	init(t_general **data, char **argv, int argc);
int thread_init(t_general *data);
int first_case(t_general *data);
int print_error(char *str, t_general *data);
int main(int argc, char **argv);

#endif
