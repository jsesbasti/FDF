/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:11:58 by jsebasti          #+#    #+#             */
/*   Updated: 2023/04/01 05:17:21 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define X 0
# define Y 1
# define Z 2

# include "../Libs/Libft/libft.h"
# include "../Libs/printf/ft_printf.h"
# include "../Libs/minilibx_macos/mlx.h"
# include <fcntl.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_point
{
	int		axis[3];
	int		color;
	int		hex;
}	t_point;

typedef struct s_map
{
	t_point	limits;
	t_point	*points;
	int		len;
	char	*mem;
	char	*line;
	int		zmin;
}	t_map;

typedef struct s_win
{
	int		size_x;
	int		size_y;
}	t_win;

typedef struct s_app
{
	void	*mlx;
	void	*win;
	int		halfx;
	int		halfy;
	t_win	scrn;
	t_map	map;
}	t_app;


int			start_map(t_map *map, char *file);

int			load_points(char *line, t_map *map, int numline);

void		terminate(int errcod);

void		print_points(t_app *fdf);

#endif
