#include "include/philo.h"

int main(int argc, char **argv)
{
    t_general *data;

    if(argc < 5 || argc > 6)
        return (1);
    if(input_checker(argv))
        return (1);
    if(init(&data, argv, argc))
        return (1);
    if(data->number_of_philo == 1)
        return (case_one(&data));
    if(thread_init(&data))
        return (1);
    destroy_mutex(&data);
    return (0);
}