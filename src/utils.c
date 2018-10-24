#include "../fdf.h"

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