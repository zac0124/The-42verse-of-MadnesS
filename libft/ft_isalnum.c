/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:33:34 by zmunkhja          #+#    #+#             */
/*   Updated: 2022/01/18 12:35:58 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* checks for an alphanumeric character; it is equivalent to 
 *(isalpha(c) || isdigit(c)) */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}
