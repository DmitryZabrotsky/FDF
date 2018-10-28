/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:48:00 by dzabrots          #+#    #+#             */
/*   Updated: 2018/10/28 16:48:02 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/incl/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include "minilibx_macos/mlx.h"
# include <math.h>

typedef struct	s_map
{
	int			x;
	int			y;
	int			**vals;
	int			val;
	int			border;
	int			w_y;
	int			w_x;
	int			indent_y;
}				t_map;

typedef struct	s_mlx
{
	int			y;
	int			x;
	void		*ptr;
	void		*window;
}				t_mlx;

typedef struct	s_point
{
	int			y;
	int			x;
	int			z;
}				t_point;

typedef struct	s_error
{
	int			err;
}				t_error;

t_map			*handle_map(int mode);
void			print_error(void);
void			clear_map(t_map *map);

int				find_y(char *file);
int				find_x(char *file);
int				**build_arr(char *file, int y, int x, t_error *error);

void			get_point_after_rotate(t_point *point, int y,
											int x, t_map *map);
void			init_point(t_point *point, t_map *map, int y, int x);

void			map_handler(t_map *map, char *file);

void			draw_image(t_map *map, t_mlx mlx);

#endif
