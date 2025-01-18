/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:33:42 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/18 17:44:43 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_char(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
		return ;
	else
		error();
}

void	check_bounds(t_data *data, int i, int j)
{
	if ((i == 0 || j == 0 || i == data->mapsize->y - 1 ||
			j == data->mapsize->x - 1) && data->map[i][j] != '1')
		error();
}

void	check_p_c_e(char a, int *p, int *c, int *e)
{
	if (a == 'P')
	{
		if (*p == 0)
			*p += 1;
		else
			error();
	}
	else if (a == 'C')
		*c += 1;
	else if (a == 'E')
	{
		if (*e == 0)
			*e += 1;
		else
			error();
	}
}

void	check_format(t_data *data, int i)
{
	if (data->mapsize->x != (int)ft_strlen(data->map[i]))
		error();
}
