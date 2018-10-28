/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:46:58 by dzabrots          #+#    #+#             */
/*   Updated: 2018/10/28 16:47:00 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int		find_val(t_point e, t_point f, t_point c, t_point d)
{
	int			width;
	int			height;
	int			res;

	width = e.x - c.x;
	width *= -1;
	if (width < 2)
		width = 2;
	height = d.y - f.y;
	res = width > height ? 1000 / width : 1000 / height;
	return (res);
}

static void		size_handler(t_map *map)
{
	t_point		point_e;
	t_point		point_f;
	t_point		point_c;
	t_point		point_d;
	int			width_height[2];

	get_point_after_rotate(&point_e, 0, 0, map);
	get_point_after_rotate(&point_f, 0, map->x, map);
	get_point_after_rotate(&point_c, map->y, 0, map);
	get_point_after_rotate(&point_d, map->y, map->x, map);
	map->val = find_val(point_e, point_f, point_c, point_d);
	get_point_after_rotate(&point_e, 0, 0, map);
	get_point_after_rotate(&point_f, 0, map->x, map);
	get_point_after_rotate(&point_c, map->y, 0, map);
	get_point_after_rotate(&point_d, map->y, map->x, map);
	width_height[0] = point_e.x - point_c.x;
	width_height[0] *= -1;
	if (width_height[0] < 2)
		width_height[0] = 2;
	width_height[1] = point_d.y - point_f.y;
	map->w_x = width_height[0] + (map->border * 2);
	map->w_y = width_height[1] + (map->border * 2);
	map->val /= 3;
	get_point_after_rotate(&point_f, 0, map->x, map);
	map->indent_y = map->border - point_f.y;
}

void			map_handler(t_map *map, char *file)
{
	if ((map->y = find_y(file) - 1) <= 0)
		print_error();
	if ((map->x = find_x(file) - 1) <= 0)
		print_error();
	map->vals = build_arr(file, map->y, map->x);
	map->border = 50;
	size_handler(map);
}
