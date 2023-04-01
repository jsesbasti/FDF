/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 06:38:58 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/01 05:39:21 by jsebasti         ###   ########.fr       */
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

int	load_points(char *line, t_map *map, int numline)
{
	const char	**splited;
	int			i;
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_points(t_app *fdf)
{
	static int	i = 0;
	t_data		img;

	img.img = mlx_new_image(fdf->mlx, 1, 1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	while (i < fdf->map.len)
	{
		my_mlx_pixel_put(&img, 0, \
				0, 0xFFFFFF);
		mlx_put_image_to_window(fdf->mlx, fdf->win, img.img, \
				fdf->halfx + fdf->map.points[i].axis[X] * 50, \
				fdf->halfy + fdf->map.points[i].axis[Y] * 50);
		i++;
	}
}
