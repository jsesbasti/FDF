/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 06:38:58 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/13 06:45:38 by jsebasti         ###   ########.fr       */
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
	char		**splited;
	static int	point_index = 0;

	splited = ft_split(line, ' ');
	i = 0;
	while (splited[i] && splited[i][0] != '\n')
	{
		ft_fatoi(&splited[i][0], &map->points[point_index].axis[Z]);
		map->points[point_index].axis[X] = i - map->limits.axis[X] / 2;
		map->points[point_index].axis[Y] = numline - map->limits.axis[Y] / 2;
		map->points[point_index].paint = 1;
		map->points[point_index].color = 0xFFFFFF;
		map->points[point_index].hex_color = has_hexcolors(splited[i]);
		if (map->limits.axis[Z] < map->points[point_index].axis[Z])
			map->limits.axis[Z] = map->points[point_index].axis[Z];
		if (map->zmin > map->points[point_index].axis[Z])
			map->zmin = map->points[point_index].axis[Z];
		i++;
		point_index++;
	}
	dbl_free(splited);
	return (i);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bitxpixel / 8));
	*(unsigned int *)dst = color;
}

void	resize(t_map *map)
{
	int		i;
	float	modmap;

	i = 0;
	if (map->res == 0)
	{
		modmap = sqrt(pow(map->limits.axis[Y], 2) + \
			pow(map->limits.axis[X], 2));
		map->res = HEIGHT / modmap;
		if (map->res < 1.5)
			map->res = 1.5;
	}
	while (i < map->len)
	{
		if (map->res > 1.5)
		{
			map->copy[i].axis[X] *= map->res;
			map->copy[i].axis[Y] *= map->res;
		}
		map->copy[i].axis[X] += (WIDTH / 2);
		map->copy[i].axis[Y] += (HEIGHT / 2);
		map->copy[i].axis[X] += map->transx;
		map->copy[i].axis[Y] += map->transy;
		i++;
	}
}

void	print_points(t_app *fdf)
{
	fdf->bitmap.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->bitmap.addr = mlx_get_data_addr(fdf->bitmap.img, \
		&fdf->bitmap.bitxpixel, \
		&fdf->bitmap.line_length, &fdf->bitmap.endian);
	if (fdf->map.limits.axis[Z] > fdf->map.limits.axis[X])
		fdf->map.resize = fdf->map.limits.axis[X];
	check_points(fdf);
}
