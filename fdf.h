#ifndef FDF_H
# define FDF_H

# include "libft/incl/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include "minilibx_macos/mlx.h"
# include <math.h>

typedef struct	s_map
{
	int 		x;
	int			y;
	int 		**vals;
	int			val;
	int			border;
	int			w_y;
	int			w_x;
	int			indent_y;
}				t_map;

typedef struct 	s_mlx
{
	int 		y;
	int			x;
	void		*ptr;
	void		*window;
}				t_mlx;

typedef struct 	s_point
{
	int		y;
	int		x;
	int		z;	
}				t_point;

t_map			*handle_map(int mode);
void			print_error(void);
void			clear_map(t_map *map);

int				find_y(char *file);
int				find_x(char *file);
int				**build_arr(char *file, int y, int x);

#endif