#ifndef FDF_H
# define FDF_H

# include "libft/incl/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include "minilibx_macos/mlx.h"

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

t_map			*create_map(void);
void			print_error(void);

int				find_y(char *file);
int				find_x(char *file);
int				**build_arr(char *file, int y, int x);

#endif