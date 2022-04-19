/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:38:16 by zmunkhja          #+#    #+#             */
/*   Updated: 2022/04/19 10:38:19 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_printnbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int num, const char format);
int		ft_printpercent(void);
int		ft_ptr_len(uintptr_t num);
int		ft_num_len(unsigned	int num);
int		ft_hex_len(unsigned	int num);

char	*ft_uitoa(unsigned int n);

void	ft_putstr(char *str);
void	ft_put_ptr(uintptr_t num);
void	ft_put_hex(unsigned int num, const char format);
#endif