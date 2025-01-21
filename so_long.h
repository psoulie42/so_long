/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:00:28 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/21 16:26:52 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "srcs/utils/get_next_line/get_next_line.h"
# include "srcs/utils/ft_printf/ft_printf.h"
# include <X11/ap_keysym.h>

typedef struct s_windowsize t_windowsize;
typedef struct s_mapsize t_mapsize;
typedef struct s_collectibles t_collectibles;

typedef struct s_data
{
	void			*mlx;
	void			*window;
	char			**map;
	t_windowsize	*windowsize;
	t_mapsize		*mapsize;
	t_collectibles	*col;
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

typedef struct s_collectibles
{
	int		nb;
	int		found;
	t_data	*data;
}				t_collectibles;

int		**init_checker(t_data *data);
int		*test(t_data *data);
int		find_exit(t_data *data, int x, int y, int ***checked);
int		open_map_file(char *map);
int		map_size_y(char *file);
int		path_check(t_data *data, int x, int y, int ***checked);
int		player_pos_x(t_data *data);
int		player_pos_y(t_data *data);
char	*ft_strstr(const char *hst, const char *ndl);
void	check_char(char c);
void	check_bounds(t_data *data, int i, int j);
void	check_p_c_e(char a, int *p, int *c, int *e);
void	check_format(t_data *data, int i);
void	map_init(t_data *data, char *map);
void	error(void);
void	data_init(t_data *data, char *file);
void	image(t_data *data, int posx, int posy, void *img_ptr);

#endif