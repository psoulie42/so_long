/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:59:31 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/18 17:20:37 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	data_init(t_data *data, char *file)
{
	data->windowsize->x = 2500;
	data->windowsize->y = 1500;
	//data->window = mlx_new_window(data->mlx, data->windowsize->x,
	//		data->windowsize->y, "so_long");
	map_init(data, file);
}

int	main(int ac, char **av)
{
	t_data		data;
	int			i = 0;

	data.mlx = mlx_init();
	data.mapsize = malloc(sizeof(t_mapsize));
	data.windowsize = malloc(sizeof(t_windowsize));
	data.windowsize->y = 2500;
	if (ac != 2)
		error();
	data_init(&data, av[1]);
	while (data.map[i])
		printf("%s", data.map[i++]);
	mlx_loop(data.mlx);
}
