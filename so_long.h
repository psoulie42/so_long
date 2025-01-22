/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:00:28 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/22 18:20:51 by psoulie          ###   ########.fr       */
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
typedef struct s_player_pos t_player_pos;

typedef struct s_data
{
	void			*mlx;
	void			*window;
	char			**map;
	int				moves;
	t_windowsize	*windowsize;
	t_mapsize		*mapsize;
	t_collectibles	*col;
	t_player_pos	*player_pos;
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

typedef struct s_player_pos
{
	int		x;
	int		y;
	t_data	data;
}				t_player_pos;

int		**init_checker(t_data *data);
int		*test(t_data *data);
int		find_exit(t_data *data, int x, int y, int ***checked);
int		open_map_file(t_data *data, char *map);
int		map_size_y(t_data *data,char *file);
int		check_p_c_e(char a, int *p, int *c, int *e);
int		path_check(t_data *data, int x, int y, int ***checked);
int		player_goes_up(t_data *data);
int		player_goes_left(t_data *data);
int		player_goes_down(t_data *data);
int		player_goes_right(t_data *data);
int		proper_exit(t_data *data, int status);
char	*ft_strstr(const char *hst, const char *ndl);
void	player_pos(t_data *data);
void	check_char(t_data *data, char c);
void	check_bounds(t_data *data, int i, int j);
void	check_format(t_data *data, int i);
void	map_init(t_data *data, char *map);
void	error(t_data *data, char *str);
void	data_init(t_data *data, char *file);
void	image(t_data *data, int posx, int posy, void *img_ptr);
void	window_init(t_data *data);
void	walls_init(t_data *data);
void	collectibles_init(t_data *data);
void	background_init(t_data *data);
void	exit_init(t_data *data);
void	player_init(t_data *data);
void	player_move(t_data *data, int key);
void	print_moves(t_data *data, int end);
void	p_c_e_kill(t_data *data, int player, int col, int ex);
void	free_checker(t_data *data, int **tab);

#endif