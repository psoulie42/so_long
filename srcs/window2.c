/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:50:55 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/22 19:29:55 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_init(t_data *data)
{
	int		i;
	int		j;
	int		x;
	void	*player;

	i = 0;
	x = 32;
	player = mlx_xpm_file_to_image(data->mlx, "srcs/sprites/Tomato.xpm", &x, &x);
	while (i < data->mapsize->y)
	{
		j = 0;
		while (j < data->mapsize->x)
		{
			if (data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->window, player, j * 32, i * 32);
				mlx_destroy_image(data->mlx, player);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	print_moves(t_data *data, int end)
{
	ft_printf("\033[1A");
	ft_printf("\033[2K");
	if (end == 0)
		ft_printf("Moves: %i\n", data->moves);
	else if (end == 1)
		ft_printf("You win! Moves: %i\n", data->moves + 1);
	else if (end == -1)
		ft_printf("You lose... Moves: %i\n", data->moves);
}
