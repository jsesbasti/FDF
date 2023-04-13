/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:11:58 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/13 18:41:12 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define X 0
# define Y 1
# define Z 2
# define HEIGHT 1080
# define WIDTH 1920
# define RED 0xFF0000
# define WHITE 0xFFFFFF
# define BLUE 0x0000FF
# define GREEN 0x00FF00

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

typedef struct s_events
{
	float		angle[3];
	float		new_center[2];
}	t_events;

typedef struct s_map
{
	t_point	limits;
	t_point	*points;
	t_point *copy;
	int		len;
	int		nlim;
	int		zmin;
	float	res;
	float	resizez;
	float	transx;
	float	transy;
	char	*mem;
	char	*line;
	float	angx;
	float	angy;
	float	angz;
}	t_map;

typedef struct s_app
{
	void		*mlx;
	void		*win;
	float		last_y;
	float		last_x;
	float		shift_x;
	float		shift_y;
	int			button_pressed;
	int			event;
	int			key;
	int			inv;
	t_map		map;
	t_data		bitmap;
	t_events	evnt;
}	t_app;

int		valid_pixel(t_point pixel);

void	check_cntrl(int key, t_app *fdf);

int		esc_up(int key, t_app *fdf);

int		esc_down(int key, t_app *fdf);

int		close_app(t_app *fdf);

void	iso(t_app *fdf);

void	orto(t_app *fdf);

int		add_rot(int key, t_app *fdf);

int		start_map(t_map *map, char *file);

void	map_init(t_app *fdf);

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

void	calculate_delta(t_point *delta, t_point *pixel, t_point *start, int	pixels);

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
