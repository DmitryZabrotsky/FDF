#include "../fdf.h"

int			*get_numbers(char *s, int x)
{
	int		*res;
	char	**arr;
	int		i;

	if ((res = (int *)malloc(sizeof(int) * x)))
	{
		i = 0;
		arr = ft_strsplit(s, ' ');
		while(arr[i] && i <= x)
		{
			res[i] = ft_atoi(arr[i]);
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	return (res);
}

int			**build_arr(char *file, int y, int x)
{
	char 	*s;
	int		fd;
	int		**res;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if ((res = (int **)malloc(sizeof(int *) * y + 1)))
	{
		while(get_next_line(fd, &s) > 0 && i <= y)
		{
			res[i] = get_numbers(s, x);
			i++;
		}
		free(s);
	}
	return (res);
}

int			find_x(char *file)
{
	char	**arr;
	char	*s;
	int		fd;
	int		x;

	x = 0;
	fd = open(file, O_RDONLY);
	get_next_line(fd, &s);
	arr = ft_strsplit(s, ' ');
	while (arr[x])
	{
		free(arr[x]);
		x++;
	}
	free(arr);
	free(s);
	return (x);
}

int			find_y(char *file)
{
	char	*s;
	int		fd;
	int		y;

	y = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &s) > 0)
	{
		y++;
		free(s);
	}
	close(fd);
	return (y);
}

void		handler(char *file)
{
	t_map 	*map;

	map = create_map();
	map->y = find_y(file) - 1;
	map->x = find_x(file) - 1;
	map->vals = build_arr(file, map->y, map->x);
	printf("y: %i x: %i", map->y, map->x);

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