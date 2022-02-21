/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:06:08 by zmunkhja          #+#    #+#             */
/*   Updated: 2022/02/21 14:35:23 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strlcpy() and strlcat() functions copy and concatenate (link (things) 
together in a chain or series.) 
strings respectively. They are designed to be safer, more consistent, and 
less error prone replacements for strncpy(3) and strncat(3). 
Unlike those functions, strlcpy() and strlcat() take the full size of the 
buffer (not just the length) and guarantee to NUL-terminate the result (as 
long as size is larger than 0 or, in the case of strlcat(),
 as long as there is at least one byte free in dst). 
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(dst) + ft_strlen(src);
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	while (*dst)
		dst++;
	i = 0;
	while ((i < size - (len - ft_strlen(src)) - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*
int main ()
{
	char	test1[] = "Test 1";
	char	test2[] = "test 2";

	ft_strlcpy(test1, test2, 1);
	printf("%s\n", test1);
	return(0);
}
*/
