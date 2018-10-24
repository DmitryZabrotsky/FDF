#ifndef FDF_H
# define FDF_H

# include "libft/incl/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_map
{
	int 		x;
	int			y;
	int 		**vals;
}				t_map;

t_map	*create_map(void);

#endif