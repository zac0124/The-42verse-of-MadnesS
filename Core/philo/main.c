/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhjargal <zmunkhjargal@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:53:20 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/09/16 13:58:09 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char **argv)
{
	t_general	data;

	if (argc < 5 || argc > 6)
		return (1);
	if (input_checker(argv))
		return (1);
	if (init(&data, argv, argc))
		return (1);
	if (data.philo_num == 1)
		return (first_case(&data));
	if (thread_init(&data))
		return (1);
	destroy_mutex(&data);
	return (0);
}
