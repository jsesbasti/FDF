/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:54:08 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/13 06:36:44 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cond_event(int x, int y, t_app *fdf)
{
	if (fdf->event == 1)
	{
		if (x < WIDTH / 2)
			fdf->map.transx += 10;
		if (x > WIDTH / 2)
			fdf->map.transx -= 10;
		if (y > HEIGHT / 2)
			fdf->map.transy -= 10;
		if (y < HEIGHT / 2)
			fdf->map.transy += 10;
	}
	if (fdf->event == 2)
	{
		if (x < WIDTH / 2)
			fdf->map.transx += 10;
		if (x > WIDTH / 2)
			fdf->map.transx -= 10;
		if (y > HEIGHT / 2)
			fdf->map.transy -= 10;
		if (y < HEIGHT / 2)
			fdf->map.transy += 10;
	}
}

int	mouse_events(int button, int x, int y, t_app *fdf)
{
	if (button == 1)
	{
		fdf->button_pressed = 1;
		fdf->last_x = x;
		fdf->last_y = y;
	}
	if (button == 5 && fdf->button_pressed == 0)
	{
		fdf->map.res *= 1.1;
		fdf->event = 1;
		cond_event(x, y, fdf);
		fdf->event = 0;
		check_points(fdf);
	}
	if (button == 4 && fdf->button_pressed == 0)
	{
		fdf->map.res *= 0.9;
		fdf->event = 2;
		cond_event(x, y, fdf);
		fdf->event = 0;
		check_points(fdf);
	}
	return (0);
}

int	mouse_move_hook(int x, int y, t_app *fdf)
{
	if (fdf->button_pressed == 1)
	{
		if (x < fdf->last_x)
			fdf->map.transx -= 5;
		if (x > fdf->last_x)
			fdf->map.transx += 5;
		if (y > fdf->last_y)
			fdf->map.transy += 5;
		if (y < fdf->last_y)
			fdf->map.transy -= 5;
		check_points(fdf);
		fdf->last_x = x;
		fdf->last_y = y;
	}
	return (0);
}

int	mouse_release_hook(int button, int x, int y, t_app *fdf)
{
	if (button == 1)
	{
		fdf->button_pressed = 0;
		fdf->last_y = y;
		fdf->last_x = x;
	}
	return (0);
}

void	redraw(t_app *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			my_mlx_pixel_put(&fdf->bitmap, j, i, 0x000000);
	}
}
