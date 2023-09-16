/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhjargal <zmunkhjargal@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:54:12 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/09/16 15:23:05 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitor(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	pthread_mutex_lock(&philo->data->write);
	printf("data: %d\n", philo->data->philo_dead);
	pthread_mutex_unlock(&philo->data->write);
	while (philo->data->philo_dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->data->finished >= philo->data->philo_num)
		{
			philo->data->philo_dead = 1;
			pthread_mutex_unlock(&philo->lock);
			break ;
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*supervisor(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *) pointer;
	while (philo->data->philo_dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && philo->eating == 0)
		{
			messages("died", philo);
			pthread_mutex_unlock(&philo->lock);
			break ;
		}
		if (philo->eat_count == philo->data->number_of_meals)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->finished++;
			philo->eat_count++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
		usleep(1000);
	}
	return ((void *)0);
}

void	*routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *) pointer;
	philo->time_to_die = philo->data->time_to_die + get_time();
	if (pthread_create(&philo->thread_1, NULL, &supervisor, (void *)philo))
		return ((void *)1);
	while (philo->data->philo_dead == 0)
	{
		eat(philo);
		messages("is thinking", philo);
	}
	if (pthread_join(philo->thread_1, NULL) != 0)
		return ((void *)1);
	return ((void *)0);
}

int	thread_init(t_general *data)
{
	int			i;
	pthread_t	thread_0;

	i = -1;
	data->start_time = get_time();
	if (data->number_of_meals > 0)
	{
		if (pthread_create(&thread_0, NULL, &monitor, &data->philos[0]))
			return (print_error("create error", data));
	}
	while (++i < data->philo_num)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philos[i]))
			return (print_error("create error", data));
		ft_usleep(1);
	}
	i = -1;
	while (++i < data->philo_num)
	{
		if (pthread_join(data->tid[i], NULL))
			return (print_error("join error", data));
	}
	return (0);
}
