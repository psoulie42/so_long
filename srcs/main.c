/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:59:31 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/21 16:50:27 by psoulie          ###   ########.fr       */
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
	void	*img_ptr;
	int		x = 32;
	int		y = 32;
	char 	*path = "srcs/sprites/seth/seth_front_idletest.xpm";

	map_init(data, file);
	data->windowsize->x = data->mapsize->x * 320;
	data->windowsize->y = data->mapsize->y * 320;
	data->window = mlx_new_window(data->mlx, data->windowsize->x,
		data->windowsize->y, "so_long");
	img_ptr = mlx_xpm_file_to_image(data->mlx, path, &x, &y);
	mlx_put_image_to_window(data->mlx, data->window, img_ptr, 0, 0);
}

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	if (keysym == 65307)
	{
		mlx_destroy_window(data->mlx, data->window);
		exit(EXIT_SUCCESS);
	}
	printf("Pressed key: %i\n", keysym);
	return (0);
}

int	main(int ac , char **av)
{
	t_data		data;

	if (ac != 2)
		error();
	data.mlx = mlx_init();
	data.mapsize = malloc(sizeof(t_mapsize));
	data.windowsize = malloc(sizeof(t_windowsize));
	data.col = malloc(sizeof(t_collectibles));
	data_init(&data, av[1]);
	mlx_hook(data.window, 02, 1L<<0, on_keypress, &data);
	mlx_loop(data.mlx);
}
