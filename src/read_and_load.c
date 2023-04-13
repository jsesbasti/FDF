/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 06:38:10 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/13 18:07:36 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define READED 50000000

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

static	void	map_get_points(t_map *map)
{
	static int	i = 0;
	static int	num_points = 0;
	static int	num_line = 0;
	char		*line;
	char		*last_line;

	line = NULL;
	last_line = map->mem;
	map->points = ft_calloc(map->len, sizeof(t_point));
	while (i >= 0)
	{
		if (map->mem[i] == '\n' || map->mem[i] == '\0')
		{
			free (line);
			line = ft_substr(last_line, 0, &map->mem[i] - last_line);
			last_line = &map->mem[i + 1];
			num_points = load_points(line, map, num_line++);
			if (num_points == -1)
				exit(3);
			if (map->mem[i] == '\0')
				break ;
		}
		i++;
	}
	free (line);
}

void	map_size(t_map *map)
{
	static int	i = -1;
	static int	num_elems = 0;	

	while (map->mem[++i])
	{
		if (map->mem[i] == '\n' && map->mem[i + 1] == '\0')
			break ;
		if (ft_isalnum(map->mem[i]) && \
			(map->mem[i + 1] == ' ' || map->mem[i + 1] == '\n' || \
			map->mem[i + 1] == '\0'))
			num_elems++;
		if (map->mem[i] == '\n')
		{
			map->limits.axis[Y]++;
			if (map->limits.axis[X] != num_elems && map->limits.axis[X] != 0)
				terminate(2);
			else
				map->limits.axis[X] = num_elems;
			num_elems = 0;
		}
	}
	if (num_elems > 0 && (map->limits.axis[X] != num_elems))
		terminate(2);
	map->limits.axis[Y]++;
	map->len = map->limits.axis[X] * map->limits.axis[Y];
}

char	*ft_read(int fd)
{
	static int	bytes = READED;
	char		*buff;
	char		*tmp;
	char		*maped;

	buff = malloc(READED * sizeof(char));
	if (!buff)
		return (NULL);
	maped = ft_strdup("");
	ft_printf("Situalizando mapa...\n");
	while (bytes == READED)
	{
		ft_bzero(buff, READED);
		bytes = read(fd, buff, READED);
		tmp = maped;
		maped = ft_strjoin(maped, buff);
		free(tmp);
	}
	free(buff);
	return (maped);
}

int	start_map(t_map *map, char *file)
{
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd < 2)
		return (1);
	map->mem = ft_read(fd);
	if (!map->mem)
		return (1);
	map_size(map);
	map_get_points(map);
	colorize(map);
	close(fd);
	return (0);
}
