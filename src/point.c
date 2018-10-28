/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:47:15 by dzabrots          #+#    #+#             */
/*   Updated: 2018/10/28 16:47:17 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		rotate_x(t_point *point, double angle)
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

void		rotate_z(t_point *point, double angle)
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

void		get_point_after_rotate(t_point *point, int y, int x, t_map *map)
{
	if (map->val == 0)
	{
		point->y = y;
		point->x = x;
		point->z = map->vals[y][x] * 0;
		rotate_z(point, -0.5);
		rotate_x(point, -0.5);
	}
	if (map->val > 0)
	{
		point->y = y * map->val;
		point->x = x * map->val;
		point->z = map->vals[y][x] * 5;
		rotate_z(point, -0.5);
		rotate_x(point, -0.5);
	}
}

void		init_point(t_point *point, t_map *map, int y, int x)
{
	point->y = y * map->val;
	point->x = x * map->val;
	point->z = map->vals[y][x] * 5;
	rotate_z(point, -0.5);
	rotate_x(point, -0.5);
	point->y += map->indent_y;
	point->x += map->border;
}
