/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:55:51 by jsebasti          #+#    #+#             */
/*   Updated: 2022/09/18 15:39:48 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				index;

	d = dst;
	s = src;
	index = 0;
	if (dst < src)
	{
		while (index < len)
		{
			d[index] = s[index];
			index++;
		}
	}
	else if (dst > src)
	{
		while (len > index)
		{
			d[len - 1] = s[len -1];
			len--;
		}
	}
	return (dst);
}
