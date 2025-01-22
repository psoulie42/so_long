/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:33:42 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/22 17:16:17 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_pos->x = j;
				data->player_pos->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	return (error(data, "No starting point on map\n"));
}

void	check_char(t_data *data, char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
		return ;
	else
		error(data, "Invalid character on map\n");
}

void	check_bounds(t_data *data, int i, int j)
{
	if ((i == 0 || j == 0 || i == data->mapsize->y - 1 ||
			j == data->mapsize->x - 1) && data->map[i][j] != '1')
		error(data, "Open map\n");
}

int	check_p_c_e(char a, int *p, int *c, int *e)
{
	if (a == 'P')
	{
		*p += 1;
		if (*p == 1)
			return (1);
		else
			return (0);
	}
	else if (a == 'C')
		*c += 1;
	else if (a == 'E')
	{
		*e += 1;
		if (*e == 1)
			return (1);
		else
			return (0);
	}
	return (1);
}

void	check_format(t_data *data, int i)
{
	if (data->mapsize->x != (int)ft_strlen(data->map[i]) - 1)
		error(data, "Invalid format\n");
}
