#include "../fdf.h"

static int ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

static void	draw_line(t_mlx *mlx, t_point *a, t_point *b)
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

void		draw_image(t_map *map, t_mlx mlx)
{
	t_point	point_a;
	t_point	point_b;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
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
}