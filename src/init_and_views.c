/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_views.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:56:04 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/13 18:46:54 by jsebasti         ###   ########.fr       */
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
	fdf->map.resizez = 5;
	fdf->map.transx = 1;
	fdf->map.transy = 1;
	fdf->map.res = 0;
	fdf->button_pressed = 0;
	fdf->event = 0;
	fdf->key = 0;
	fdf->inv = 0;
	fdf->map.nlim = 0;
}

void	iso(t_app *fdf)
{
	fdf->map.angx = 45;
	fdf->map.angz = 45;
	fdf->map.angy = 0;
	fdf->map.resizez = 5;
	if (fdf->map.limits.axis[Z] > fdf->map.limits.axis[X])
		fdf->map.resizez = fdf->map.limits.axis[X];
	fdf->map.transx = 1;
	fdf->map.transy = 1;
	fdf->map.res = 0;
	fdf->map.nlim = 0;
	check_points(fdf);
}

void	orto(t_app *fdf)
{
	fdf->map.angx = 0;
	fdf->map.angz = 0;
	fdf->map.angy = 0;
	fdf->map.resizez = 5;
	if (fdf->map.limits.axis[Z] > fdf->map.limits.axis[X])
		fdf->map.resizez = fdf->map.limits.axis[X];
	fdf->map.transx = 1;
	fdf->map.transy = 1;
	fdf->map.res = 0;
	fdf->map.nlim = 0;
	check_points(fdf);
}

void	calculate_delta(t_point *delta, t_point *pixel, \
	t_point *start, int pixels)
{
	delta->axis[X] /= pixels;
	delta->axis[Y] /= pixels;
	pixel->axis[X] = start->axis[X];
	pixel->axis[Y] = start->axis[Y];
}
