/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhjargal <zmunkhjargal@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:54:04 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/09/02 17:07:42 by zmunkhjarga      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int     memory_alloc(t_general *data)
{
    data->thread_id = malloc(sizeof(pthread_t) * data->number_of_philo);
    if(!data->thread_id)
        return(print_error("id memory allocation error", data));
    data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philo);
    if(!data->forks)
        return(print_error("forks memory allocation error", data));
    data->philos = malloc(sizeof(t_philo) * data->number_of_philo);
	if (!data->philos)
		return (print_error("philo error", data));
	return (0);
}

int     put_forks(t_general *data)
{
    	int	i;

	i = -1;
	while (++i < data->number_of_philo)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	data->philos[0].left_fork = &data->forks[0];
	data->philos[0].right_fork = &data->forks[data->number_of_philo - 1];
	i = 1;
	while (i < data->number_of_philo)
	{
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[i - 1];
		i++;
	}
	return (0);
}

void    enter_philos(t_general *data)
{
    int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->philos[i].data = data;
		data->philos[i].id = i+1;
		data->philos[i].time_to_die = data->time_to_die;
		data->philos[i].eat_count = 0;
		data->philos[i].eating = 0;
		data->philos[i].status = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
		i++;
	}
}

int     start(t_general *data, char **argv, int argc)
{
    data->number_of_philo = (int) ft_atoi(argv[1]);
	data->time_to_die = (u_int64_t) ft_atoi(argv[2]);
	data->time_to_eat = (u_int64_t) ft_atoi(argv[3]);
	data->time_to_sleep = (u_int64_t) ft_atoi(argv[4]);
	if (argc == 6)
		data->number_of_meals = (int) ft_atoi(argv[5]);
	else
		data->number_of_meals = -1;
	if (data->number_of_philo <= 0 || data->number_of_philo > 200 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0)
		return (print_error("start errer", 0));
	data->philo_dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (0);
}

int	init(t_general *data, char **argv, int argc)
{
	if (start(data, argv, argc))
		return (1);
	if (memory_alloc(data))
		return (1);
	if (put_forks(data))
		return (1);
	enter_philos(data);
	return (0);
}
