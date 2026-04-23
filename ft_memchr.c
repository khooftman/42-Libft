/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:07:53 by khooftma          #+#    #+#             */
/*   Updated: 2026/04/23 09:45:32 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	 		i;
	unsigned char	*ptr; 
	unsigned char	target;

	i = 0;
	ptr = (unsigned char *)s;
	target = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == target)
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (NULL);
}