/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:27:27 by jsebasti          #+#    #+#             */
/*   Updated: 2022/10/18 05:00:44 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	sizet;
	void	*mtx;

	sizet = count * size;
	mtx = (void *)malloc(sizet);
	if (!mtx)
		return (NULL);
	ft_bzero(mtx, sizet);
	return (mtx);
}
