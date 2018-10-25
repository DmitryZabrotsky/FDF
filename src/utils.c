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
	}
	return(map);
}