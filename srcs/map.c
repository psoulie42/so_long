/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:16:58 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/22 19:09:39 by psoulie          ###   ########.fr       */
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
			check_char(data, data->map[i][j]);
			check_bounds(data, i, j);
			if (!check_p_c_e(data->map[i][j++], &player, &collectible, &exit_tile))
				p_c_e_kill(data, player, collectible, exit_tile);
		}
		i++;
	}
	if (!player || !collectible || !exit_tile)
		p_c_e_kill(data, player, collectible, exit_tile);
}

int	open_map_file(t_data *data, char *file)
{
	int		fd;
	int		i;
	char	*check;
	char	*file_ext;

	i = 0;
	file_ext = ".ber";
	check = ft_strstr(file, file_ext);
	if (!check)
		error(data, "Invalid '.ber' file\n");;
	while (check[i] && file_ext[i])
	{
		if (check[i] != file_ext[i])
			error(data, "Invalid '.ber' file\n");
		i++;
	}
	if (check[i])
		error(data, "Invalid '.ber' file\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(data, "Invalid '.ber' file\n");
	return (fd);

}

int	map_size_y(t_data *data, char *file)
{
	char	*stash;
	int		i;
	int		fd;

	fd = open_map_file(data, file);
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
	proper_exit(data, 0);
	return (0);
}

void	map_init(t_data *data, char *file)
{
	int	fd;
	int	i;
	int	**checker;

	data->col->found = 0;
	data->mapsize->y = map_size_y(data, file);
	data->map = (char **)malloc(data->mapsize->y * (sizeof(char *)));
	fd = open_map_file(data, file);
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
	player_pos(data);
	checker = init_checker(data);
	if (!path_check(data, data->player_pos->x, data->player_pos->y, &checker))
		return (error(data, "Impossible map\n"));
}
