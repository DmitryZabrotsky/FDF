#include "../fdf.h"

static int			find_val(t_point e, t_point f, t_point c, t_point d)
{
	int		width;
	int		height;
	int		res;

	width = e.x - c.x;
	width *= -1;
	if (width < 2)
		width = 2;
	height = d.y - f.y;
printf("width: %i height: %i\n", width, height);
	res = width > height ? 1000 / width : 1000 / height;
	return (res);
}

static void		size_handler(t_map *map)
{
	t_point	point_e;
	t_point	point_f;
	t_point	point_c;
	t_point	point_d;
	int		width_height[2];

	get_point_after_rotate(&point_e, 0, 0, map);
	get_point_after_rotate(&point_f, 0, map->x, map);
	get_point_after_rotate(&point_c, map->y, 0, map);
	get_point_after_rotate(&point_d, map->y, map->x, map);
printf("e: y %i x %i z %i\n", point_e.y, point_e.x, point_e.z);
printf("f: y %i x %i z %i\n", point_f.y, point_f.x, point_f.z);
printf("c: y %i x %i z %i\n", point_c.y, point_c.x, point_c.z);
printf("d: y %i x %i z %i\n", point_d.y, point_d.x, point_d.z);
	map->val = find_val(point_e, point_f, point_c, point_d);
printf("val: %i\n", map->val);

	get_point_after_rotate(&point_e, 0, 0, map);
	get_point_after_rotate(&point_f, 0, map->x, map);
	get_point_after_rotate(&point_c, map->y, 0, map);
	get_point_after_rotate(&point_d, map->y, map->x, map);

printf("e: y %i x %i z %i\n", point_e.y, point_e.x, point_e.z);
printf("f: y %i x %i z %i\n", point_f.y, point_f.x, point_f.z);
printf("c: y %i x %i z %i\n", point_c.y, point_c.x, point_c.z);
printf("d: y %i x %i z %i\n", point_d.y, point_d.x, point_d.z);

	width_height[0] = point_e.x - point_c.x;
	width_height[0] *= -1;
	if (width_height[0] < 2)
		width_height[0] = 2;
	width_height[1] = point_d.y - point_f.y;
printf("width: %i height: %i\n", width_height[0], width_height[1]);

	map->w_x = width_height[0] + (map->border * 2);
	map->w_y = width_height[1] + (map->border * 2);
printf("map->width: %i map->height: %i\n", map->w_x, map->w_y);

	map->val /= 3;
printf("val: %i \n", map->val);

	get_point_after_rotate(&point_f, 0, map->x, map);
	map->indent_y = map->border - point_f.y;
}

void		map_handler(t_map *map, char *file)
{
	if ((map->y = find_y(file) - 1) <= 0)
		print_error();
	if ((map->x = find_x(file) - 1) <= 0)
		print_error();
	map->vals = build_arr(file, map->y, map->x);
	map->border = 50;
	size_handler(map);
}