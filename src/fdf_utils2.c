/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 06:38:58 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/10 17:02:47 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dbl_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// POR FAVOR, NO PONER "STATIC INT I" POR LO QUE MAS QUIERAS, DA SEG_FAULT.
int	load_points(char *line, t_map *map, int numline)
{
	int			i;
	const char	**splited;
	static int	point_index = 0;

	splited = (const char **)ft_split(line, ' ');
	i = 0;
	while (splited[i] && splited[i][0] != '\n')
	{
		ft_atoi(&splited[i][0], &map->points[point_index].axis[Z]);
		map->points[point_index].axis[X] = i - map->limits.axis[X] / 2;
		map->points[point_index].axis[Y] = numline - map->limits.axis[Y] / 2;
		if (map->limits.axis[Z] < map->points[point_index].axis[Z])
			map->limits.axis[Z] = map->points[point_index].axis[Z];
		if (map->zmin > map->points[point_index].axis[Z])
			map->zmin = map->points[point_index].axis[Z];
		i++;
		point_index++;
	}
	dbl_free((char **)splited);
	return (i);
}

void	set_color(char *buffer, int endian, int color, int alpha)
{
	if (endian == 1)
	{
		buffer[0] = alpha;
		buffer[1] = (color >> 16) & 0xFF;
		buffer[2] = (color >> 8) & 0xFF;
		buffer[3] = (color) & 0xFF;
	}
	else
	{
		buffer[0] = (color) & 0xFF;
		buffer[1] = (color >> 8) & 0xFF;
		buffer[2] = (color >> 16) & 0xFF;
		buffer[3] = alpha;
	}
}

int	my_putpixel(t_app *fdf, t_point pixel)
{
	int	mypixel;
	int	alpha;

	alpha = 0;
	//if (pixel.axis[X] < MENU_WIDTH)
	//	alpha = -10;
	if (pixel.axis[X] >= fdf->scrn.size_x || pixel.axis[Y] >= fdf->scrn.size_y || \
		pixel.axis[X] < 0 || pixel.axis[Y] < 0)
		return (1);
	mypixel = ((int)pixel.axis[Y] * fdf->scrn.size_x * 4) + ((int)pixel.axis[X] * 4);
	if (fdf->bitmap.bitxpixel != 32)
		pixel.color = mlx_get_color_value(fdf->mlx, pixel.color);
	set_color(&fdf->bitmap.addr[mypixel], \
		fdf->bitmap.endian, pixel.color, alpha);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bitxpixel / 8));
	*(unsigned int *)dst = color;
}

void	resize(t_map *map)
{
	if (map->len <= 100)
		map->resize = 80;
	if (map->len > 100 && map->len <= 25000)
		map->resize = 20;
	if (map->len > 25000 && map->len <= 100000)
		map->resize = 5;
	if (map->len > 100000)
		map->resize = 1;
}

void	print_points(t_app *fdf)
{
	static int	i = 0;
	t_data		img;

	img.img = mlx_new_image(fdf->mlx, 1, 1);
	img.addr = mlx_get_data_addr(img.img, &img.bitxpixel, \
			&img.line_length, &img.endian);
	resize(&fdf->map);
	while (i < fdf->map.len)
	{
		my_mlx_pixel_put(&img, 0, 0, 0xFFFFFF);
		mlx_put_image_to_window(fdf->mlx, fdf->win, img.img, \
				fdf->halfx + fdf->map.points[i].axis[X] * fdf->map.resize, \
				fdf->halfy + fdf->map.points[i].axis[Y] * fdf->map.resize);
		i++;
	}
}
