/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 04:59:27 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/13 05:55:28 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	add_rot(t_app *fdf)
{
	if (fdf->key == 1)
	{
		if (fdf->inv)
			fdf->map.angz -= 1.5;
		else
			fdf->map.angz += 1.5;
	}
	if (fdf->key == 2)
	{
		if (fdf->inv)
			fdf->map.angx -= 1.5;
		else
			fdf->map.angx += 1.5;
	}
	if (fdf->key == 3)
	{
		if (fdf->inv)
			fdf->map.angy -= 1.5;
		else
			fdf->map.angy += 1.5;
	}
	fdf->key = 0;
	check_points(fdf);
	return (0);
}

void	check_cntrl(int key, t_app *fdf)
{
	if (key == 256)
	{
		if (fdf->inv)
			fdf->inv = 0;
		else
			fdf->inv = 1;
	}
}
