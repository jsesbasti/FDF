/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:08:23 by jsebasti          #+#    #+#             */
/*   Updated: 2022/09/23 15:50:03 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 || !s2)
	{
		if (!s1)
			return ((char *)s2);
		if (!s2)
			return ((char *)s1);
	}
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < ft_strlen(s1))
		res[i] = ((char *)s1)[i];
	while (++j <= ft_strlen(s2))
	{
		res[i] = ((char *)s2)[j];
		i++;
	}
	return (res);
}
