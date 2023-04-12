/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:54:08 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/12 23:18:10 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_events(int button, int x, int y, t_app *fdf)
{
	if (button == 5 && x && y && fdf->button_pressed == 0)
	{
		fdf->map.res *= 1.1;
		check_points(fdf);
	}
	if (button == 4 && fdf->button_pressed == 0)
	{
		fdf->map.res *= 0.9;
		check_points(fdf);
	}
	if (button == 1)
	{
		fdf->button_pressed = 1;
		fdf->last_x = x;
		fdf->last_y = y;
	}
	return (0);
}

int mouse_move_hook(int x, int y, t_app *fdf)
{
	if (fdf->button_pressed)
	{
		if (x < WIDTH / 2)
			fdf->map.transx -= 5;
		if (x > WIDTH / 2)
			fdf->map.transx += 5;
		if (y > HEIGHT /2 )
			fdf->map.transy += 5;
		if (y < HEIGHT / 2)
			fdf->map.transy -= 5;
		check_points(fdf);
		fdf->last_x = x;
		fdf->last_y = y;
	}
	return (0);
}

int mouse_release_hook(int button, int x, int y, t_app *fdf)
{
    if (button == 1)
    {
        fdf->button_pressed = 0;
        x = fdf->last_x;
        y =	fdf->last_y;
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
