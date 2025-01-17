/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:00:28 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/16 11:47:51 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*window;
	int		winsize_x;
	int		winsize_y;
}				t_data;

int	test(t_data *data);

#endif