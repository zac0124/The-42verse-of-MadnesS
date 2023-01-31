/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:26:27 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/01/12 12:26:29 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharacter_length(char character, int *length)
{
	write(1, &character, 1);
	(*length)++;
}

void	ft_string(char *args, int *length)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		write(1, "null", 4);
		(*length) += 4;
		return ;
	}
	while (args[i] != '\0')
	{
		ft_putcharacter_length(args[i], length);
		i++;
	}
}
