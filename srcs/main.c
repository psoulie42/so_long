/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:59:31 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/23 17:01:52 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	data_init(t_data *data, char *file)
{
	map_init(data, file);
	data->col->found = 0;
	data->moves = 0;
	data->windowsize->x = data->mapsize->x * 480;
	data->windowsize->y = data->mapsize->y * 480;
	data->window = mlx_new_window(data->mlx, data->windowsize->x,
		data->windowsize->y, "so_long");
	window_init(data);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 119 || keysym == 97 || keysym == 115 || keysym == 100)
		player_move(data, keysym);
	if (keysym == 65307)
		proper_exit(data, 1);
	return (0);
}

int	main(int ac , char **av)
{
	t_data	data;

	data.type = 'v';
	data.mlx = mlx_init();
	data.mapsize = malloc(sizeof(t_mapsize));
	data.windowsize = malloc(sizeof(t_windowsize));
	data.col = malloc(sizeof(t_collectibles));
	data.player_pos = malloc(sizeof(t_player_pos));
	data.map = NULL;
	data.window = NULL;
	if (ac != 2)
		error(&data, "1 map required as argument\n");
	data_init(&data, av[1]);
	mlx_hook(data.window, 02, 1L<<0, on_keypress, &data);
	mlx_hook(data.window, 17, 0, proper_exit, &data);
	mlx_loop(data.mlx);
}
