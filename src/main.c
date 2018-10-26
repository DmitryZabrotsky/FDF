#include "../fdf.h"

void	rotate_x(t_point *point, double angle)
{
	double	copy_y;
	double	copy_z;
	double	rad;

	copy_y = point->y;
	copy_z = point->z;
	rad = atan2(copy_y, copy_z) + angle;
	point->y = hypot(copy_y, copy_z) * sin(rad);
	point->z = hypot(copy_y, copy_z) * cos(rad);
}

void	rotate_z(t_point *point, double angle)
{
	double	copy_y;
	double	copy_x;
	double	rad;

	copy_y = point->y;
	copy_x = point->x;
	rad = atan2(copy_y, copy_x) + angle;
	point->y = hypot(copy_y, copy_x) * sin(rad);
	point->x = hypot(copy_y, copy_x) * cos(rad);
}

int ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	draw_line(t_mlx *mlx, t_point *a, t_point *b)
{
	int		y;
	int		x;
	int		z;

	printf("a: x = %i, y = %i\n", (int)a->x, (int)a->y);
	printf("b: x = %i, y = %i\n", (int)b->x, (int)b->y);
	x = a->x;
	y = a->y;
	if (ft_abs(a->x - b->x) > ft_abs(a->y - b->y))
		z = ft_abs(a->x - b->x);
	else
		z = ft_abs(a->y - b->y) / -2;
	//int i = 10;
	while (y != b->y || x != b->x)
	{
		printf("x = %i, y = %i\n", x, y);
		printf("b: x = %i, y = %i\n", (int)b->x, (int)b->y);
		mlx_pixel_put(mlx->ptr, mlx->window, x, y, 0xff0000);
		if (z > ft_abs(a->x - b->x) * -1)
		{
			z -= ft_abs(a->y - b->y);
			x += a->x < b->x ? 1 : -1;
		}
		if (z < (int)ft_abs(a->y - b->y))
		{
			z += ft_abs(a->x - b->x);
			y += a->y < b->y ? 1 : -1;
		}
	}
}

t_mlx		*init_mlx(t_map *map)
{
	t_mlx *res;

	res = NULL;
	if ((res = (t_mlx *)malloc(sizeof(t_mlx *))))
	{
		res->y = map->y;
		res->x = map->x;
		res->ptr = mlx_init();
		res->window = mlx_new_window(res->ptr, res->x + 1000, res->y + 1000, "FDF");
	}
	return (res);
}

void		init_point(t_point *point, t_map *map, int y, int x)
{
	point->y = y * 20; // отступ между пискелями
	point->x = x * 20;
	point->z = map->vals[y][x] * 10;
	rotate_z(point, -0.5);
	rotate_x(point, -0.5);
	point->y += 250;
	point->x += 100; // отступ от края
}

void		handler(char *file)
{
	t_map 	*map;
	t_mlx	*mlx;
	t_point point_a;
	t_point point_b;

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
			init_point(&point_a, map, i, j);
			if (j != map->x)
			{
				init_point(&point_b, map, i, j + 1);
				draw_line(mlx, &point_a, &point_b);
			}
			if (i != map->y)
			{
				init_point(&point_b, map, i + 1, j);
				draw_line(mlx, &point_a, &point_b);
			}
			mlx_pixel_put(mlx->ptr, mlx->window, point_a.x, point_a.y, 0xb0ffed);
			mlx_pixel_put(mlx->ptr, mlx->window, point_b.x, point_b.y, 0xffff00);

			j++;
		}
		i++;
	}
	mlx_loop(mlx->ptr);

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