/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:04:57 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/13 18:45:01 by jsebasti         ###   ########.fr       */
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

int	valid_pixel(t_point pixel)
{
	if (pixel.axis[X] < 0 || pixel.axis[X] >= WIDTH)
		return (0);
	if (pixel.axis[Y] < 0 || pixel.axis[Y] >= HEIGHT)
		return (0);
	return (1);
}

void	resize_z(int key, t_map *map)
{
	if (key == 126 && map->nlim < 5)
	{
		map->resizez *= 0.95;
		map->nlim++;
	}
	if (key == 125 && map->nlim > -50)
	{
		map->resizez /= 0.95;
		map->nlim--;
	}
}
