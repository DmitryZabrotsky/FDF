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

t_map			*create_map(void);
void			print_error(void);

int				find_y(char *file);
int				find_x(char *file);
int				**build_arr(char *file, int y, int x);

#endif