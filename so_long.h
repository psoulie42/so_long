/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:00:28 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/18 17:45:12 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "srcs/utils/get_next_line/get_next_line.h"
# include "srcs/utils/ft_printf/ft_printf.h"

typedef struct s_windowsize t_windowsize;
typedef struct s_mapsize t_mapsize;

typedef struct s_data
{
	void			*mlx;
	void			*window;
	char			**map;
	t_windowsize	*windowsize;
	t_mapsize		*mapsize;
}				t_data;

typedef struct s_windowsize
{
	int		x;
	int		y;
	t_data	*data;
}				t_windowsize;

typedef struct s_mapsize
{
	int		x;
	int		y;
	t_data	*data;
}				t_mapsize;

int		*test(t_data *data);
int		open_map_file(char *map);
int		map_size_y(char *file);
char	*ft_strstr(const char *hst, const char *ndl);
void	check_char(char c);
void	check_bounds(t_data *data, int i, int j);
void	check_p_c_e(char a, int *p, int *c, int *e);
void	check_format(t_data *data, int i);
void	map_init(t_data *data, char *map);
void	error(void);
void	data_init(t_data *data, char *file);

#endif