/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:11:31 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/22 17:22:27 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_goes_right(t_data *data)
{
	int		x;
	int		y;
	int		end;
	char	**map;

	end = 0;
	map = data->map;
	x = data->player_pos->x;
	y = data->player_pos->y;
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C' ||
			(map[y][x + 1] == 'E' && data->col->found == data->col->nb))
	{
		if (map[y][x + 1] == 'C')
			data->col->found++;
		else if (map[y][x + 1] == 'E')
			end = 1;
		map[y][x] = '0';
		map[y][x + 1] = 'P';
		window_init(data);
		if (end)
			return (print_moves(data, 1), proper_exit(data, 0), 1);
		return (1);
	}
	return (0);
}

int	player_goes_down(t_data *data)
{
	int		x;
	int		y;
	int		end;
	char	**map;

	end = 0;
	map = data->map;
	x = data->player_pos->x;
	y = data->player_pos->y;
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C' ||
			(map[y + 1][x] == 'E' && data->col->found == data->col->nb))
	{
		if (map[y + 1][x] == 'C')
			data->col->found++;
		else if (map[y + 1][x] == 'E')
			end = 1;
		map[y][x] = '0';
		map[y + 1][x] = 'P';
		window_init(data);
		if (end)
			return (print_moves(data, 1), proper_exit(data, 0), 1);
		return (1);
	}
	return (0);
}

int	player_goes_left(t_data *data)
{
	int		x;
	int		y;
	int		end;
	char	**map;

	end = 0;
	map = data->map;
	x = data->player_pos->x;
	y = data->player_pos->y;
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C' ||
			(map[y][x - 1] == 'E' && data->col->found == data->col->nb))
	{
		if (map[y][x - 1] == 'C')
			data->col->found++;
		else if (map[y][x - 1] == 'E')
			end = 1;
		map[y][x] = '0';
		map[y][x - 1] = 'P';
		window_init(data);
		if (end)
			return (print_moves(data, 1), proper_exit(data, 0), 1);
		return (1);
	}
	return (0);
}

int	player_goes_up(t_data *data)
{
	int		x;
	int		y;
	int		end;
	char	**map;

	end = 0;
	map = data->map;
	x = data->player_pos->x;
	y = data->player_pos->y;
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C' ||
			(map[y - 1][x] == 'E' && data->col->found == data->col->nb))
	{
		if (map[y - 1][x] == 'C')
			data->col->found++;
		else if (map[y - 1][x] == 'E')
			end = 1;
		map[y][x] = '0';
		map[y - 1][x] = 'P';
		window_init(data);
		if (end)
			return (print_moves(data, 1), proper_exit(data, 0), 1);
		return (1);
	}
	return (0);
}

void	player_move(t_data *data, int key)
{
	player_pos(data);
	if (key == 119)
		data->moves += player_goes_up(data);
	else if (key == 97)
		data->moves += player_goes_left(data);
	else if (key == 115)
		data->moves += player_goes_down(data);
	else if (key == 100)
		data->moves += player_goes_right(data);
	print_moves(data, 0);
}
