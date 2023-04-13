/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 06:38:58 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/13 18:07:34 by jsebasti         ###   ########.fr       */
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

void	terminate(int errcod)
{
	if (errcod == 2)
		ft_printf("Limits error.\n");
	if (errcod == 3)
		ft_printf("Split error.\n");
	exit(errcod);
}

// POR FAVOR, NO PONER "STATIC INT I" POR LO QUE MAS QUIERAS, DA SEG_FAULT.

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
		map->copy[i].axis[X] *= map->res;
		map->copy[i].axis[Y] *= map->res;
		map->copy[i].axis[X] += (WIDTH / 2);
		map->copy[i].axis[Y] += (HEIGHT / 2);
		map->copy[i].axis[X] += map->transx;
		map->copy[i].axis[Y] += map->transy;
		i++;
	}
}
