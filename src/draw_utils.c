/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:04:57 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/13 01:58:47 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	colorize(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		load_color((int)map->limits.axis[Z], map->zmin, \
		&map->points[i]);
		i++;
	}
}

int	ft_round(double num)
{
	int	rounded;

	rounded = (int)num;
	if (num - rounded >= .5)
		rounded++;
	return (rounded);
}

int	gradient(int startcolor, int endcolor, int len, int pix)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((endcolor >> 16) - \
					(startcolor >> 16)) / (double)len;
	increment[1] = (double)(((endcolor >> 8) & 0xFF) - \
					((startcolor >> 8) & 0xFF)) / (double)len;
	increment[2] = (double)((endcolor & 0xFF) - (startcolor & 0xFF)) \
					/ (double)len;
	new[0] = (startcolor >> 16) + ft_round(pix * increment[0]);
	new[1] = ((startcolor >> 8) & 0xFF) + ft_round(pix * increment[1]);
	new[2] = (startcolor & 0xFF) + ft_round(pix * increment[2]);
	newcolor = (new[0] << 16) + (new[1] << 8) + new[2];
	return (newcolor);
}

int	draw_line(t_app *fdf, t_point start, t_point end)
{
	t_point		delta;
	t_point		pixel;
	int			pixels;
	int			len;

	delta.axis[X] = end.axis[X] - start.axis[X];
	delta.axis[Y] = end.axis[Y] - start.axis[Y];
	pixels = sqrt((delta.axis[X] * delta.axis[X]) + \
			(delta.axis[Y] * delta.axis[Y]));
	len = pixels;
	delta.axis[X] /= pixels;
	delta.axis[Y] /= pixels;
	pixel.axis[X] = start.axis[X];
	pixel.axis[Y] = start.axis[Y];
	while (pixels > 0)
	{
		pixel.color = gradient(start.color, end.color, len, len - pixels);
		my_mlx_pixel_put(&fdf->bitmap, pixel.axis[X], \
			pixel.axis[Y], pixel.color);
		pixel.axis[X] += delta.axis[X];
		pixel.axis[Y] += delta.axis[Y];
		pixels = pixels - 1;
	}
	return (0);
}

void	check_points(t_app *fdf)
{
	int	i;

	i = 0;
	redraw(fdf);
	create_copy(fdf);
	check_z(&fdf->map);
	rotate(&fdf->map);
	resize(&fdf->map);
	while (i < fdf->map.len)
	{
		if ((i + 1 < fdf->map.len) && (fdf->map.points[i].axis[Y] == \
			fdf->map.points[i + 1].axis[Y]))
			draw_line(fdf, fdf->map.copy[i], fdf->map.copy[i + 1]);
		if ((i + fdf->map.limits.axis[X]) < fdf->map.len)
			draw_line(fdf, fdf->map.copy[i], \
				fdf->map.copy[i + (int)fdf->map.limits.axis[X]]);
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->bitmap.img, 0, 0);
}
