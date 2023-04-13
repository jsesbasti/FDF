/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:27:25 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/13 18:07:37 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(t_map *map)
{
	rotate_z(map, map->angz);
	rotate_x(map, map->angx);
	rotate_y(map, map->angy);
}

void	rotate_x(t_map *map, int ang)
{
	float	rad;
	int		i;
	float	cosr;
	float	sinr;
	t_point	p;

	rad = ang * M_PI / 180;
	cosr = cos(rad);
	sinr = sin(rad);
	i = 0;
	while (i < map->len)
	{
		p = map->copy[i];
		map->copy[i].axis[Y] = (p.axis[Y] * cosr) - \
			(p.axis[Z] * sinr);
		map->copy[i].axis[Z] = (p.axis[Y] * sinr) + \
			(p.axis[Z] * cosr);
		i++;
	}
}

void	rotate_y(t_map *map, int ang)
{
	float	rad;
	int		i;
	float	cosr;
	float	sinr;
	t_point	p;

	rad = ang * M_PI / 180;
	cosr = cos(rad);
	sinr = sin(rad);
	i = 0;
	while (i < map->len)
	{
		p = map->copy[i];
		map->copy[i].axis[X] = (p.axis[X] * cosr) + \
		(p.axis[Z] * sinr);
		map->copy[i].axis[Z] = -(p.axis[X] * sinr) + \
		(p.axis[Z] * cosr);
		i++;
	}
}

void	rotate_z(t_map *map, int ang)
{
	float	rad;
	int		i;
	float	cosr;
	float	sinr;
	t_point	p;

	rad = ang * M_PI / 180;
	cosr = cos(rad);
	sinr = sin(rad);
	i = 0;
	while (i < map->len)
	{
		p = map->copy[i];
		map->copy[i].axis[X] = (p.axis[X] * cosr) - \
		(p.axis[Y] * sinr);
		map->copy[i].axis[Y] = (p.axis[X] * sinr) + \
		(p.axis[Y] * cosr);
		i++;
	}
}
