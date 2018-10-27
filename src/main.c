#include "../fdf.h"

int		key_hooker(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (key == 53)
	{
		mlx_destroy_window(mlx->ptr, mlx->window);
		// CLEAR MEMORY();
		exit(0);
		return (1);
	}
	return (1);
}

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

	x = a->x;
	y = a->y;
	if (ft_abs(a->x - b->x) > ft_abs(a->y - b->y))
		z = ft_abs(a->x - b->x);
	else
		z = ft_abs(a->y - b->y) / -2;
	while (y != b->y || x != b->x)
	{
		mlx_pixel_put(mlx->ptr, mlx->window, x, y, 0xb0ffed);
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

void		init_mlx(t_map *map, t_mlx *mlx)
{
	mlx->y = map->y;
	mlx->x = map->x;
	mlx->ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->ptr, map->w_y, map->w_y, "FDF");
}

void		get_point_after_rotate(t_point *point, int y, int x, t_map *map)
{
	if (map->val == 0)
	{
		point->y = y; // отступ между пискелями
		point->x = x;
		point->z = map->vals[y][x] * 0;
		rotate_z(point, -0.5);
		rotate_x(point, -0.5);
	}
	if (map->val > 0)
	{
		point->y = y * map->val; // отступ между пискелями
		point->x = x * map->val;
		point->z = map->vals[y][x] * 5;
		rotate_z(point, -0.5);
		rotate_x(point, -0.5);
	}
}

void		init_point(t_point *point, t_map *map, int y, int x)
{
	point->y = y * map->val; // отступ между пискелями
	point->x = x * map->val;
	point->z = map->vals[y][x] * 5;
	rotate_z(point, -0.5);
	rotate_x(point, -0.5);
	point->y += map->indent_y;
	point->x += map->border; // отступ от края

	printf("point: y %i x %i z %i\n", point->y, point->x, point->z);
}

void		handler(char *file)
{
	t_map 	*map;
	t_mlx	mlx;
	t_point point_a;
	t_point point_b;

	map = create_map();
	if ((map->y = find_y(file) - 1) <= 0)
		print_error();
	if ((map->x = find_x(file) - 1) <= 0)
		print_error();
	map->vals = build_arr(file, map->y, map->x);

map->border = 50;

	t_point point_e;
	t_point point_f;
	t_point point_c;
	t_point point_d;

	get_point_after_rotate(&point_e, 0, 0, map);
	get_point_after_rotate(&point_f, 0, map->x, map);
	get_point_after_rotate(&point_c, map->y, 0, map);
	get_point_after_rotate(&point_d, map->y, map->x, map);

	printf("e: y %i x %i z %i\n", point_e.y, point_e.x, point_e.z);
	printf("f: y %i x %i z %i\n", point_f.y, point_f.x, point_f.z);
	printf("c: y %i x %i z %i\n", point_c.y, point_c.x, point_c.z);
	printf("d: y %i x %i z %i\n", point_d.y, point_d.x, point_d.z);

	int width = point_e.x - point_c.x;
	width *= -1;
	if (width < 2)
		width = 2;
	int height = point_d.y - point_f.y;
	printf("width: %i height: %i\n", width, height);

map->val = width > height ? 1000 / width : 1000 / height;
	printf("val: %i\n", map->val);

	get_point_after_rotate(&point_e, 0, 0, map);
	get_point_after_rotate(&point_f, 0, map->x, map);
	get_point_after_rotate(&point_c, map->y, 0, map);
	get_point_after_rotate(&point_d, map->y, map->x, map);

	printf("e: y %i x %i z %i\n", point_e.y, point_e.x, point_e.z);
	printf("f: y %i x %i z %i\n", point_f.y, point_f.x, point_f.z);
	printf("c: y %i x %i z %i\n", point_c.y, point_c.x, point_c.z);
	printf("d: y %i x %i z %i\n", point_d.y, point_d.x, point_d.z);

	width = point_e.x - point_c.x;
	width *= -1;
	if (width < 2)
		width = 2;
	height = point_d.y - point_f.y;
	printf("width: %i height: %i\n", width, height);

map->w_x = width + (map->border * 2);
map->w_y = height + (map->border * 2);
	printf("map->width: %i map->height: %i\n", map->w_x, map->w_y);

map->val /= 3;
	printf("val: %i \n", map->val);

get_point_after_rotate(&point_f, 0, map->x, map);
map->indent_y = map->border - point_f.y;

	init_mlx(map, &mlx);
	mlx_clear_window(mlx.ptr, mlx.window);
	
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
				draw_line(&mlx, &point_a, &point_b);
			}
			if (i != map->y)
			{
				init_point(&point_b, map, i + 1, j);
				draw_line(&mlx, &point_a, &point_b);
			}
			// mlx_pixel_put(mlx->ptr, mlx->window, point_a.x, point_a.y, 0xb0ffed);
			// mlx_pixel_put(mlx->ptr, mlx->window, point_b.x, point_b.y, 0xffff00);

			j++;
		}
		i++;
	}
	mlx_key_hook(mlx.window, key_hooker, &mlx);
	mlx_loop(mlx.ptr);

	// log

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