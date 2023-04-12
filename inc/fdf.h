/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:11:58 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/12 22:59:53 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define X 0
# define Y 1
# define Z 2
# define HEIGHT 1080
# define WIDTH 1920

# include "../Libs/Libft/libft.h"
# include "../Libs/printf/ft_printf.h"
# include "../Libs/minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bitxpixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_point
{
	float	axis[3];
	int		color;
	int		hex_color;
	int		paint;
}	t_point;

typedef struct s_map
{
	t_point	limits;
	t_point	*points;
	t_point *copy;
	int		len;
	int		zmin;
	float	res;
	float	resize;
	float	transx;
	float	transy;
	char	*mem;
	char	*line;
	int		angx;
	int		angy;
	int		angz;
}	t_map;

typedef struct s_app
{
	void	*mlx;
	void	*win;
	int		last_y;
	int		last_x;
	int		button_pressed;
	t_map	map;
	t_data	bitmap;
}	t_app;


int		start_map(t_map *map, char *file);

int		load_points(char *line, t_map *map, int numline);

void	terminate(int errcod);

void	print_points(t_app *fdf);

void	check_points(t_app *fdf);

int		draw_line(t_app *fdf, t_point start, t_point end);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	resize(t_map *map);

void	rotate_x(t_map *map, int ang);

void	rotate_y(t_map *map, int ang);

void	rotate_z(t_map *map, int ang);

void	colorize(t_map *map);

void	load_color(int max, int min, t_point *point);

int		has_hexcolors(char *line);

int		valid_point(char *value);

void	dbl_free(char **str);

int		gradient(int startcolor, int endcolor, int len, int pix);

void	rotate(t_map *map);

void	check_z(t_map *map);

void	resize_z(int key, t_map *map);

void	create_copy(t_app *fdf);

void	redraw(t_app *fdf);

int		mouse_events(int button, int x, int y, t_app *fdf);

int 	mouse_press_hook(int button, int x, int y, t_app *fdf);

int 	mouse_move_hook(int x, int y, t_app *fdf);

int 	mouse_release_hook(int button, int x, int y, t_app *fdf);

# define COS cos(30 * (M_PI / 180))
# define SIN sin(30 * (M_PI / 180))
# define NSIN -sin(30 * (M_PI / 180))

#endif
