/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:55:52 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/13 18:15:31 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	free(fdf->map.copy);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->bitmap.img, 0, 0);
}

int	draw_line(t_app *fdf, t_point start, t_point end)
{
	t_point		delta;
	t_point		pixel;
	float		pixels;
	int			len;

	if (valid_pixel(start) == 0 && valid_pixel(end) == 0)
		return (0);
	delta.axis[X] = end.axis[X] - start.axis[X];
	delta.axis[Y] = end.axis[Y] - start.axis[Y];
	pixels = sqrt((delta.axis[X] * delta.axis[X]) + \
			(delta.axis[Y] * delta.axis[Y]));
	len = pixels;
	calculate_delta(&delta, &pixel, &start, pixels);
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

void	print_points(t_app *fdf)
{
	fdf->bitmap.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->bitmap.addr = mlx_get_data_addr(fdf->bitmap.img, \
		&fdf->bitmap.bitxpixel, \
		&fdf->bitmap.line_length, &fdf->bitmap.endian);
	if (fdf->map.limits.axis[Z] > fdf->map.limits.axis[X])
		fdf->map.resizez = fdf->map.limits.axis[X];
	check_points(fdf);
}
