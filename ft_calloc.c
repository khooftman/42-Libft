/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:50:36 by khooftma          #+#    #+#             */
/*   Updated: 2026/04/28 11:11:18 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	total_size;

	total_size = nmemb * size;
	if (total_size == 0)
		p = malloc(1);
	else
		p = malloc(total_size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, total_size);
	return (p);
}
