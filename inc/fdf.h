/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:11:58 by jsebasti          #+#    #+#             */
/*   Updated: 2023/02/26 20:26:19 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libs/Libft/libft.h"
#include "../Libs/printf/ft_printf.h"
#include "../Libs/minilibx_macos/mlx.h"

typedef struct s_win
{
	int		size_x;
	int		size_y;
}	t_win;

typedef struct s_app
{
	void	*mlx;
	void	*win;
	t_win	scrn;
}	t_app;