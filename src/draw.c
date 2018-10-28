/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:46:42 by dzabrots          #+#    #+#             */
/*   Updated: 2018/10/28 16:46:44 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	ft_abs(int num)
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
	int		i_j[2];

	i_j[0] = 0;
	while (i_j[0] <= map->y)
	{
		i_j[1] = 0;
		while (i_j[1] <= map->x)
		{
			init_point(&point_a, map, i_j[0], i_j[1]);
			if (i_j[1] != map->x)
			{
				init_point(&point_b, map, i_j[0], i_j[1] + 1);
				draw_line(&mlx, &point_a, &point_b);
			}
			if (i_j[0] != map->y)
			{
				init_point(&point_b, map, i_j[0] + 1, i_j[1]);
				draw_line(&mlx, &point_a, &point_b);
			}
			i_j[1]++;
		}
		i_j[0]++;
	}
}
