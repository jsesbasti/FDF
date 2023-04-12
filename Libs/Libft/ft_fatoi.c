/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:43:02 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/12 09:46:11 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	limit(long long n, const char *s, int sign)
{
	long long	limit_min;
	long long	limit_max;

	limit_min = ((n * 10) + (*s - '0')) * sign;
	if (limit_min < -2147483648)
		return (0);
	limit_max = ((n * 10) + (*s - '0')) * sign;
	if (limit_max > 2147483647)
		return (-1);
	return (1);
}

int	ft_fatoi(const char *str, float *temp)
{
	size_t		i;
	int			sign;
	long int	result;
	int			limit_test;

	i = 0;
	sign = 1;
	result = 0;
	if (ft_strlen(str) > 11)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]))
	{
		limit_test = limit(result, &str[i], sign);
		if (limit_test == 0 || limit_test == -1)
			return (limit_test);
		result = ((result * 10) + str[i] - '0');
		i++;
	}
	if (temp)
		*temp = result * sign;
	return (1);
}
