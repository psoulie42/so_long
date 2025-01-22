/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:45:12 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/22 19:25:38 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_init(t_data *data)
{
	int		i;
	int		j;
	int		x;
	void	*exit;

	i = 0;
	x = 32;
	exit = mlx_xpm_file_to_image(data->mlx, "srcs/sprites/Watermelon.xpm", &x, &x);
	while (i < data->mapsize->y)
	{
		j = 0;
		while (j < data->mapsize->x)
		{
			if (data->map[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->window, exit, j * 32, i * 32);
				mlx_destroy_image(data->mlx, exit);
				return ;
			}
			j++;
		}
		i++;
	}
	if (exit)
		mlx_destroy_image(data->mlx, exit);
}

void	background_init(t_data *data)
{
	int		i;
	int		j;
	int		x;
	void	*bg;

	i = 0;
	x = 32;
	bg = mlx_xpm_file_to_image(data->mlx, "srcs/sprites/Cauliflower.xpm", &x, &x);
	while (i < data->mapsize->y)
	{
		j = 0;
		while (j < data->mapsize->x)
		{
			mlx_put_image_to_window(data->mlx, data->window, bg, j * 32, i * 32);
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->mlx, bg);
}

void	collectibles_init(t_data *data)
{
	int		i;
	int		j;
	int		x;
	void	*col;

	i = 0;
	x = 32;
	col = mlx_xpm_file_to_image(data->mlx, "srcs/sprites/Onion.xpm", &x, &x);
	while (i < data->mapsize->y)
	{
		j = 0;
		while (j < data->mapsize->x)
		{
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, col, j * 32, i * 32);
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->mlx, col);
}

void	walls_init(t_data *data)
{
	int		i;
	int		j;
	int		x;
	void	*wall;;

	i = 0;
	x = 32;
	wall = mlx_xpm_file_to_image(data->mlx, "srcs/sprites/Pumpkin.xpm", &x, &x);
	while (i < data->mapsize->y)
	{
		j = 0;
		while (j < data->mapsize->x)
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->window, wall, j * 32, i * 32);
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->mlx, wall);
}

void	window_init(t_data *data)
{
	background_init(data);
	walls_init(data);
	collectibles_init(data);
	exit_init(data);
	player_init(data);
}
