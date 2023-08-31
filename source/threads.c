/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:54:12 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/08/31 15:54:14 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void monitor(void *pointer)
{
    t_philo *philo = (t_philo *)pointer;

    pthread_mutex_lock(&philo->data->write);
    printf("data: %d\n", philo->data->philo_dead);
    pthread_mutex_unlock(&philo->data->write);

    while (philo->data->philo_dead == 0)
    {
        pthread_mutex_lock(&philo->lock);
        if (philo->data->finished >= philo->data->number_of_philo)
        {
            philo->data->philo_dead = 1;
            pthread_mutex_unlock(&philo->lock);
            break;
            // Exit the loop after setting philo_dead to avoid deadlocks
        }
        pthread_mutex_unlock(&philo->lock);
    }
}

void    *supervisor(void *pointer)
{
    t_philo *philo;

    philo = (t_philo *) pointer;
    while (philo->data->philo_dead == 0)
    {
        pthread_mutex_lock(&philo->lock);
        if(get_time() >= philo->time_to_die && philo->eating == 0)
        {
            messages("died", philo);
            pthread_mutex_unlock(&philo->lock);
            break; // Exit the loop after the philosopher dies
        }
        if(philo->eat_count == philo->data->number_of_meals)
        {
            pthread_mutex_lock(&philo->data->lock);
            philo->data->finished++;
            philo->eat_count++;
            pthread_mutex_unlock(&philo->data->lock);
        }
         pthread_mutex_unlock(&philo->lock);
         usleep(1000);
    }
}

void    *routine(void *pointer)
{
    t_philo *philo;

    philo = (t_philo *) pointer;
    // Calculate the time when the philosopher should die
    philo->time_to_die = philo->data->time_to_die + get_time();
    // Create a supervisor thread to monitor the philosopher
    if(pthread_create(&philo->thread_1, NULL, &supervisor, (void *)philo) != 0)
        return ((void *) 1);
    while (philo->data->philo_dead == 0)
    {
        eat(philo);
        messages("is thinking", philo);
    }
    if(pthread_join(philo->thread_1, NULL) != 0)
        return  ((void *) 1);
}

int thread_init(t_general *data)
{
    int     i;
    pthread_t   thread_0;

    i = -1;
    data->start_time = get_time();
    if(data->number_of_meals > 0)
    {
        if(pthread_create(&thread_0, NULL, &monitor, &data->philos[0]) != 0)
            return (print_error("create error", data));
    }
    while (++i < data->number_of_philo)
    {
        if(pthread_create(&data->philos[i], NULL, &routine, &data->philos[i]) != 0)
            return(print_error("create error", data));
        ft_usleep(1);
    }
    i = -1;
    while(++i < data->number_of_philo)
    {
        if (pthread_join(data->thread_id[i], NULL) != 0)
			return (print_error("join error", data));
    }
    return (0);

}
