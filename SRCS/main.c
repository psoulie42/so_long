/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:59:31 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/16 11:47:10 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main()
{
	t_data	data;

	data.mlx = mlx_init();
	data.winsize_x = 200;
	data.winsize_y = 250;
	data.window = mlx_new_window(data.mlx, data.winsize_x, data.winsize_y, "so_long");
	mlx_loop_hook(data.mlx, test(&data), &data);
}
