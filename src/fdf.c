/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:11:02 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/13 18:07:33 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	esc_up(int key, t_app *fdf)
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
	if (key == 6 || key == 7 || key == 16)
		add_rot(key, fdf);
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
		mlx_hook(fdf.win, 2, 0, esc_up, &fdf);
		mlx_hook(fdf.win, 3, 0, esc_down, &fdf);
		mlx_hook(fdf.win, 4, 0, mouse_events, &fdf);
		mlx_hook(fdf.win, 5, 0, mouse_release_hook, &fdf);
		mlx_hook(fdf.win, 6, 0, mouse_move_hook, &fdf);
		mlx_hook(fdf.win, 17, 0, close_app, &fdf);
		mlx_loop(fdf.mlx);
	}
	else
		return (1);
	return (0);
}
