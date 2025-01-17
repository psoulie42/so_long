/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:16:58 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/17 19:08:42 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	open_map_file(char *file)
{
	int		fd;
	//char	*check;

	/* check = ft_strnstr(file, ".ber", 4);
	if (!check || check++)
		return (error(), 0); */
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error(), 0);
	return (fd);

}

int	map_size_y(char *file)
{
	char	*stash;
	int		i;
	int		fd;

	fd = open_map_file(file);
	stash = get_next_line(fd);
	i = 1;
	while (stash)
	{
		free(stash);
		stash = get_next_line(fd);
		i++;
	}
	free(stash);
	return (i);
}

void	map_init(t_data *data, char *file)
{
	int		fd;
	int		i;
	char	**map;

	data->mapsize->y = 0;
	fd = open_map_file(file);
	data->mapsize->y = map_size_y(file);
	close(fd);
	map = (char **)malloc(data->mapsize->y * (sizeof(char *)));
	fd = open_map_file(file);
	i = 0;
	while (1)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	map[i] = NULL;
}
