#include "../include/philo.h"

int case_one(t_general *data)
{
    data->start_time = get_time();

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
    perror("&str\n");
    if(data)
        destroy_mutex(data);
    return (1);
}