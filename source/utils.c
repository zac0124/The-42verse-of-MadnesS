#include "../include/philo.h"

bool is_string(char c, char *str)
{
    while(*str)
    {
        if(*str == c)
            return (true);
        str++;
    }
    return (false);
}

long    ft_atoi(const char *str)
{
    int sign;
    long    result;

    sign = 1;
    result = 0;

    while(is_string(*(char *) str, "\t\n\v\f\r"))
        str++;
    if(*str == "-")
        sign *= -1;
    if(*str == "-" || *str == "+")
        str++;
    while(*str >= '0' && *str <= '9')
    {
        if(result * 10 < 0)
            return (-1);
        result *= 10;
        result += *str - '0';
        str++;
    }
    return (result * sign);
}

int input_checker(char  **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while(argv[i])
    {
        while(argv[i][j])
        {
            if(argv[i][j] == ' ')
            {
                j++;
                continue;
            }
            if(argv[i][j] < 48 || argv[i][j] > 57)
                return(print_error("error", 0));
            j++;
        }
            i++;

    }
    return(0);
}

int ft_usleep(useconds_t time)
{
    u_int64_t start_time;

    start_time = get_time();
    while((get_time() - start_time) < time)
        usleep(time/10);
    return (0);
}

int ft_strcmp(char *s1, char *s2)
{
    while(*s1 != '\0' && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return(*(char *)s1 - *(char *)s2);
}