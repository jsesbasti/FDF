/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 07:39:43 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/13 18:36:38 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_copy(t_app *fdf)
{
	int	i;

	i = 0;
	fdf->map.copy = ft_calloc(sizeof(t_point), fdf->map.len);
	if (!fdf->map.copy)
		terminate(3);
	while (i < fdf->map.len)
	{
		fdf->map.copy[i] = fdf->map.points[i];
		i++;
	}
}

void	load_color(int max, int min, t_point *point)
{
	point->paint = 1;
	point->color = WHITE;
	if (point->hex_color > 0)
	{
		point->color = point->hex_color;
		return ;
	}
	if (point->axis[Z] == max)
		point->color = RED;
	else if (point->axis[Z] == 0)
		point->color = WHITE;
	else if (point->axis[Z] == min && min != 0)
		point->color = BLUE;
	else if (point->axis[Z] > 0)
		point->color = gradient(WHITE, RED, \
		max, point->axis[Z]);
	else
		point->color = gradient(BLUE, WHITE, \
		-min, - (min - point->axis[Z]));
}

int	has_hexcolors(char *line)
{
	char	**color;
	int		get_color;

	if (ft_strchr(line, ',') != 0)
	{
		color = ft_split(line, ',');
		get_color = strtol(color[1] + 2, NULL, 16);
		dbl_free(color);
		return (get_color);
	}
	else
		return (0);
}

int	valid_point(char *value)
{
	int	valid;

	valid = 0;
	if (*value == '-' || *value == '+' || ft_isdigit(*value))
		valid++;
	value++;
	while (ft_isdigit(*value))
	{
		value++;
		valid++;
	}
	if (valid == 0)
		return (0);
	else
		return (1);
}

void	check_z(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		map->copy[i].axis[Z] /= map->resizez;
		i++;
	}
}
