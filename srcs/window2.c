/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:50:55 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/23 16:47:32 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_image(t_data *data, char *img)
{
	int	fd;

	if (!(fd = open(img, O_RDONLY)))
		error(data, "comment ca tu supprimes mes sprites chef?");
	close(fd);
}

void	player_init(t_data *data, char *dir)
{
	int		i;
	int		j;
	int		x;
	void	*player;
	char	*file;

	i = 0;
	x = 480;
	file = ft_strjoin(dir, "player.xpm");
	check_image(data, file);
	player = mlx_xpm_file_to_image(data->mlx, file, &x, &x);
	free(file);
	while (i < data->mapsize->y)
	{
		j = 0;
		while (j < data->mapsize->x)
		{
			if (data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->window, player, j * x, i * x);
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
