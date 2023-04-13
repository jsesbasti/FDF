/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:56:04 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/13 05:49:14 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_init(t_app *fdf)
{
	fdf->map.limits.axis[X] = 0;
	fdf->map.limits.axis[Y] = 0;
	fdf->map.zmin = 0;
	fdf->map.angx = 45;
	fdf->map.angz = 45;
	fdf->map.angy = 0;
	fdf->map.resize = 2.5;
	fdf->map.transx = 1;
	fdf->map.transy = 1;
	fdf->map.res = 0;
}

void	iso(t_app *fdf)
{
	fdf->map.angx = 45;
	fdf->map.angz = 45;
	fdf->map.angy = 0;
	check_points(fdf);
}

void	orto(t_app *fdf)
{
	fdf->map.angx = 0;
	fdf->map.angz = 0;
	fdf->map.angy = 0;
	check_points(fdf);
}
