/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:44:00 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/01/12 12:33:17 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"

void	send_bit(int pid, char *str, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 7)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(300);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_bit(pid, str, ft_strlen(str));
	}
	else
		ft_printf("\nERROR!!! COULD BE SPACE OR BLANK\n\n");
}
