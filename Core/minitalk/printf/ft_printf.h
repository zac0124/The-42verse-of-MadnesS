/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:18:28 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/01/12 12:32:22 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>

void	ft_putcharacter_length(char character, int *length);
void	ft_string(char *args, int *length);
void	ft_number(int number, int *length);
void	ft_hexadecimal(unsigned int x, int *length, char hex);
void	ft_unsigned_int(unsigned int u, int *length);
void	ft_pointer(size_t pointer, int *length);

int		ft_printf(const	char	*string, ...);

typedef struct s_message
{
	char	c;
	size_t	i;
}	t_message;

t_message	g_msg;

int		ft_strlen(const char *str);
int		ft_atoi(const char *str);

#endif
