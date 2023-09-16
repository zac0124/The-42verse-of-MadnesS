/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhjargal <zmunkhjargal@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:54:30 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/09/02 17:19:31 by zmunkhjarga      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int first_case(t_general *data)
{
    data->start_time = get_time();
    if(pthread_create(&data->thread_id[0], NULL, &routine, &data->philos[0]))
        return (print_error("case one error", data));
	pthread_detach(data->thread_id[0]);
	while (data->philo_dead == 0)
		ft_usleep(0);
	destroy_mutex(data);
	return (0);
}

void free_memory(t_general *data)
{
    if(data->thread_id)
        free(data->thread_id);
    if(data->forks)
        free(data->forks);
    if(data->philos)
        free(data->philos);
}

void destroy_mutex(t_general *data)
{
    int i;

    i = -1;
    while(++i < data->number_of_philo)
    {
        pthread_mutex_destroy(&data->forks[i]);
        pthread_mutex_destroy(&data->philos[i].lock);
    }
    pthread_mutex_destroy(&data->write);
    pthread_mutex_destroy(&data->lock);
    free_memory(data);
}

int print_error(char *str, t_general *data)
{
    perror(str);
    if(data)
        destroy_mutex(data);
    return (1);
}
