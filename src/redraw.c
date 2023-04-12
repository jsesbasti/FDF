/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:54:08 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/12 20:29:54 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_events(int button, int x, int y, t_app *fdf)
{
	if (button == 5 && x)
	{
		fdf->map.res *= 1.25;
		check_points(fdf);
	}
	if (button == 4 && y)
	{
		fdf->map.res *= 0.75;
		check_points(fdf);
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
