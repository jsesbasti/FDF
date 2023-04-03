/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 06:38:10 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/03 17:31:25 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define READED 50000000

void	terminate(int errcod)
{
	if (errcod == 2)
		ft_printf("Limits error.");
	if (errcod == 3)
		ft_printf("Split error");
	exit(errcod);
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
	ft_printf("%s", map->mem);
	close(fd);
	return (0);
}
