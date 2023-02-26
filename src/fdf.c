/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:11:02 by jsebasti          #+#    #+#             */
/*   Updated: 2023/02/26 20:26:16 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	esc(int key, t_app *fdf)
{
	if (key == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	return (1);
}

int	close_app(t_app *fdf)
{
	if (fdf)
		mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

int	check(char **map)
{
	const char *ext;
	char *mapext;

	ext = ".fdf";
	mapext = ft_strrchr(map[1], '.');
	if ( !mapext || ft_strlen(mapext) != 4)
	{
		ft_printf("Map error\n");
		return (1);
	}
	if (ft_strncmp(ext, mapext, 4) != 0)
		return (1);
	return (0);
}

int	init(t_app *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (1);
	fdf->scrn.size_x = 1920;
	fdf->scrn.size_y = 1080;
	fdf->win = mlx_new_window(fdf->mlx, fdf->scrn.size_x, fdf->scrn.size_y, "FdF");
	if (!fdf->win)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_app	fdf;

	if (argc != 2)
	{
		if (argc < 2)
			ft_printf("You need to give a map\n");
		return (1);
	}
	else
	{
		if (check(argv) == 1)
			return (1);
		if (init(&fdf) == 1)
			return (1);
		mlx_key_hook(fdf.mlx, esc, &fdf);
		mlx_hook(fdf.mlx, 17, 0, close_app, &fdf);
		mlx_loop(fdf.mlx);
	}
	return (0);
}