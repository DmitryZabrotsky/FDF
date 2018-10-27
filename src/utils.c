#include "../fdf.h"

void		print_error(void)
{
	ft_putstr(RED);
	ft_putendl("Error!");
	ft_putstr(RESET);
	exit(0);
}

t_map	*create_map(void)
{
	t_map *map;

	if ((map = (t_map *)malloc(sizeof(t_map))))
	{
		map->x = 0;
		map->y = 0;
		map->vals = NULL;
		map->val = 0;
		map->border = 0;
		map->w_y = 0;
		map->w_x = 0;
		map->indent_y = 0;
	}
	return(map);
}