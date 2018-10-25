#include "../fdf.h"

t_mlx		*init_mlx(t_map *map)
{
	t_mlx *res;

	res = NULL;
	if ((res = (t_mlx *)malloc(sizeof(t_mlx *))))
	{
		res->y = map->y;
		res->x = map->x;
		res->ptr = mlx_init();
		res->window = mlx_new_window(res->ptr, res->x, res->y, "FDF");
	}
	return (res);
}

void		handler(char *file)
{
	t_map 	*map;
	t_mlx	*mlx;

	map = create_map();
	if ((map->y = find_y(file) - 1) <= 0)
		print_error();
	if ((map->x = find_x(file) - 1) <= 0)
		print_error();
	map->vals = build_arr(file, map->y, map->x);
	mlx = init_mlx(map);

	mlx_clear_window(mlx->ptr, mlx->window);
	
	int i = 0;
	int j = 0;
	while (i <= map->y)
	{
		j = 0;
		while (j <= map->x)
		{
			mlx_pixel_put(mlx->ptr, mlx->window, i, j, 0x00B0FFED);
			j++;
		}
		i++;
	}


	// log

		// printf("y: %i x: %i", map->y, map->x);
		// i = 0;
		// j = 0;
		// while (i <= map->y)
		// {
		// 	j = 0;
		// 	while (j <= map->x)
		// 	{
		// 		ft_putnbr(map->vals[i][j]);
		// 		ft_putstr(" ");
		// 		j++;
		// 	}
		// 	ft_putendl(" ");
		// 	i++;
		// }

	// end of log

}

void		usage(char *name)
{
	ft_putstr("Usage: ");
	ft_putstr(name);
	ft_putstr(" [file with map]");
	exit(0);
}

int			main(int av, char **ac)
{
	if (av != 2)
		usage(ac[0]);
	else
		handler(ac[1]);
}