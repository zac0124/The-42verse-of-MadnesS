/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:09:45 by zmunkhja          #+#    #+#             */
/*   Updated: 2022/02/21 13:44:39 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Converts the letter c to lower case, if possible. */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}