/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:45:12 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/23 16:47:58 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_init(t_data *data, char *dir)
{
	int		i;
	int		j;
	int		x;
	void	*exit;
	char	*file;

	i = 0;
	x = 480;
	file = ft_strjoin(dir, "exit.xpm");
	check_image(data, file);
	exit = mlx_xpm_file_to_image(data->mlx, file, &x, &x);
	free(file);
	while (i < data->mapsize->y)
	{
		j = 0;
		while (j < data->mapsize->x)
		{
			if (data->map[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->window, exit, j * x, i * x);
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

void	background_init(t_data *data, char *dir)
{
	int		i;
	int		j;
	int		x;
	void	*bg;
	char	*file;

	i = 0;
	x = 480;
	file = ft_strjoin(dir, "bg.xpm");
	check_image(data, file);
	bg = mlx_xpm_file_to_image(data->mlx, file, &x, &x);
	free(file);
	while (i < data->mapsize->y)
	{
		j = 0;
		while (j < data->mapsize->x)
		{
			mlx_put_image_to_window(data->mlx, data->window, bg, j * x, i * x);
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->mlx, bg);
}

void	collectibles_init(t_data *data, char *dir)
{
	int		i;
	int		j;
	int		x;
	void	*col;
	char	*file;

	i = 0;
	x = 480;
	file = ft_strjoin(dir, "col.xpm");
	check_image(data, file);
	col = mlx_xpm_file_to_image(data->mlx, file, &x, &x);
	free(file);
	while (i < data->mapsize->y)
	{
		j = 0;
		while (j < data->mapsize->x)
		{
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, col, j * x, i * x);
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->mlx, col);
}

void	walls_init(t_data *data, char *dir)
{
	int		i;
	int		j;
	int		x;
	void	*wall;
	char	*file;

	i = 0;
	x = 480;
	file = ft_strjoin(dir, "wall.xpm");
	check_image(data, file);
	wall = mlx_xpm_file_to_image(data->mlx, file, &x, &x);
	free(file);
	while (i < data->mapsize->y)
	{
		j = 0;
		while (j < data->mapsize->x)
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->window, wall, j * x, i * x);
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->mlx, wall);
}

void	window_init(t_data *data)
{
	char	*dir;

	if (data->type == 'v')
		dir = "srcs/sprites/vegetables/";
	else
		dir = "srcs/sprites/radiant/";
	background_init(data, dir);
	walls_init(data, dir);
	collectibles_init(data, dir);
	exit_init(data, dir);
	player_init(data, dir);
}
