/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_kill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:26:44 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/23 13:56:24 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_checker(t_data *data, int **tab)
{
	int	i;

	i = 0;
	while (i < data->mapsize->y)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	error(t_data *data, char *str)
{
	ft_printf("Error: %s", str);
	proper_exit(data, -1);
}

void	p_c_e_kill(t_data *data, int player, int col, int ex)
{
	if (!player)
		error(data, "No starting point 'P' on map\n");
	if (!col)
		error(data, "No collectible 'C' on map\n");
	if (!ex)
		error(data, "No exit tile 'E' on map\n");
	if (player > 1)
		error(data, "More than 1 starting point on map\n");
	if (ex > 1)
		error(data, "More than 1 exit tile on map\n");
}

int	proper_exit(t_data *data, int status)
{
	if (data)
	{
		if (data->map)
			free_map(data);
		if (data->col)
			free(data->col);
		if (data->mapsize)
			free(data->mapsize);
		if (data->player_pos)
			free(data->player_pos);
		if (data->windowsize)
			free(data->windowsize);
		if (data->window)
			mlx_destroy_window(data->mlx, data->window);
		if (data->mlx)
		{
			mlx_destroy_display(data->mlx);
			free(data->mlx);
		}
	}
	exit(status);
	return (0);
}
