/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_feasability.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:42:59 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/21 16:17:51 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	**init_checker(t_data *data)
{
	int	i;
	int	j;
	int	**tab;

	i = 0;
	tab = (int **)malloc((data->mapsize->y) * (sizeof(int *)));
	while (i < data->mapsize->y)
	{
		tab[i] = (int *)malloc((data->mapsize->x) * sizeof(int));
		j = 0;
		while (j < data->mapsize->x)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

int	find_exit(t_data *data, int x, int y, int ***checked)
{
	int	exit;

	exit = 0;
	if ((*checked)[y][x] || data->map[y][x] == '1')
		return (0);
	(*checked)[y][x] = 1;
	if (data->map[y][x] == 'E')
		return (1);
	if (x > 1)
		exit += find_exit(data, x - 1, y, checked);
	if (x < data->mapsize->x)
		exit += find_exit(data, x + 1, y, checked);
	if (y > 1)
		exit += find_exit(data, x, y - 1, checked);
	if (y < data->mapsize->y)
		exit += find_exit(data, x, y + 1, checked);
	if (exit)
		return (1);
	else
		return (0);
}

int	path_check(t_data *data, int x, int y, int ***checked)
{
	char	**map;

	map = data->map;
	if ((*checked)[y][x] == 1)
		return (0);
	(*checked)[y][x] = 1;
	if (map[y][x] == '1' || map[y][x] == 'E')
		return (0);
	if (map[y][x] == 'C')
		data->col->found++;
	if (x > 1)
		path_check(data, x - 1, y, checked);
	if (x < data->mapsize->x)
		path_check(data, x + 1, y, checked);
	if (y > 1)
		path_check(data, x, y - 1, checked);
	if (y < data->mapsize->y)
		path_check(data, x, y + 1, checked);
	if (map[y][x] != 'P')
		return (data->col->found);
	else if (data->col->found == data->col->nb)
		return (*checked = init_checker(data), find_exit(data, x, y, checked));
	else
		return (error(), -1);
}
