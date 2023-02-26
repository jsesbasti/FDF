/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:57:07 by jsebasti          #+#    #+#             */
/*   Updated: 2022/10/09 23:06:39 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_unsigned(unsigned int n, int count)
{
	if (n < 0)
		n *= -1;
	if (n > 9)
	{
		count = ft_print_unsigned(n / 10, count);
		if (count == -1)
			return (-1);
	}
	count = ft_print_char(n % 10 + '0', count);
	if (count == -1)
		return (-1);
	return (count);
}
