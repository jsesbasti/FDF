/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:11:02 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/12 23:18:53 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	esc(int key, t_app *fdf)
{
	if (key == 53)
	{
		mlx_destroy_image(fdf->mlx, fdf->bitmap.img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	if (key == 126 || key == 125)
	{
		resize_z(key, &fdf->map);
		check_points(fdf);
	}
	return (1);
}

int	close_app(t_app *fdf)
{
	if (fdf)
		mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

int	check(char *argv)
{
	char	*ext;
	char	*mapext;

	ext = ".fdf";
	mapext = ft_strrchr(argv, '.');
	if (!mapext || ft_strlen(mapext) != 4)
	{
		ft_printf("Map error\n");
		return (1);
	}
	if (ft_strncmp(ext, mapext, 4) != 0)
	{
		ft_printf("Map error\n");
		return (1);
	}
	return (0);
}

int	init(t_app *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (1);
	fdf->map.limits.axis[X] = 0;
	fdf->map.limits.axis[Y] = 0;
	fdf->map.zmin = 0;
	fdf->map.angx = 45;
	fdf->map.angz = 45;
	fdf->map.angy = 0;
	fdf->map.resize = 2.5;
	fdf->map.transx = 0;
	fdf->map.transy = 0;
	fdf->map.res = 0;
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, \
		HEIGHT, "FdF");
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
		else
			ft_printf("Please give only one map\n");
		return (1);
	}
	else
	{
		if (check(argv[1]))
			return (1);
		if (init(&fdf))
			return (1);
		if (start_map(&fdf.map, argv[1]))
			return (1);
		print_points(&fdf);
		mlx_key_hook(fdf.win, esc, &fdf);
		mlx_mouse_hook(fdf.win, mouse_events, &fdf);
		mlx_hook(fdf.win, 17, 0, close_app, &fdf);
		mlx_hook(fdf.win, 6, 0, mouse_move_hook, &fdf);
		mlx_hook(fdf.win, 5, 0, mouse_release_hook, &fdf);
		mlx_loop(fdf.mlx);
	}
	return (0);
}
