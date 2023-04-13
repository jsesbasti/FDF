/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:11:02 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/13 06:37:15 by jsebasti         ###   ########.fr       */
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
	if (key == 33)
		orto(fdf);
	if (key == 8)
		iso(fdf);
	check_cntrl(key, fdf);
	if (key == 6)
		fdf->key = 1;
	if (key == 7)
		fdf->key = 2;
	if (key == 16)
		fdf->key = 3;
	return (0);
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

void	init(t_app *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return ;
	map_init(fdf);
	fdf->button_pressed = 0;
	fdf->event = 0;
	fdf->key = 0;
	fdf->inv = 0;
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, \
		HEIGHT, "FdF");
	if (!fdf->win)
		return ;
}

int	main(int argc, char **argv)
{
	t_app	fdf;

	if (argc == 2)
	{
		if (check(argv[1]))
			return (1);
		init(&fdf);
		if (start_map(&fdf.map, argv[1]))
			return (1);
		print_points(&fdf);
		mlx_hook(fdf.win, 2, 0, esc, &fdf);
		mlx_mouse_hook(fdf.win, mouse_events, &fdf);
		mlx_hook(fdf.win, 17, 0, close_app, &fdf);
		mlx_hook(fdf.win, 6, 0, mouse_move_hook, &fdf);
		mlx_hook(fdf.win, 5, 0, mouse_release_hook, &fdf);
		mlx_loop_hook(fdf.mlx, add_rot, &fdf);
		mlx_loop(fdf.mlx);
	}
	else
		return (1);
	return (0);
}
