/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:16:58 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/20 17:50:11 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	collectibles(t_data *data)
{
	int		nb;
	int		i;
	int		j;
	char	**map;

	nb = 0;
	map = data->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
}

void	parse_map(t_data *data)
{
	int		i;
	int		j;
	int		player;
	int		collectible;
	int		exit_tile;

	player = 0;
	collectible = 0;
	exit_tile = 0;
	i = 0;
	while (i < data->mapsize->y)
	{
		check_format(data, i);
		j = 0;
		while (j < data->mapsize->x)
		{
			check_char(data->map[i][j]);
			check_bounds(data, i, j);
			check_p_c_e(data->map[i][j], &player, &collectible, &exit_tile);
			j++;
		}
		i++;
	}
	if (!player || !collectible || !exit_tile)
		error();
}

int	open_map_file(char *file)
{
	int		fd;
	int		i;
	char	*check;
	char	*file_ext;

	i = 0;
	file_ext = ".ber";
	check = ft_strstr(file, file_ext);
	if (!check)
		error();
	while (check[i] && file_ext[i])
	{
		if (check[i] != file_ext[i])
			error();
		i++;
	}
	if (check[i])
		error();
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error();
	return (fd);

}

int	map_size_y(char *file)
{
	char	*stash;
	int		i;
	int		fd;

	fd = open_map_file(file);
	stash = get_next_line(fd);
	i = 1;
	while (stash)
	{
		free(stash);
		stash = get_next_line(fd);
		i++;
	}
	free(stash);
	close(fd);
	return (i - 1);
}

void	map_init(t_data *data, char *file)
{
	int	fd;
	int	i;
	int	**checker;

	data->col->found = 0;
	data->mapsize->y = map_size_y(file);
	data->map = (char **)malloc(data->mapsize->y * (sizeof(char *)));
	fd = open_map_file(file);
	i = 0;
	while (1)
	{
		data->map[i] = get_next_line(fd);
		if (!data->map[i])
			break ;
		i++;
	}
	data->map[i] = NULL;
	data->mapsize->x = ft_strlen(data->map[0]) - 1;
	data->col->nb = collectibles(data);
	parse_map(data);
	checker = init_checker(data);
	if (!path_check(data, player_pos_x(data), player_pos_y(data), &checker))
		error();
}
