/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:47:23 by dzabrots          #+#    #+#             */
/*   Updated: 2018/10/28 16:47:26 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print_error(void)
{
	ft_putstr(RED);
	ft_putendl("Error!");
	ft_putstr(RESET);
	exit(0);
}

t_map	*handle_map(int mode)
{
	static t_map *map = NULL;

	if (mode == 1)
	{
		if ((map = (t_map *)malloc(sizeof(t_map))))
		{
			map->x = 0;
			map->y = 0;
			map->vals = NULL;
			map->val = 0;
			map->border = 0;
			map->w_y = 0;
			map->w_x = 0;
			map->indent_y = 0;
		}
	}
	if (mode == 0)
		clear_map(map);
	return (map);
}

void	clear_map(t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->y)
	{
		free(map->vals[i]);
		i++;
	}
	free(map->vals);
	free(map);
}
