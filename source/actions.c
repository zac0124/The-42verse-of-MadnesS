/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:53:56 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/08/31 15:53:58 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

u_int64_t   get_time(void)
{
    struct timeval tv;
    if(gettimeofday(&tv, NULL))
        return (print_error("time error", NULL ));
    return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec/1000));
}

void    messages(char *str, t_philo *philo)
{
    u_int64_t   time;

    pthread_mutex_lock(&philo->data->write);
    time = get_time() - philo->data->start_time;
    if(ft_strcmp("died", str) ==0 && philo->data->philo_dead == 0)
    {
        printf("%llu %d %s\n", time, philo->id, str);
        philo->data->philo_dead = 1;
    }
    else if(!philo->data->philo_dead)
        printf("%llu %d %s\n", time, philo->id, str);
    pthread_mutex_unlock(&philo->data->write);
}

void    take_forks(t_philo *philo)
{
    pthread_mutex_lock(philo->right_fork);
    messages("has taken a fork", philo);
    pthread_mutex_lock(philo->left_fork);
    messages("has taken a fork", philo);
}

void    drop_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    messages("is sleeping", philo);
    ft_usleep(philo->data->time_to_sleep);

}

void    eat(t_philo *philo)
{
    take_forks(philo);
    pthread_mutex_lock(&philo->lock);
    philo->eating = 1;
    philo->time_to_die = get_time() + philo->data->time_to_die;
    messages("is eating", philo);
    philo->eat_count++;
    ft_usleep(philo->data->time_to_eat);
    philo->eating = 0;
    pthread_mutex_unlock(&philo->lock);
    drop_forks(philo);
}
