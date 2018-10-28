#include "../fdf.h"

int		key_hooker(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (key == 53)
	{
		mlx_destroy_window(mlx->ptr, mlx->window);
		handle_map(0);
		exit(0);
	}
	return (1);
}

static void		init_mlx(t_map *map, t_mlx *mlx)
{
	mlx->y = map->y;
	mlx->x = map->x;
	mlx->ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->ptr, map->w_y, map->w_y, "FDF");
}

void		handler(char *file)
{
	t_map 	*map;
	t_mlx	mlx;

	map = handle_map(1);
	map_handler(map, file);

// printf("y: %i x: %i", map->y, map->x);
// int i = 0;
// int j = 0;
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

	init_mlx(map, &mlx);
	mlx_clear_window(mlx.ptr, mlx.window);
	draw_image(map, mlx);
	mlx_key_hook(mlx.window, key_hooker, &mlx);
	mlx_loop(mlx.ptr);

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